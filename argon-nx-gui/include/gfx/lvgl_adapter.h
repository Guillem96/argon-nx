#ifndef _LVGL_ADAPTER_H_
#define _LVGL_ADAPTER_H_

#include "core/argon-ctxt.h"

void lvgl_adapter_init(argon_ctxt_t* argon_ctxt);
lv_img_dsc_t *bmp_to_lvimg_obj(const char *path);

#endif