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
#include "menu/gui/gui_menu_pool.h"
#include "mem/heap.h"

void gui_menu_pool_init(gui_menu_pool_t* pool)
{
    pool->max_items = 0x16;
    pool->current_items = 0;
    pool->menus = (lv_obj_t **)malloc(sizeof(lv_obj_t *) * pool->max_items);
}

void gui_menu_pool_push(gui_menu_pool_t* pool, lv_obj_t *obj)
{
    if (obj != NULL)
    {
        if (pool->current_items == pool->max_items - 1)
        {
            // Resize the pool
            u32 new_size = pool->max_items << 1;
            pool->menus = (lv_obj_t **)m_realloc(pool->menus, sizeof(lv_obj_t *) * pool->max_items, new_size);
            pool->max_items = new_size;
        }
        pool->menus[pool->current_items] = obj;
        pool->current_items++;
    }
}

void gui_menu_pool_cleanup(gui_menu_pool_t* pool)
{
    for (int i = 0; i < pool->current_items; ++i)
        free(pool->menus[i]);
    free(pool->menus);
    free(pool);
}