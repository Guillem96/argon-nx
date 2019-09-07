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
#include "soc/bpmp.h"

#include "core/launcher.h"

#include "utils/util.h"
#include "utils/fs_utils.h"
#include "utils/btn.h"

#include "power/max17050.h"


extern void pivot_stack(u32 stack_top);

static inline void setup_gfx()
{
    gfx_init_ctxt((u32 *)FB_ADDRESS, 720, 1280, 720);
    memset((u32 *)FB_ADDRESS, 0, 0x3C0000);
	gfx_con_init();
}

static void error_end(const char* error_msg)
{
    display_init_framebuffer();
    gfx_clear_grey(0x0);
    gfx_printf("%s\n", error_msg);
    
    gfx_printf("Press power button to reboot into RCM...\n\n");
    wait_for_button_and_reboot();
}


void ipl_main()
{
    /* Configure Switch Hardware (thanks to hekate project) */
    config_hw();
    bpmp_mmu_enable();

    /* Init the stack and the heap */
    pivot_stack(0x90010000);
    heap_init(0x90020000);

    /* Init display and gfx module */
    display_init();
    setup_gfx();
    display_backlight_pwm_init();
    display_backlight_brightness(100, 1000);

    
    bpmp_clk_rate_set(BPMP_CLK_SUPER_BOOST);
    
    /* Mount Sd card and launch payload */
    if (sd_mount())
    {  

        u8* splash = sd_file_read("argon/splash.bmp");
        if (splash)
        {
            gfx_render_splash(splash);
            display_init_framebuffer();
            msleep(1000);
        } 
        else 
        {
            error_end("No splash found\n");
        }

        launch_payload("argon/sys/argon-nx-gui.bin");
        error_end("Fail chainloading GUI\n");
    } else {
        error_end("No sd card found...\n");
    }
    error_end("");
}