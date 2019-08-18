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
#include "gfx/lvgl_adapter.h"

#include "mem/heap.h"

#include "soc/hw_init.h"
// #include "core/launcher.h"

#include "utils/util.h"
#include "utils/fs_utils.h"
#include "utils/touch.h"
#include "utils/btn.h"
// #include "menu/gui/gui_argon_menu.h"

#include "power/battery.h"
#include "power/max17050.h"

#include "minerva/minerva.h"


extern void pivot_stack(u32 stack_top);

static inline void setup_gfx()
{
    u32 *fb = display_init_framebuffer();
	gfx_init_ctxt((u32*)FB_ADDRESS, 720, 1280, 720);
	gfx_con_init();
    // gfx_con_setcol(0xFFCCCCCC, 0xFFCCCCCC, 1);
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
    g_gfx_con.mute = 0; /* Silence minerva, comment for debug */
    minerva();
    minerva_change_freq(FREQ_1600);
    g_gfx_con.mute = 0;

    /* Cofigure touch input */
    touch_power_on();
    
    /* Mount Sd card and launch payload */
    if (sd_mount())
    {
        // bool cancel_auto_chainloading = btn_read() & BTN_VOL_DOWN;
        // bool load_menu = cancel_auto_chainloading || launch_payload("argon/payload.bin");
        
        // gfx_printf(&g_gfx_con, "Autochainload canceled. Loading menu...\n");
        // gfx_swap_buffer(&g_gfx_ctxt);

        // if (load_menu)
        //     gui_init_argon_menu();

        // gfx_swap_buffer(&g_gfx_ctxt);
        lvgl_adapter_init();
        wait_for_button_and_reboot();

    } else {
        gfx_printf("No sd card found...\n");
    }

    /* If payload launch fails wait for user input to reboot the switch */
    gfx_printf("Press power button to reboot into RCM...\n\n");
    wait_for_button_and_reboot();
}