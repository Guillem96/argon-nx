#include "core/payloads.h"
#include <string.h>
#include "utils/dirlist.h"
#include "mem/heap.h"
#include "utils/util.h"
#include "gfx/gfx.h"

void payload_full_path(const char* payload, char* result)
{
    strcpy(result, PAYLOADS_DIR);
    strcat(result, "/");
    strcat(result, payload);
}

void payload_logo_path(const char* payload, char* result)
{   
    char tmp[256];
    strcpy(tmp, PAYLOADS_LOGOS_DIR);
    strcat(tmp, "/");
    strcat(tmp, payload);

    strcpy(result, str_replace(tmp, ".bin", ".bmp"));
}

