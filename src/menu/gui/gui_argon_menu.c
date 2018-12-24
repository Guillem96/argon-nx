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
#include "menu/gui/gui_menu.h"
#include "menu/gui/gui_menu_pool.h"

#include "gfx/gfx.h"
#include "utils/types.h"
#include "utils/fs_utils.h"
#include "utils/dirlist.h"
#include "utils/util.h"
#include "core/launcher.h"
#include "core/payloads.h"

#include "mem/heap.h"

#include <string.h>

#define COLUMNS 4  
#define ROWS 2
#define ELEM_SIZE 230
#define MARGIN 50


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
    gfx_con_setpos(&g_gfx_con, 550, 10);
    gfx_printf(&g_gfx_con, "ArgonNX");

    char* dir = "argon/payloads";
    const char* payloads = dirlist(dir, "*.bin", false);

    /* Init pool for menu */
    gui_menu_pool_init();

    gui_menu_t* menu = gui_menu_create("ArgonNX");

    /* Generate dinamycally the entries */
    u32 i = 0;
    /* For each payload generate its logo, its name and its path */
    while(payloads[i * 256])
    {
        char* payload_path = (char*)malloc(256);
        payload_full_path(&payloads[i * 256], payload_path);
        
        char payload_logo[256];
        payload_logo_path(&payloads[i * 256], payload_logo);

        u32 row = i / COLUMNS;
        u32 col = i % COLUMNS;
        u32 x = g_gfx_ctxt.width / COLUMNS * col + MARGIN;
        u32 y = g_gfx_ctxt.height / ROWS * row + MARGIN + (row == 0 ? 30 : -30);

        gui_menu_append_entry(menu, 
            gui_create_menu_entry(&payloads[i * 256], 
                                    sd_file_read("argon/logos/Reinx.bmp"), 
                                    x, y,
                                    200, 200,
                                    (int (*)(void *))launch_payload, (void*)payload_path));
        i++;
    }

    gui_menu_append_entry(menu, 
            gui_create_menu_entry("Power off", NULL, 900, 680, 1, 1, (int (*)(void *))power_off, NULL));

    gui_menu_append_entry(menu, 
            gui_create_menu_entry("Reboot RCM", NULL, 1100, 680, 1, 1, (int (*)(void *))reboot_rcm, NULL));


    gui_menu_open(menu);

    // gfx_render_bmp_arg_file(&g_gfx_ctxt, "argon/logos/fusee-primary.bmp", 100, 100, 200, 200);

    /* Clear all entries and menus */
    gui_menu_pool_cleanup();
}

// W: 1280
// H: 720
// 4 columnes
// 2 Files
// 250 cada elem

// W / cols
// H / 2