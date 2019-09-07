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
#include "soc/bpmp.h"

#include "core/argon-resources.h"
#include "core/argon-ctxt.h"
#include "core/launcher.h"

#include "menu/gui/gui_menu.h"

#include "utils/util.h"
#include "utils/fs_utils.h"
#include "utils/touch.h"
#include "utils/btn.h"

#include "power/battery.h"
#include "power/max17050.h"

#include "minerva/minerva.h"


extern void pivot_stack(u32 stack_top);

static inline void setup_gfx()
{
    gfx_init_ctxt((u32 *)FB_ADDRESS, 720, 1280, 720);
	gfx_con_init();
}


void ipl_main()
{
    /* Load needed hw*/
    bpmp_mmu_enable();

    heap_init(0x90020000);

    /* Init display and gfx module */
    setup_gfx();
    
    /* Initialize ArgonNX context */
    argon_ctxt_t argon_ctxt;
    argon_ctxt_init(&argon_ctxt);

    /* Train DRAM */
    g_gfx_con.mute = 0; /* Silence minerva, comment for debug */
    minerva(argon_ctxt.mtc_conf);
    minerva_change_freq(argon_ctxt.mtc_conf, FREQ_1600);
    g_gfx_con.mute = 0;
    
    bpmp_clk_rate_set(BPMP_CLK_SUPER_BOOST);

    /* Cofigure touch input */
    touch_power_on();
    
    /* Mount Sd card and launch payload */
    if (sd_mount())
    {
        bool cancel_auto_chainloading = btn_read() & BTN_VOL_DOWN;
        bool load_menu = cancel_auto_chainloading || launch_payload(&argon_ctxt, "argon/payload.bin");
        
        if (load_menu)
        {
            argon_resources_init();
            lvgl_adapter_init(&argon_ctxt);
            gui_menu_draw(&argon_ctxt);
            gui_menu_open(&argon_ctxt);
            gui_menu_destroy(&argon_ctxt);
        }
        wait_for_button_and_reboot();

    } else {
        gfx_printf("No sd card found...\n");
    }

    /* If payload launch fails wait for user input to reboot the switch */
    gfx_printf("Press power button to reboot into RCM...\n\n");
    wait_for_button_and_reboot();
}