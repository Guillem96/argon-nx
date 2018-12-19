/*  
 * Copyright (c) 2018 Guillem96
 *
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

#include "menu/gui/gui_argon_menu.h"
#include "gfx/gfx.h"
#include "utils/types.h"
#include <string.h>

void setup_gfx_gui()
{
    u32 clear_color = 0xFFF7F7F7;
    gfx_con_setcol(&g_gfx_con, BLACK, 1, clear_color);
    gfx_clear_color(&g_gfx_ctxt, clear_color);
}

/* Init needed menus for ArgonNX */
void gui_init_argon_menu(void)
{
    setup_gfx_gui();
    gfx_printf(&g_gfx_con, "Hello from ArgonNX");

    gfx_render_bmp_arg_file(&g_gfx_ctxt, "argon/logos/fusee-primary.bmp", 100, 100, 200, 200);
}

