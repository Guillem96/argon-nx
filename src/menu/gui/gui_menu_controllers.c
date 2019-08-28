#include "menu/gui/gui_menu_controllers.h"
#include "utils/util.h"
#include "menu/gui/gui_menu_pool.h"
#include "core/launcher.h"

void ctrl_reboot_rcm(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        argon_ctxt_destroy(g_argon_ctxt);
        reboot_rcm();
    }
}

void ctrl_reboot_ofw(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        argon_ctxt_destroy(g_argon_ctxt);
        reboot_normal();
    }
}

void ctrl_power_off(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        argon_ctxt_destroy(g_argon_ctxt);
        power_off();
    }
}

void ctrl_lauch_payload(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_obj_t label = lv_obj_get_child(obj, NULL)[0];
        char* path = lv_label_get_text(&label);
        launch_payload(g_argon_ctxt, path);
    }
}
