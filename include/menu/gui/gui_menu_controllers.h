#ifndef _GUI_MENU_CTRL_
#define _GUI_MENU_CTRL_

#include "libs/lvgl/lvgl.h"
#include "core/argon-ctxt.h"

argon_ctxt_t* g_argon_ctxt;

void ctrl_reboot_rcm(lv_obj_t *obj, lv_event_t event);
void ctrl_reboot_ofw(lv_obj_t *obj, lv_event_t event);
void ctrl_power_off(lv_obj_t *obj, lv_event_t event);
void ctrl_lauch_payload(lv_obj_t *obj, lv_event_t event);

#endif