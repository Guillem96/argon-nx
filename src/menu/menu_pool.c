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
#include "menu/menu_pool.h"

void menu_pool_init()
{
    g_menu_pool = (menu_pool_t *)malloc(sizeof(menu_pool_t));
    g_menu_pool->max_items = 0x16;
    g_menu_pool->current_items = 0;
    g_menu_pool->menus = (menu_t **)malloc(sizeof(menu_t *) * g_menu_pool->max_items);
}

void menu_push_to_pool(menu_t *menu)
{
    if (menu != NULL)
    {
        if (g_menu_pool->current_items == g_menu_pool->max_items - 1)
        {
            // Resize the pool
            g_menu_pool->max_items = g_menu_pool->max_items << 1;
            g_menu_pool->menus = (menu_t **)realloc(g_menu_pool->menus, sizeof(menu_t *) * g_menu_pool->max_items);
        }
        g_menu_pool->menus[g_menu_pool->current_items] = menu;
        g_menu_pool->current_items++;
    }
}

void menu_pool_cleanup()
{
    for (int i = 0; i < g_menu_pool->current_items; ++i)
        menu_destroy(g_menu_pool->menus[i]);
    free(g_menu_pool->menus);
    free(g_menu_pool);
}
