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

#include <string.h>
#include <stdlib.h>

#include "gfx/di.h"
#include "gfx/gfx.h"

#include "mem/heap.h"
#include "soc/hw_init.h"
#include "soc/t210.h"
#include "core/launcher.h"
#include "utils/util.h"
#include "utils/fs_utils.h"

extern void pivot_stack(u32 stack_top);

static inline void setup_gfx()
{
    u32 *fb = display_init_framebuffer();
	gfx_init_ctxt(&g_gfx_ctxt, fb, 720, 1280, 720);
	gfx_con_init(&g_gfx_con, &g_gfx_ctxt);
    gfx_con_setcol(&g_gfx_con, 0xFFCCCCCC, 1, 0xFF1B1B1B);
    gfx_con_setpos(&g_gfx_con, 0, 0);
}

void ipl_main()
{
    /* Configure Switch Hardware (thanks to hekate project) */
    config_hw();

    /* Init the stack and the heap */
	pivot_stack(0x90010000);
	heap_init(0x90020000);

    /* Init display and gfx module */
	display_init();
    setup_gfx();
    display_backlight_pwm_init();
	display_backlight_brightness(100, 1000);

    /* Mount Sd card and launch payload */
    if(sd_mount())
    {
        gfx_printf(&g_gfx_con, "Hello from ArgonNX\n\n");
        if(launch_payload("payload.bin"))
        {
            gfx_printf(&g_gfx_con, "Error loading the payload\n\n");
        }
    }

    /* If payload launch fails wait for user input to reboot the switch */
    gfx_printf(&g_gfx_con, "Press power button to reboot into RCM...\n\n");
	wait_for_button_and_reboot();
}
