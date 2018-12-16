/*
 * Copyright (c) 2018 Atmosphère-NX
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
 
#include "handlers/exception_handlers.h"
#include "panic/panic.h"
#include "hwinit.h"
#include "gfx/di.h"
#include "utils/timers.h"
#include "utils/fs_utils.h"
#include "memory/sdmmc/sdmmc.h"
#include "lib/log.h"
#include "lib/vsprintf.h"
#include "gfx/display/video_fb.h"
#include "gfx/gfx.h"

extern void (*__program_exit_callback)(int rc);

static void *g_framebuffer;


static void setup_env(void) {
    g_framebuffer = (void *)0xC0000000;

    /* Initialize hardware. */
    nx_hwinit();

    /* Check for panics. */
    check_and_display_panic();

    /* Zero-fill the framebuffer and register it as printk provider. */
    video_init(g_framebuffer);
    
    /* Initialize the display. */
    display_init();

    /* Set the framebuffer. */
    display_init_framebuffer(g_framebuffer);

    /* Turn on the backlight after initializing the lfb */
    /* to avoid flickering. */
    display_backlight(true);

    /* Set up the exception handlers. */
    setup_exception_handlers();
    
    /* Mount the SD card. */
    mount_sd();
}

static void cleanup_env(void) {
    /* Unmount the SD card. */
    unmount_sd();

    display_backlight(false);
    display_end();
}

static void setup_gfx(gfx_ctxt_t* ctxt, gfx_con_t* con)
{
    gfx_init_ctxt(ctxt, g_framebuffer, 720, 1280, 768);
    gfx_clear_color(ctxt, 0xFF000000);
    gfx_con_init(con, ctxt);
    gfx_con_setcol(con, 0xFFFFFFFF, 0, 0);
}

int main(void) {
    ScreenLogLevel log_level = SCREEN_LOG_LEVEL_MANDATORY;
    gfx_ctxt_t gfx_ctxt;
    gfx_con_t gfx_con;

    /* Override the global logging level. */
    log_set_log_level(log_level);
    
    /* Initialize the display, console, etc. */
    setup_env();
    setup_gfx(&gfx_ctxt, &gfx_con);

    /* Say hello. */
    gfx_printf(&gfx_con, "Hello from ArgonNX!\n");

    /* Wait a while. */
    mdelay(10000);
    
    /* Deinitialize the display, console, etc. */
    cleanup_env();
    
    return 0;
}
