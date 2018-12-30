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
#include "utils/fs_utils.h"

bool render_custom_background()
{
    u8* custom_bg = (u8*)sd_file_read(CUSTOM_BG_PATH);
    if (custom_bg == NULL)
        return false;
    
    gfx_render_bmp_arg_bitmap(&g_gfx_ctxt, custom_bg, 0, 0, 1280, 720);
    return true;
}

bool render_custom_title()
{
    u8* title_bmp = (u8*)sd_file_read(CUSTOM_TITLE_PATH);
    if (title_bmp == NULL)
        return false;

    u32 bmp_width = (title_bmp[0x12] | (title_bmp[0x13] << 8) | (title_bmp[0x14] << 16) | (title_bmp[0x15] << 24));
    u32 bmp_height = (title_bmp[0x16] | (title_bmp[0x17] << 8) | (title_bmp[0x18] << 16) | (title_bmp[0x19] << 24));
    gfx_render_bmp_arg_bitmap(&g_gfx_ctxt, (u8*)title_bmp, 420, 10, bmp_width, bmp_height);
    return true;
}

