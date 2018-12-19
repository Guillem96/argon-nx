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
#ifndef _MENU_ENTRY_H
#define _MENU_ENTRY_H

#include "utils/types.h"

typedef struct
{
	char text[0x100];
	u32 color;
	void *param;
	int (*handler)(void *);
} menu_entry_t;

/* Creates a menu entry */
menu_entry_t *create_menu_entry(const char *text, u32 color, int (*handler)(void *), void *param);
int cancel(void *param);

#endif
