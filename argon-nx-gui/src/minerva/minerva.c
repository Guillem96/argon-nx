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


void minerva(mtc_config_t *mtc_cfg)
{
    /* Mount sd card */
    if (!sd_mount())
    {
        gfx_printf("Error mounting sd card\n");
        return;
    }

    gfx_printf("-- Minerva Training Cell --\n");
    
    // Set table to ram.
    mtc_cfg->mtc_table = NULL;
    mtc_cfg->sdram_id = (fuse_read_odm(4) >> 3) & 0x1F;
    u32 ep_addr = ianos_loader(false, "argon/sys/minerva.bso", DRAM_LIB, (void *)mtc_cfg);
    minerva_cfg = (void *)ep_addr;

    if (!minerva_cfg)
    {
        gfx_printf("Abort Minerva Training Cell\n");
        return;
    }

    gfx_printf("Starting training process.. \n");


    u32 curr_ram_idx;
    for (curr_ram_idx = 0; curr_ram_idx < 10; curr_ram_idx++)
	{
		if (CLOCK(CLK_RST_CONTROLLER_CLK_SOURCE_EMC) == mtc_cfg->mtc_table[curr_ram_idx].clk_src_emc)
			break;
	}

    mtc_cfg->rate_from = mtc_cfg->mtc_table[curr_ram_idx].rate_khz;
    mtc_cfg->rate_to = 204000;
    mtc_cfg->train_mode = OP_TRAIN;
    minerva_cfg(mtc_cfg, NULL);
    mtc_cfg->rate_to = 800000;
    minerva_cfg(mtc_cfg, NULL);
    mtc_cfg->rate_to = 1600000;
    minerva_cfg(mtc_cfg, NULL);
    gfx_printf("-- Finished Minerva Training Cell --\n");
}

void minerva_change_freq(mtc_config_t *mtc_cfg, minerva_freq_t freq)
{
	if (!minerva_cfg)
		return;

	if (minerva_cfg && (mtc_cfg->rate_from != freq))
	{
		mtc_cfg->rate_to = freq;
		mtc_cfg->train_mode = OP_SWITCH;
		minerva_cfg(mtc_cfg, NULL);
	}
}

void minerva_periodic_training(lv_task_t * task)
{
    mtc_config_t* mtc_cfg = task->user_data;

    if (minerva_cfg && mtc_cfg->rate_from == FREQ_1600)
    {
        mtc_cfg->train_mode = OP_PERIODIC_TRAIN;
        minerva_cfg(mtc_cfg, NULL);
    }
}