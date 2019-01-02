/*
 * Copyright (c) 2018 Guillem96
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
#ifndef _CUSTOM_GUI_H_
#define _CUSTOM_GUI_H_

#include "utils/types.h"

#define CUSTOM_BG_PATH "argon/background.bmp"
#define CUSTOM_TITLE_PATH "argon/title.bmp"

/* Renders custom background, returns false if background.bmp does not exist */
bool render_custom_background();

/* Renders custom title, returns false if title.bmp does not exist */
bool render_custom_title();

/* Tool to take screenshots */
int screenshot(void* params);

#endif