/*
 * Copyright (c) 2018 Guillem96
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
#include "core/launcher.h"

#include <string.h>

#include "libs/fatfs/ff.h"

#include "utils/types.h"
#include "utils/util.h"
#include "utils/fs_utils.h"

#include "soc/hw_init.h"
#include "soc/bpmp.h"

#include "gfx/gfx.h"

#include "gfx/di.h"

#include "mem/heap.h"

// This is a safe and unused DRAM region for our payloads.
#define IPL_LOAD_ADDR      0x40003000
#define EXT_PAYLOAD_ADDR   0xC03C0000
#define PATCHED_RELOC_SZ   0x94
#define RCM_PAYLOAD_ADDR   (EXT_PAYLOAD_ADDR + ALIGN(PATCHED_RELOC_SZ, 0x10))
#define PAYLOAD_ENTRY      0x40010000
#define CBFS_SDRAM_EN_ADDR 0x4003e000
#define COREBOOT_ADDR      (0xD0000000 - 0x100000)

void (*ext_payload_ptr)() = (void *)EXT_PAYLOAD_ADDR;

void reloc_patcher(u32 payload_size)
{
	static const u32 START_OFF = 0x7C;
	static const u32 PAYLOAD_END_OFF = 0x84;
	static const u32 IPL_START_OFF = 0x88;

	memcpy((u8 *)EXT_PAYLOAD_ADDR, (u8 *)IPL_LOAD_ADDR, PATCHED_RELOC_SZ);

	*(vu32 *)(EXT_PAYLOAD_ADDR + START_OFF) = PAYLOAD_ENTRY - ALIGN(PATCHED_RELOC_SZ, 0x10);
	*(vu32 *)(EXT_PAYLOAD_ADDR + PAYLOAD_END_OFF) = PAYLOAD_ENTRY + payload_size;
	*(vu32 *)(EXT_PAYLOAD_ADDR + IPL_START_OFF) = PAYLOAD_ENTRY;

	if (payload_size == 0x7000)
	{
		memcpy((u8 *)(EXT_PAYLOAD_ADDR + ALIGN(PATCHED_RELOC_SZ, 0x10)), (u8 *)COREBOOT_ADDR, 0x7000); //Bootblock
		*(vu32 *)CBFS_SDRAM_EN_ADDR = 0x4452414D;
	}
}

int launch_payload(argon_ctxt_t* argon_ctxt, char *path)
{
    FIL fp;
    if (f_open(&fp, path, FA_READ))
    {
        gfx_printf("Cannot find %s\n", path);
        return 1;
    }

    // Read and copy the payload to our chosen address
    void *buf;
    u32 size = f_size(&fp);

    if (size < 0x30000)
        buf = (void *)RCM_PAYLOAD_ADDR;
    else
        buf = (void *)COREBOOT_ADDR;

    if (f_read(&fp, buf, size, NULL))
    {
        f_close(&fp);
        gfx_printf("Error loading %s\n", path);
        return 1;
    }

    f_close(&fp);	
    free(path);
    path = NULL;

    sd_unmount();

    if (size < 0x30000)
    {
        reloc_patcher(ALIGN(size, 0x10));
        reconfig_hw_workaround(argon_ctxt, false, byte_swap_32(*(u32 *)(buf + size - sizeof(u32))));
    }
    else
    {
        reloc_patcher(0x7000);
        if (*(vu32 *)CBFS_SDRAM_EN_ADDR != 0x4452414D)
            return 1;
        reconfig_hw_workaround(argon_ctxt, true, 0);
    }

    display_end();
    argon_ctxt_destroy(argon_ctxt);
    bpmp_mmu_disable();
	bpmp_clk_rate_set(BPMP_CLK_NORMAL);
    // Launch our payload.
    (*ext_payload_ptr)();

	return 1;
}
