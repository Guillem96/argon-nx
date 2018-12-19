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
#include "menu/argon_menu.h"
#include "menu/menu.h"
#include "menu/menu_pool.h"
#include "menu/menu_entry.h"
#include "gfx/gfx.h"
#include "core/launcher.h"
#include "utils/util.h"

void init_argon_menu()
{
    // TODO: Read payloads using dirlist("argon/payloads", "*.bin", false)
    char* payloads[] = { "fusee.bin", "Reinx.bin", "hekate.bin", "fusee-primary.bin" };
    u32 num_payloads = 4;

    /* Init pool for menu */
    menu_pool_init();

    /* Create a menu context */
	menu_t *argon_menu = menu_create("ArgonNX Menu");

    /* Create menu to launch payloads */
	menu_entry_t *launch_separator = create_menu_entry("--- Payloads ---", 0xFF7AADFF, NULL, NULL);
    for(s8 i = 0; i < num_payloads; i++)
    {
        menu_entry_t *current_payload = create_menu_entry("Launch ReiNX", WHITE, launch_payload, payloads[i]);
        menu_append_entry(argon_menu, current_payload);
    }
    
    /* Create menu to reboot or power off nx */
	menu_entry_t *utils_separator = create_menu_entry("--- Reboot Options ---", 0xFF7AADFF, NULL, NULL);
	menu_entry_t *reboot_rcm_entry = create_menu_entry("Reboot into RCM", WHITE, reboot_rcm, NULL);
    menu_entry_t *launc_ofw_entry = create_menu_entry("Reboot normal (won't work with AutoRCM)", WHITE, reboot_normal, NULL);
	menu_entry_t *shutdown_entry = create_menu_entry("Power Off", WHITE, power_off, NULL);

	menu_append_entry(argon_menu, reboot_rcm_entry);
    menu_append_entry(argon_menu, launc_ofw_entry);
	menu_append_entry(argon_menu, shutdown_entry);

    /* Render the menu */
	menu_open(argon_menu);

    /* Clear all entries and menus */
    menu_pool_cleanup();
}