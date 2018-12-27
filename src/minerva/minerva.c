#include "minerva.h"
#include "utils/types.h"
#include "utils/btn.h"
#include "utils/util.h"
#include "utils/fs_utils.h"
#include "soc/fuse.h"
#include "mtc.h"
#include "mtc_mc_emc_regs.h"
#include "gfx/gfx.h"

void minerva()
{
    
    mtc_config_t mtc_cfg;
    gfx_clear_partial_grey(&g_gfx_ctxt, 0, 0, 1256);
	gfx_con_setpos(&g_gfx_con, 0, 0);
	u32 curr_ram_idx = 0;
	
    if (!sd_mount())
		return;
	gfx_printf(&g_gfx_con, "-- Minerva Training Cell --\n\n");
	
    // Set table to ram.
	mtc_cfg.mtc_table = NULL;
	mtc_cfg.sdram_id = (fuse_read_odm(4) >> 3) & 0x1F;
	_minerva_init(&mtc_cfg, NULL);

	gfx_printf(&g_gfx_con, "\nStarting training process..\n\n");
	// Get current frequency
	for (curr_ram_idx = 0; curr_ram_idx < 10; curr_ram_idx++)
	{
		if (CLOCK(CLK_RST_CONTROLLER_CLK_SOURCE_EMC) == mtc_cfg.mtc_table[curr_ram_idx].clk_src_emc)
			break;
	}
	mtc_cfg.rate_from = mtc_cfg.mtc_table[curr_ram_idx].rate_khz;
	mtc_cfg.rate_to = 800000;
	mtc_cfg.train_mode = OP_TRAIN_SWITCH;
	gfx_printf(&g_gfx_con, "Training and switching %7d -> %7d\n\n", mtc_cfg.mtc_table[curr_ram_idx].rate_khz, 800000);
	_minerva_init(&mtc_cfg, NULL);
	
	// Thefollowing frequency needs periodic training every 100ms.
	msleep(200);
	
	mtc_cfg.rate_to = 1600000;
	gfx_printf(&g_gfx_con, "Training and switching  %7d -> %7d\n\n", mtc_cfg.current_emc_table->rate_khz, 1600000);
    mtc_cfg.train_mode = OP_PERIODIC_TRAIN;
	_minerva_init(&mtc_cfg, NULL);
	
	mtc_cfg.train_mode = OP_TEMP_COMP;
	_minerva_init(&mtc_cfg, NULL);

	gfx_printf(&g_gfx_con, "Finished!");
    sd_unmount();
    btn_wait();
}