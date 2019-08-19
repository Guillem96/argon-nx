#include "gfx/gfx.h"
#include "gfx/di.h"

#include "gfx/lvgl_adapter.h"
#include "libs/lvgl/lvgl.h"
#include "minerva/minerva.h"
#include "utils/touch.h"
#include "utils/util.h"

static bool first_print = false;

void display_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    // gfx_set_rect_land_pitch(g_gfx_ctxt.fb, (u32*)color_p, 
    //                         area->x1, 
    //                         area->y1,
    //                         area->x2, area->y2);
    u32 x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            g_gfx_ctxt.fb[x * g_gfx_ctxt.stride + y] = (*color_p).full;
            color_p++;
        }
    }
    if (!first_print) {
        first_print = true;
        display_backlight_brightness(100, 1000);
        display_init_framebuffer();
    }

    lv_disp_flush_ready(disp); /* Indicate you are ready with the flushing*/
}

void btn_event_cb(lv_obj_t *btn, lv_event_t event)
{

    if (event == LV_EVENT_CLICKED)
    {
        gfx_printf("Clicked\n");
    }
}

touch_event_t touchpad;

bool handle_touch(lv_indev_drv_t * indev, lv_indev_data_t * data)
{
    touch_poll(&touchpad);

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


void lvgl_adapter_init(argon_ctxt_t* argon_ctxt)
{
    lv_init();
    g_gfx_con.fillbg = 1;

    static lv_disp_buf_t disp_buf;
    lv_disp_buf_init(&disp_buf,
                     argon_ctxt->vdb,
                     NULL,
                     LV_HOR_RES_MAX * LV_VER_RES_MAX);

    // Initialize framebuffer drawing functions.
    lv_disp_drv_t disp_drv;			   /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);	   /*Basic initialization*/
    disp_drv.flush_cb = display_flush; /*Set your driver function*/
    disp_drv.buffer = &disp_buf;	   /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);   /*Finally register the driver*/

    // Touch support
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = handle_touch;
    lv_indev_drv_register(&indev_drv);
    touchpad.touch = false;

    lv_theme_t *th = lv_theme_zen_init(167, NULL);
    lv_theme_set_current(th);

    lv_obj_t *base_tabs = lv_tabview_create(lv_scr_act(), NULL);
	lv_obj_align(base_tabs, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 20);
	lv_obj_t* statustab = lv_tabview_add_tab(base_tabs, "Status");
	lv_tabview_add_tab(base_tabs, "Network");

    lv_obj_t *btn = lv_btn_create(statustab, NULL); /*Add a button the current screen*/
    lv_obj_set_pos(btn, 300, 300);					   /*Set its position*/
    lv_obj_set_size(btn, 100, 50);					   /*Set its size*/
    lv_obj_set_event_cb(btn, power_off);			   /*Assign a callback to the button*/

    lv_obj_t *label = lv_label_create(btn, NULL); /*Add a label to the button*/
    lv_label_set_text(label, "Reboot RCM");


    
    lv_task_create(minerva_periodic_training,
                   500,
                   LV_TASK_PRIO_HIGH, 
                   argon_ctxt->mtc_conf);

    while (true) 
    {
        lv_tick_inc(1);
        lv_task_handler();
		msleep(1);
        // break;
    }
}