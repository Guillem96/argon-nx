#include "menu/gui/gui_menu_controllers.h"
#include "utils/util.h"
#include "menu/gui/gui_menu_pool.h"


void ctrl_reboot_rcm(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        reboot_rcm();
    }
}

void ctrl_power_off(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        power_off();
    }
}