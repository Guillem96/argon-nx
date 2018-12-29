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

#include "../logo_bmp.h"

#include <string.h>

#define COLUMNS 4  
#define ROWS 2
#define ELEM_SIZE 230
#define MARGIN_TOP 80
#define MARGIN_LEFT 45

#define MINOR_VERSION 1
#define MAJOR_VERSION 0

#define CUSTOM_BACKGROUND_PATH "argon/background.bmp"

void setup_gfx_gui()
{
    /* Custom background*/
    u8* custom_bg = (u8*)sd_file_read(CUSTOM_BACKGROUND_PATH);
    if (custom_bg != NULL)
        gfx_render_bmp_arg_bitmap(&g_gfx_ctxt, custom_bg, 0, 0, 1280, 720);
    else 
        gfx_clear_color(&g_gfx_ctxt, 0xFF191414);
    
    gfx_con_setcol(&g_gfx_con, 0xFFF9F9F9, 0, 0xFF191414);

    /* Render logo */
    u32 bmp_width = (logo_bmp[0x12] | (logo_bmp[0x13] << 8) | (logo_bmp[0x14] << 16) | (logo_bmp[0x15] << 24));
    u32 bmp_height = (logo_bmp[0x16] | (logo_bmp[0x17] << 8) | (logo_bmp[0x18] << 16) | (logo_bmp[0x19] << 24));
    gfx_render_bmp_arg_bitmap_transparent(&g_gfx_ctxt, (u8*)logo_bmp, 30, 10, bmp_width, bmp_height, 0);

    /* Render title */
    g_gfx_con.scale = 4;
    gfx_con_setpos(&g_gfx_con, 120, 20);
    gfx_printf(&g_gfx_con, "ArgonNX v%d.%d", MAJOR_VERSION, MINOR_VERSION);
}

/* Generate entries dynamically */
void generate_payloads_entries(const char* payloads, gui_menu_t* menu)
{
    if (payloads == NULL)
    {
        g_gfx_con.scale = 4;
        gfx_con_setpos(&g_gfx_con, 140, 250);
        gfx_printf(&g_gfx_con, "Payloads directory is empty...\n");
        
        g_gfx_con.scale = 3;
        gfx_con_setpos(&g_gfx_con, 110, 370);
        gfx_printf(&g_gfx_con, "Place your payloads inside \"%s\"", PAYLOADS_DIR);

        return;
    }

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
        u32 x = g_gfx_ctxt.width / COLUMNS * col + MARGIN_LEFT;
        u32 y = g_gfx_ctxt.height / ROWS * row + MARGIN_TOP + (row == 0 ? 30 : -60);

        gui_menu_append_entry(menu, 
            gui_create_menu_entry(&payloads[i * 256], 
                                    sd_file_read(payload_logo), 
                                    x, y,
                                    200, 200,
                                    (int (*)(void *))launch_payload, (void*)payload_path));
        i++;
    }
}

/* Init needed menus for ArgonNX */
void gui_init_argon_menu(void)
{
    setup_gfx_gui();

    /* Init pool for menu */
    gui_menu_pool_init();

    gui_menu_t* menu = gui_menu_create("ArgonNX");

    generate_payloads_entries(dirlist(PAYLOADS_DIR, "*.bin", false), menu);

    gui_menu_append_entry(menu, 
            gui_create_menu_entry("Power off", NULL, 900, 680, 1, 1, (int (*)(void *))power_off, NULL));

    gui_menu_append_entry(menu, 
            gui_create_menu_entry("Reboot RCM", NULL, 1100, 680, 1, 1, (int (*)(void *))reboot_rcm, NULL));


    gui_menu_open(menu);

    /* Clear all entries and menus */
    gui_menu_pool_cleanup();
}