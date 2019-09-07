/*
 * Copyright (c) 2018 Guillem96
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "core/custom-gui.h"
#include "gfx/gfx.h"
#include "mem/heap.h"
#include "gfx/lvgl_adapter.h"
#include "utils/fs_utils.h"
#include "utils/util.h"

#include "libs/lvgl/lvgl.h"

#include <string.h>


custom_gui_t* custom_gui_load()
{
    custom_gui_t* custom_gui = (custom_gui_t*)malloc(sizeof(custom_gui_t));
    custom_gui->custom_bg = bmp_to_lvimg_obj(CUSTOM_BG_PATH);
    return custom_gui;
}

void custom_gui_end(custom_gui_t* cg)
{
    free(cg->custom_bg);
    free(cg);
}

bool render_custom_background(custom_gui_t* cg, lv_obj_t* par)
{
    if (cg->custom_bg == NULL)
        return false;
        
    lv_obj_t *img = lv_img_create(par, NULL);
    lv_img_set_src(img, cg->custom_bg);
    lv_obj_set_pos(img, 0, 0);
    lv_obj_set_width(img, LV_HOR_RES);
    return true;
}

void take_screenshot()
{
    static lv_style_t bg;
    lv_style_copy(&bg, &lv_style_pretty);
    bg.text.color = LV_COLOR_WHITE;
    bg.body.opa = LV_OPA_0;
    
    const u32 file_size = 0x384000 + 0x36;
    u8 *bitmap = malloc(file_size);
    u32 *fb = malloc(0x384000);
    u32 *fb_ptr = g_gfx_ctxt.fb;

    // Reconstruct FB for bottom-top, landscape bmp.
    for (u32 x = 0; x < 1280; x++)
    {
        for (int y = 719; y > -1; y--)
            fb[y * 1280 + x] = *fb_ptr++;
    }

    memcpy(bitmap + 0x36, fb, 0x384000);

    typedef struct _bmp_t
    {
        u16 magic;
        u32 size;
        u32 rsvd;
        u32 data_off;
        u32 hdr_size;
        u32 width;
        u32 height;
        u16 planes;
        u16 pxl_bits;
        u32 comp;
        u32 img_size;
        u32 res_h;
        u32 res_v;
        u64 rsvd2;
    } __attribute__((packed)) bmp_t;

    bmp_t *bmp = (bmp_t *)bitmap;

    bmp->magic    = 0x4D42;
    bmp->size     = file_size;
    bmp->rsvd     = 0;
    bmp->data_off = 0x36;
    bmp->hdr_size = 40;
    bmp->width    = 1280;
    bmp->height   = 720;
    bmp->planes   = 1;
    bmp->pxl_bits = 32;
    bmp->comp     = 0;
    bmp->img_size = 0x384000;
    bmp->res_h    = 2834;
    bmp->res_v    = 2834;
    bmp->rsvd2    = 0;

    char path[0x80];

    strcpy(path, "argon/screenshots");
    f_mkdir(path);
    s_printf(path + strlen(path), "/screen_%08X.bmp", get_tmr_us());
    sd_save_to_file(bitmap, file_size, path);

    free(bitmap);
    free(fb);

    lv_obj_t * mbox = lv_mbox_create(lv_layer_top(), NULL);
    lv_mbox_set_recolor(mbox, true);
    lv_obj_set_width(mbox, LV_DPI * 4);
    lv_obj_set_top(mbox, true);
    lv_obj_set_auto_realign(mbox, true);
    lv_obj_align(mbox, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 50);
    lv_mbox_set_text(mbox, "Screenshot saved!");
    lv_mbox_set_style(mbox, LV_MBOX_STYLE_BG, &bg);
    lv_mbox_start_auto_close(mbox, 4000);
}