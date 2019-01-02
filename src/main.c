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

#include "gfx/di.h"
#include "gfx/gfx.h"

#include "mem/heap.h"

#include "soc/hw_init.h"

#include "core/launcher.h"

#include "utils/util.h"
#include "utils/fs_utils.h"
#include "utils/touch.h"
#include "utils/btn.h"

#include "menu/gui/gui_argon_menu.h"

#include "minerva/minerva.h"

#define PATH_ENABLE_TOUCH "argon/touch"

extern void pivot_stack(u32 stack_top);

static inline void setup_gfx()
{
    u32 *fb = display_init_framebuffer();
    gfx_init_ctxt(&g_gfx_ctxt, fb, 1280, 720, 720);
    gfx_con_init(&g_gfx_con, &g_gfx_ctxt);
    gfx_con_setcol(&g_gfx_con, 0xFFCCCCCC, 1, BLACK);
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

    /* Train DRAM */
    g_gfx_con.mute = 1; /* Silence minerva, comment for debug */
    minerva();
    g_gfx_con.mute = 0;

    /* Cofigure touch input */
    /* If touch file exists enable touch support*/
    g_touch_enabled = sd_file_exists(PATH_ENABLE_TOUCH);
    touch_power_on(); // Needs a game card lol
    
    /* Mount Sd card and launch payload */
    if (sd_mount())
    {
        bool cancel_auto_chainloading = btn_read() & BTN_VOL_DOWN;
        bool load_menu = cancel_auto_chainloading || launch_payload("argon/payload.bin");
        
        if (load_menu)
            gui_init_argon_menu();

    } else {
        gfx_printf(&g_gfx_con, "No sd card found...\n");
    }

    /* If payload launch fails wait for user input to reboot the switch */
    gfx_printf(&g_gfx_con, "Press power button to reboot into RCM...\n\n");
    wait_for_button_and_reboot();
}