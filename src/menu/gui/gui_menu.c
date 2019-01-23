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

#include "menu/gui/gui_menu.h"
#include "menu/gui/gui_menu_pool.h"

#include "utils/touch.h"
#include "utils/btn.h"

#include "gfx/gfx.h"

#include "mem/heap.h"

#include "core/custom-gui.h"

#include <string.h>

#define MINOR_VERSION 3
#define MAJOR_VERSION 0


/* Render the menu */
static void gui_menu_render_menu(gui_menu_t*);
static void gui_menu_draw_background(gui_menu_t*);
static void gui_menu_draw_entries(gui_menu_t*);

/* Update menu after an input */
static int gui_menu_update(gui_menu_t*);

/* Handle input */
static int handle_touch_input(gui_menu_t*);

gui_menu_t *gui_menu_create(const char *title)
{
	gui_menu_t *menu = (gui_menu_t *)malloc(sizeof(gui_menu_t));
    menu->custom_gui = custom_gui_load();
	strcpy(menu->title, title);
	menu->next_entry = 0;
	menu->selected_index = 0;
    gui_menu_push_to_pool((void*)menu);
	return menu;
}


void gui_menu_append_entry(gui_menu_t *menu, gui_menu_entry_t *menu_entry)
{
	if (menu->next_entry == MAX_ENTRIES)
		return;

	menu->entries[menu->next_entry] = menu_entry;
	menu->next_entry++;
}

static void gui_menu_draw_background(gui_menu_t* menu)
{
    if(!render_custom_background(menu->custom_gui))
        gfx_clear_color(&g_gfx_ctxt, 0xFF191414);
    
    /* Render title */
    if (!render_custom_title(menu->custom_gui)) 
    {
        g_gfx_con.scale = 4;
        gfx_con_setpos(&g_gfx_con, 480, 20);
        gfx_printf(&g_gfx_con, "ArgonNX v%d.%d", MAJOR_VERSION, MINOR_VERSION);
    }
}

static void gui_menu_render_menu(gui_menu_t* menu) 
{
    gui_menu_draw_background(menu);
    gui_menu_draw_entries(menu);
    gfx_swap_buffer(&g_gfx_ctxt);
}

static void gui_menu_draw_entries(gui_menu_t *menu)
{
    for (s16 i = 0; i < menu->next_entry; i++)
        gui_menu_render_entry(menu->entries[i]);
}


static int gui_menu_update(gui_menu_t *menu)
{
    u32 res = 0;

    gui_menu_draw_background(menu);
    gui_menu_draw_entries(menu);

    res = handle_touch_input(menu);

    gfx_swap_buffer(&g_gfx_ctxt);

    return res;
}

int gui_menu_open(gui_menu_t *menu)
{   
    gfx_con_setcol(&g_gfx_con, 0xFFF9F9F9, 0, 0xFF191414);
    /* 
     * Render and flush at first render because blocking input won't allow us 
     * flush buffers
     */
    gui_menu_render_menu(menu);

	while (gui_menu_update(menu))
    ;

	return 0;
}

void gui_menu_destroy(gui_menu_t *menu)
{
	for (int i = 0; i < menu->next_entry; i++)
		gui_menu_entry_destroy(menu->entries[i]);
    custom_gui_end(menu->custom_gui);
	free(menu->entries);
	free(menu);
}


static int handle_touch_input(gui_menu_t *menu)
{
    gui_menu_entry_t *entry = NULL;
    touch_event_t event = touch_wait();
    
    /* After touch input check if any entry has ben tapped */
    for(u32 i = 0; i < menu->next_entry; i++)
    {
        entry = menu->entries[i];

        if (entry->handler != NULL 
            && is_rect_touched(&event, entry->x, entry->y, entry->width, entry->height))
        {
            if (entry->handler(entry->param) != 0)
                return 0;
        }
    }

    return 1;
}
