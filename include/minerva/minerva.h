#ifndef _MINERVA_H_
#define _MINERVA_H_

#include "mtc_table.h"

#include "libs/lvgl/lvgl.h"

typedef struct
{
	s32 rate_to;
	s32 rate_from;
	emc_table_t *mtc_table;
	u32 table_entries;
	emc_table_t *current_emc_table;
	u32 train_mode;
	u32 sdram_id;
	u32 prev_temp;
	bool emc_2X_clk_src_is_pllmb;
	bool fsp_for_src_freq;
	bool train_ram_patterns;
} mtc_config_t;

enum train_mode_t
{
	OP_SWITCH         = 0,
	OP_TRAIN          = 1,
	OP_TRAIN_SWITCH   = 2,
	OP_PERIODIC_TRAIN = 3,
	OP_TEMP_COMP      = 4
};

typedef enum
{
	FREQ_204  = 204000,
	FREQ_800  = 800000,
	FREQ_1600 = 1600000
} minerva_freq_t;


void (*minerva_cfg)(mtc_config_t *mtc_cfg, void *);
void minerva(mtc_config_t *mtc_cfg);
void minerva_change_freq(mtc_config_t *mtc_cfg, minerva_freq_t freq);
void minerva_periodic_training(lv_task_t * task);

#endif