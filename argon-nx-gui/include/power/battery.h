/*
 * Battery charger driver for Nintendo Switch's TI BQ24193
 *
 * Copyright (C) 2019 Guillem96
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

#include "utils/types.h"

#ifndef _BATTERY_H_
#define _BATTERY_H_

typedef enum 
{
    NOT_CHARGING,
    CHARGING,
    FAST_CHARGING,
    TERMINATED,
    UNKNOWN,
} charge_status_t;

typedef struct {
    charge_status_t charge_status;
    u32 percent;
} battery_status_t;

void battery_get_status(battery_status_t* battery_status);
charge_status_t battery_charge_status();
const char* battery_str_charge_status(charge_status_t);
void battery_percent(int*);

#endif