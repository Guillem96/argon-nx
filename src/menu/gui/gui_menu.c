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

bool g_force_render = true;

/* Render the menu */
static void gui_menu_draw(gui_menu_t *menu);

/* Update menu after an input */
static int gui_menu_update(gui_menu_t *menu);

gui_menu_t *gui_menu_create(const char *title)
{
	gui_menu_t *menu = (gui_menu_t *)malloc(sizeof(gui_menu_t));
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


static void gui_menu_draw(gui_menu_t *menu)
{
    for (s16 i = 0; i < menu->next_entry; i++)
	{
        gui_menu_render_entry(menu->entries[i], i == menu->selected_index, g_force_render);
	}
    g_force_render = false;
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
            gui_menu_draw(menu);
        }
    }
    
    return 1;
}


static int handle_btn_input(gui_menu_t *menu)
{
    gui_menu_entry_t *entry = NULL;
	u32 input;

    input = btn_wait();

	if ((input & BTN_VOL_DOWN) && menu->selected_index > 0)
	{
		menu->selected_index--;
	}
	else if ((input & BTN_VOL_UP) && menu->selected_index < menu->next_entry - 1)
	{
		menu->selected_index++;
	}
	else if (input & BTN_POWER)
	{
		entry = menu->entries[menu->selected_index];
		if (entry->handler != NULL)
		{
			if (entry->handler(entry->param) != 0)
				return 0;
            gui_menu_draw(menu);
		}
	}

    return 1;
}


static int gui_menu_update(gui_menu_t *menu)
{
    gui_menu_draw(menu);

    if (!g_touch_enabled)
        return handle_btn_input(menu);

    return handle_touch_input(menu);
}


int gui_menu_open(gui_menu_t *menu)
{    

	while (gui_menu_update(menu))
		;

	return 0;
}


void gui_menu_destroy(gui_menu_t *menu)
{
	for (int i = 0; i < menu->next_entry; i++)
		gui_menu_entry_destroy(menu->entries[i]);
	free(menu->entries);
	free(menu);
}