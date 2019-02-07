/*
 * Copyright (c) 2018 naehrwert
 * Copyright (C) 2018 CTCaer
 * Copyright (C) 2018 Guillem96
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

#include "utils/fs_utils.h"

#include "mem/heap.h"
#include "gfx/gfx.h"
#include <string.h>

bool sd_mount()
{
	if (g_sd_mounted)
		return true;

	if (!sdmmc_storage_init_sd(&g_sd_storage, &g_sd_sdmmc, SDMMC_1, SDMMC_BUS_WIDTH_4, 11))
	{
        gfx_printf(&g_gfx_con, "%kFailed to init SD card.\nMake sure that it is inserted.\nOr that SD reader is properly seated!%k\n", 0xFFFFDD00, 0xFFCCCCCC);
	}
	else
	{
		int res = 0;
		res = f_mount(&g_sd_fs, "", 1);
		if (res == FR_OK)
		{
			g_sd_mounted = 1;
			return true;
		}
		else
		{
            gfx_printf(&g_gfx_con, "%kFailed to mount SD card (FatFS Error %d).\nMake sure that a FAT partition exists..%k\n", 0xFFFFDD00, res, 0xFFCCCCCC);
		}
	}

	return false;
}

void sd_unmount()
{
	if (g_sd_mounted)
	{
		f_mount(NULL, "", 1);
		sdmmc_storage_end(&g_sd_storage);
		g_sd_mounted = false;
	}
}

void *sd_file_read(char *path)
{
	FIL fp;
	if (f_open(&fp, path, FA_READ) != FR_OK)
		return NULL;

	u32 size = f_size(&fp);
	void *buf = malloc(size);

	u8 *ptr = buf;
	while (size > 0)
	{
		u32 rsize = MIN(size, 512 * 512);
		if (f_read(&fp, ptr, rsize, NULL) != FR_OK)
		{
			free(buf);
			return NULL;
		}

		ptr += rsize;
		size -= rsize;
	}

	f_close(&fp);

	return buf;
}

int sd_save_to_file(void *buf, u32 size, const char *filename)
{
	FIL fp;
	u32 res = 0;
	res = f_open(&fp, filename, FA_CREATE_ALWAYS | FA_WRITE);
	if (res)
	{
        gfx_printf(&g_gfx_con, "%kError (%d) creating file\n%s.\n%k\n", 0xFFFFDD00, res, filename, 0xFFCCCCCC);
		return 1;
	}

	f_sync(&fp);
	f_write(&fp, buf, size, NULL);
	f_close(&fp);

	return 0;
}

bool sd_file_exists(const char* filename)
{
    FIL fp;
	u32 res = 0;
	res = f_open(&fp, filename, FA_READ);
	if (res == FR_OK)
	{
        f_close(&fp);
        return true;
	}

    return false;
}

void flipVertically(unsigned char* pixels_buffer, const unsigned int width, const unsigned int height, const int bytes_per_pixel)
{
    const unsigned int rows = height / 2; // Iterate only half the buffer to get a full flip
    const unsigned int row_stride = width * bytes_per_pixel;
    unsigned char* temp_row = (unsigned char*)malloc(row_stride);

    int source_offset, target_offset;

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        source_offset = rowIndex * row_stride;
        target_offset = (height - rowIndex - 1) * row_stride;

        memcpy(temp_row, pixels_buffer + source_offset, row_stride);
        memcpy(pixels_buffer + source_offset, pixels_buffer + target_offset, row_stride);
        memcpy(pixels_buffer + target_offset, temp_row, row_stride);
    }

    free(temp_row);
    temp_row = NULL;
}