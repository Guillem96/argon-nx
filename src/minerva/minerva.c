#include "minerva/minerva.h"

#include "utils/types.h"
#include "utils/util.h"
#include "utils/fs_utils.h"

#include "soc/fuse.h"
#include "soc/t210.h"
#include "soc/clock.h"

#include "gfx/gfx.h"

#include "mem/sdram.h"

#include "ianos/ianos.h"

#include "../modules/minerva/mtc.h"

void minerva()
{
    if(!sd_mount())
    {
        gfx_printf(&g_gfx_con, "Error mounting sd card");
        return;
    }

    mtc_config_t mtc_cfg;
    gfx_clear_partial_grey(&g_gfx_ctxt, 0, 0, 1256);
	gfx_con_setpos(&g_gfx_con, 0, 0);
	u32 curr_ram_idx = 0;

	gfx_printf(&g_gfx_con, "-- Minerva Training Cell --\n");
	
    // Set table to ram.
	mtc_cfg.mtc_table = NULL;
	mtc_cfg.sdram_id = get_sdram_id();
	ianos_loader(false, "argon/sys/minerva.bso", DRAM_LIB, (void *)&mtc_cfg);

	gfx_printf(&g_gfx_con, "Starting training process..\n");
	// Get current frequency
	for (curr_ram_idx = 0; curr_ram_idx < 10; curr_ram_idx++)
	{
		if (CLOCK(CLK_RST_CONTROLLER_CLK_SOURCE_EMC) == mtc_cfg.mtc_table[curr_ram_idx].clk_src_emc)
			break;
	}
	mtc_cfg.rate_from = mtc_cfg.mtc_table[curr_ram_idx].rate_khz;
	mtc_cfg.rate_to = 800000;
	mtc_cfg.train_mode = OP_TRAIN_SWITCH;
	gfx_printf(&g_gfx_con, "Training and switching %7d -> %7d\n", mtc_cfg.mtc_table[curr_ram_idx].rate_khz, 800000);
	ianos_loader(false, "argon/sys/minerva.bso", DRAM_LIB, (void *)&mtc_cfg);
	
	// Thefollowing frequency needs periodic training every 100ms.
	msleep(200);
	
	mtc_cfg.rate_to = 1600000;
	gfx_printf(&g_gfx_con, "Training and switching  %7d -> %7d\n", mtc_cfg.current_emc_table->rate_khz, 1600000);
    mtc_cfg.train_mode = OP_PERIODIC_TRAIN;
	ianos_loader(false, "argon/sys/minerva.bso", DRAM_LIB, (void *)&mtc_cfg);

	mtc_cfg.train_mode = OP_TEMP_COMP;
	ianos_loader(false, "argon/sys/minerva.bso", DRAM_LIB, (void *)&mtc_cfg);

	gfx_printf(&g_gfx_con, "Finished!");
}