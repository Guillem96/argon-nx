#include "gfx/gfx.h"
#include "gfx/di.h"

#include "gfx/lvgl_adapter.h"
#include "libs/lvgl/lvgl.h"
#include "minerva/minerva.h"
#include "utils/touch.h"
#include "utils/util.h"
#include "utils/fs_utils.h"

#include "core/custom-gui.h"

#include "mem/heap.h"

static touch_event_t touchpad;
static bool first_print = false;

void display_flush(lv_disp_drv_t *disp,
                   const lv_area_t *area,
                   lv_color_t *color_p)
{
    gfx_set_rect_land_pitch(g_gfx_ctxt.fb, (u32 *)color_p,
                            area->x1,
                            area->y1,
                            area->x2, area->y2);

    if (!first_print)
    {
        first_print = true;
        display_backlight_brightness(100, 1000);
        display_init_framebuffer();
    }

    lv_disp_flush_ready(disp);
}

bool handle_touch(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    touch_poll(&touchpad);

    if (touchpad.fingers >= 2)
		take_screenshot();

    switch (touchpad.type & STMFTS_MASK_EVENT_ID)
    {
    case STMFTS_EV_MULTI_TOUCH_ENTER:
    case STMFTS_EV_MULTI_TOUCH_MOTION:
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touchpad.x;
        data->point.y = touchpad.y;

        break;
    case STMFTS_EV_MULTI_TOUCH_LEAVE:
        data->state = LV_INDEV_STATE_REL;
        data->point.x = touchpad.x;
        data->point.y = touchpad.y;
        break;
    case STMFTS_EV_NO_EVENT:
    default:
        if (touchpad.touch)
        {
            data->state = LV_INDEV_STATE_PR;
        }
        else
        {
            data->point.x = touchpad.x;
            data->point.y = touchpad.y;
            data->state = LV_INDEV_STATE_REL;
            //return true;
        }
        break;
    }

    return false; /*Return `false` because we are not buffering and no more data to read*/
}

void lvgl_adapter_init(argon_ctxt_t *argon_ctxt)
{
    lv_init();

    static lv_disp_buf_t disp_buf;
    lv_disp_buf_init(&disp_buf,
                     argon_ctxt->vdb,
                     NULL,
                     LV_HOR_RES_MAX * LV_VER_RES_MAX);

    // Initialize framebuffer drawing functions.
    lv_disp_drv_t disp_drv;            /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);       /*Basic initialization*/
    disp_drv.flush_cb = display_flush; /*Set your driver function*/
    disp_drv.buffer = &disp_buf;       /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);   /*Finally register the driver*/

    // Touch support
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = handle_touch;
    lv_indev_drv_register(&indev_drv);
    touchpad.touch = false;

    lv_task_create(minerva_periodic_training,
                   500,
                   LV_TASK_PRIO_HIGHEST,
                   argon_ctxt->mtc_conf);

    lv_theme_t *th = lv_theme_argon_init(10, NULL);
    lv_theme_set_current(th);
}

lv_img_dsc_t *bmp_to_lvimg_obj(const char *path)
{
	u8 *bitmap = sd_file_read((char*)path);
	if (!bitmap) 
    {
        gfx_printf("Not found\n");
        return NULL;
    }

	struct _bmp_data
	{
		u32 size;
		u32 size_x;
		u32 size_y;
		u32 offset;
	};

	struct _bmp_data bmpData;

	// Get values manually to avoid unaligned access.
	bmpData.size = bitmap[2] | bitmap[3] << 8 |
		bitmap[4] << 16 | bitmap[5] << 24;
	bmpData.offset = bitmap[10] | bitmap[11] << 8 |
		bitmap[12] << 16 | bitmap[13] << 24;
	bmpData.size_x = bitmap[18] | bitmap[19] << 8 |
		bitmap[20] << 16 | bitmap[21] << 24;
	bmpData.size_y = bitmap[22] | bitmap[23] << 8 |
		bitmap[24] << 16 | bitmap[25] << 24;
	// Sanity check.
	if (bitmap[0] == 'B' &&
		bitmap[1] == 'M' &&
		bitmap[28] == 32) // Only 32 bit BMPs allowed.
	{
		// Check if non-default Bottom-Top.
		bool flipped = false;
		if (bmpData.size_y & 0x80000000)
		{
			bmpData.size_y = ~(bmpData.size_y) + 1;
			flipped = true;
		}

		lv_img_dsc_t *img_desc = (lv_img_dsc_t *)bitmap;
		u32 offset_copy = ALIGN((u32)bitmap + sizeof(lv_img_dsc_t), 0x10);
	
		img_desc->header.always_zero = 0;
		img_desc->header.w = bmpData.size_x;
		img_desc->header.h = bmpData.size_y;
		img_desc->header.cf = (bitmap[28] == 32) ? LV_IMG_CF_TRUE_COLOR_ALPHA : LV_IMG_CF_TRUE_COLOR;
		img_desc->data_size = bmpData.size - bmpData.offset;
		img_desc->data = (u8 *)offset_copy;

		u32 *tmp = malloc(bmpData.size);
		u32 *tmp2 = (u32 *)offset_copy;

		// Copy the unaligned data to an aligned buffer.
		memcpy((u8 *)tmp, bitmap + bmpData.offset, img_desc->data_size);
		u32 j = 0;

		if (!flipped)
		{
			for (u32 y = 0; y < bmpData.size_y; y++)
			{
				for (u32 x = 0; x < bmpData.size_x; x++)
					tmp2[j++] = tmp[(bmpData.size_y - 1 - y ) * bmpData.size_x + x];
			}
		}
		else
		{
			for (u32 y = 0; y < bmpData.size_y; y++)
			{
				for (u32 x = 0; x < bmpData.size_x; x++)
					tmp2[j++] = tmp[y * bmpData.size_x + x];
			}
		}
		
		free(tmp);
	}
	else
	{
		free(bitmap);
        gfx_printf("Failed sanitize\n");
		return NULL;
	}
	
	return (lv_img_dsc_t *)bitmap;
}