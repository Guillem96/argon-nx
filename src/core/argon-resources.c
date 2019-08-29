#include "core/argon-resources.h"
#include "libs/fatfs/ff.h"

void argon_resources_init() 
{
    FIL fp;
	f_open(&fp, "argon/sys/resources.argon", FA_READ);
	f_read(&fp, (void *)ARGON_RES_ADDR, f_size(&fp), NULL);
	f_close(&fp);
}