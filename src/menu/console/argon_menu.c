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
#include "menu/console/argon_menu.h"
#include "menu/console/menu.h"
#include "menu/console/menu_pool.h"
#include "menu/console/menu_entry.h"
#include "gfx/gfx.h"
#include "core/launcher.h"
#include "mem/heap.h"
#include "utils/util.h"
#include "utils/dirlist.h"

#include <string.h>

int tool_reboot_normal(void*);
int tool_reboot_rcm(void*);
int tool_power_off(void*);

void init_argon_menu()
{
    char* dir = "argon/payloads";
    const char* payloads = dirlist(dir, "*.bin", false);
    /* Init pool for menu */
    menu_pool_init();

    /* Create a menu context */
	menu_t *argon_menu = menu_create("ArgonNX Menu");

    /* Create menu to launch payloads */
	menu_entry_t *launch_separator = create_menu_entry("--- Payloads ---", 0xFF7AADFF, NULL, NULL);
    menu_append_entry(argon_menu, launch_separator);
    
    /* Generate dinamycally the entries */
    u32 i = 0;
    while(payloads[i * 256])
    {
        char* payload = (char*)malloc(256);
        strcpy(payload, dir);
        strcat(payload, "/");
        strcat(payload, &payloads[i * 256]);

        char buff[64];
        strcpy(buff, "Launch ");
        strcat(buff,  &payloads[i * 256]);
        menu_append_entry(argon_menu, create_menu_entry(buff, WHITE, (int (*)(void *))launch_payload, (void*)payload));
        i++;
    }
    
    /* Create menu to reboot or power off nx */
	menu_entry_t *utils_separator = create_menu_entry("--- Reboot Options ---", 0xFF7AADFF, NULL, NULL);
	menu_entry_t *reboot_rcm_entry = create_menu_entry("Reboot into RCM", WHITE, tool_reboot_rcm, NULL);
    menu_entry_t *launc_ofw_entry = create_menu_entry("Reboot normal (won't work with AutoRCM)", WHITE, tool_reboot_normal, NULL);
	menu_entry_t *shutdown_entry = create_menu_entry("Power Off", WHITE, tool_power_off, NULL);

	menu_append_entry(argon_menu, utils_separator);
	menu_append_entry(argon_menu, reboot_rcm_entry);
    menu_append_entry(argon_menu, launc_ofw_entry);
	menu_append_entry(argon_menu, shutdown_entry);

    /* Render the menu */
	menu_open(argon_menu);

    /* Clear all entries and menus */
    menu_pool_cleanup();
}

int tool_reboot_normal(void* param)
{
    reboot_normal();
    return 0;
}
int tool_reboot_rcm(void* param)
{
    reboot_rcm();
    return 0;
}

int tool_power_off(void* param)
{
    power_off();
    return 0;
}