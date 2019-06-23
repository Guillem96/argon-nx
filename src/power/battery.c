/*
 * Battery charger driver for Nintendo Switch's TI BQ24193
 *
 * Copyright (C) 2018 CTCaer
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

#include "power/battery.h"
#include "power/bq24193.h"
#include "power/max17050.h"
#include "utils/types.h"


void battery_get_status(battery_status_t* battery_status)
{
    battery_status->charge_status = battery_charge_status();
    battery_percent((int*)&(battery_status->percent));
    battery_status->percent = (battery_status->percent >> 8) & 0xFF;
}

charge_status_t battery_charge_status()
{
    int value = 0;

    bq24193_get_property(BQ24193_ChargeStatus, &value);
	switch (value)
	{
	case 0:
        return NOT_CHARGING; 
	case 1:
		return CHARGING;
	case 2:
		return FAST_CHARGING;
	case 3:
		return TERMINATED;
	default:
		return UNKNOWN;
    }
}

void battery_percent(int* percent) 
{
    max17050_get_property(MAX17050_RepSOC, percent);
}

const char* battery_str_charge_status(charge_status_t charge_status)
{
    const char *values[] = 
    { 
        "Not Charging", 
        "Charging", 
        "Fast Charging", 
        "Full",
        "Unknown"
    };

    return values[charge_status];
}
