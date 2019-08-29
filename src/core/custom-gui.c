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

