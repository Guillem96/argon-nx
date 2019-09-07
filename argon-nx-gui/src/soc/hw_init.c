/*
 * Copyright (c) 2018 naehrwert
 * Copyright (c) 2018 CTCaer
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

#include "soc/hw_init.h"

#include "gfx/di.h"

#include "mem/mc.h"
#include "mem/sdram.h"

#include "minerva/minerva.h"

#include "power/max77620.h"
#include "power/max7762x.h"

#include "sec/se.h"
#include "sec/se_t210.h"

#include "soc/clock.h"
#include "soc/fuse.h"
#include "soc/gpio.h"
#include "soc/i2c.h"
#include "soc/pinmux.h"
#include "soc/pmc.h"
#include "soc/t210.h"
#include "soc/uart.h"
#include "soc/bpmp.h"

#include "storage/sdmmc.h"

#include "utils/util.h"
#include "utils/fs_utils.h"


void reconfig_hw_workaround(argon_ctxt_t *argon_ctxt, bool extra_reconfig, u32 magic)
{
    bpmp_mmu_disable();
    bpmp_clk_rate_set(BPMP_CLK_NORMAL);

    minerva_change_freq(argon_ctxt->mtc_conf, FREQ_204);

    // Re-enable clocks to Audio Processing Engine as a workaround to hanging.
    CLOCK(CLK_RST_CONTROLLER_CLK_OUT_ENB_V) |= (1 << 10); // Enable AHUB clock.
    CLOCK(CLK_RST_CONTROLLER_CLK_OUT_ENB_Y) |= (1 << 6);  // Enable APE clock.

    if (extra_reconfig)
    {
        msleep(10);
        PMC(APBDEV_PMC_PWR_DET_VAL) |= PMC_PWR_DET_SDMMC1_IO_EN;

        clock_disable_cl_dvfs();

        // Disable Joy-con GPIOs.
        gpio_config(GPIO_PORT_G, GPIO_PIN_0, GPIO_MODE_SPIO);
        gpio_config(GPIO_PORT_D, GPIO_PIN_1, GPIO_MODE_SPIO);
        gpio_config(GPIO_PORT_E, GPIO_PIN_6, GPIO_MODE_SPIO);
        gpio_config(GPIO_PORT_H, GPIO_PIN_6, GPIO_MODE_SPIO);

        // Fix GPU after warmboot for Linux.
        i2c_send_byte(I2C_5, MAX77620_I2C_ADDR, MAX77620_REG_GPIO5, 2);
        i2c_send_byte(I2C_5, MAX77620_I2C_ADDR, MAX77620_REG_GPIO6, 2);

        // Touch
        gpio_config(GPIO_PORT_J, GPIO_PIN_7, GPIO_MODE_SPIO);
    }

    // Power off display.
    display_end();

    // Enable clock to USBD and init SDMMC1 to avoid hangs with bad hw inits.
    if (magic == 0xBAADF00D)
    {
        CLOCK(CLK_RST_CONTROLLER_CLK_OUT_ENB_L) |= (1 << 22);
        sdmmc_init(&g_sd_sdmmc, SDMMC_1, SDMMC_POWER_3_3, SDMMC_BUS_WIDTH_1, 5, 0);
        clock_disable_cl_dvfs();

        msleep(200);
    }
}
