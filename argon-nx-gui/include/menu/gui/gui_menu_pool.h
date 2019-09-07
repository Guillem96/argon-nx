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
#ifndef _GUI_MENU_POOL_H_
#define _GUI_MENU_POOL_H_

#include "libs/lvgl/lvgl.h"

typedef struct {
    int max_items;
    int current_items;
    lv_obj_t** menus;
} gui_menu_pool_t;


/* Initializes the pool */
void gui_menu_pool_init(gui_menu_pool_t* pool);

/* Add a lv object to the pool */
void gui_menu_pool_push(gui_menu_pool_t* pool, lv_obj_t* item);

/* Deallocate all entries and menus */
void gui_menu_pool_cleanup(gui_menu_pool_t* pool);

#endif