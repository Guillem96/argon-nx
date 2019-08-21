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

#include <string.h>


custom_gui_t* custom_gui_load()
{
    custom_gui_t* custom_gui = (custom_gui_t*)malloc(sizeof(custom_gui_t));
    custom_gui->custom_bg = bmp_to_lvimg_obj(CUSTOM_BG_PATH);
    custom_gui->title_bmp = (u8*)sd_file_read(CUSTOM_TITLE_PATH);
    return custom_gui;
}

void custom_gui_end(custom_gui_t* cg)
{
    free(cg->custom_bg);
    free(cg->title_bmp);
    free(cg);
}

bool render_custom_background(custom_gui_t* cg, lv_obj_t* par)
{
    if (cg->custom_bg == NULL)
    {
        return false;
    }
    // lv_obj_t *cnr = lv_cont_create(par, NULL);
    // lv_obj_set_size(cnr, LV_HOR_RES, LV_VER_RES);
    
    lv_obj_t *img = lv_img_create(par, NULL);
    lv_img_set_src(img, cg->custom_bg);
    return true;
}

bool render_custom_title(custom_gui_t* cg)
{  
    if (cg->title_bmp == NULL)
        return false;

    u32 bmp_width = (cg->title_bmp[0x12] | (cg->title_bmp[0x13] << 8) | (cg->title_bmp[0x14] << 16) | (cg->title_bmp[0x15] << 24));
    u32 bmp_height = (cg->title_bmp[0x16] | (cg->title_bmp[0x17] << 8) | (cg->title_bmp[0x18] << 16) | (cg->title_bmp[0x19] << 24));
    // gfx_render_bmp_arg_bitmap(&g_gfx_ctxt, cg->title_bmp, 420, 10, bmp_width, bmp_height);
    return true;
}
