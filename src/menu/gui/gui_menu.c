/*  
 * Copyright (c) 2018 Guillem96
 *
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

#include "menu/gui/gui_menu.h"
#include "menu/gui/gui_menu_pool.h"
#include "menu/gui/gui_menu_controllers.h"

#include "power/battery.h"

#include "core/custom-gui.h"
#include "core/payloads.h"

#include "utils/util.h"
#include "utils/dirlist.h"

#include "gfx/gfx.h"
#include "gfx/lvgl_adapter.h"

#include <string.h>

#define MINOR_VERSION 3
#define MAJOR_VERSION 0


// static void gui_menu_draw_battery()
// {
//     battery_status_t battery_status;
//     battery_get_status(&battery_status);
//     u32 color = get_battery_color(battery_status);
// }

/* Render functions */
static bool render_title(argon_ctxt_t *);

static bool render_tabs(argon_ctxt_t *);
static bool render_payloads_tab(lv_obj_t *, argon_ctxt_t *);
static bool render_single_payload_tab(lv_obj_t *, argon_ctxt_t *, char*, u32);
static bool render_payloads_entries(lv_obj_t *, argon_ctxt_t *, char*, u32);
static bool render_tools_tab(lv_obj_t *, argon_ctxt_t *);

void gui_menu_draw(argon_ctxt_t *argon_ctxt)
{
    lv_style_scr.body.main_color = GRAD_1;
    lv_style_scr.body.grad_color = GRAD_2;
    
    custom_gui_t *cg = custom_gui_load();

    if (!render_custom_background(cg, lv_scr_act()))
    {
        gfx_printf("\nFail drawing bg\n");
    }

    render_title(argon_ctxt);
    render_tabs(argon_ctxt);
}

void gui_menu_open(argon_ctxt_t *argon_ctxt)
{
    while (true)
    {
        lv_tick_inc(1);
        lv_task_handler();
        msleep(1);
    }
}

void gui_menu_destroy(argon_ctxt_t *argon_ctxt)
{
    argon_ctxt_destroy(argon_ctxt);
}

static bool render_tabs(argon_ctxt_t *argon_ctxt)
{
    lv_obj_t *base_tabs = lv_tabview_create(lv_scr_act(), NULL);
    lv_obj_set_pos(base_tabs, 0, 0);
    lv_tabview_set_btns_pos(base_tabs, LV_TABVIEW_BTNS_POS_BOTTOM);
    lv_tabview_set_style(base_tabs, LV_TABVIEW_STYLE_BG, &lv_style_transp_tight);

    /* Disable animations */
    lv_tabview_set_anim_time(base_tabs, 0);
    lv_tabview_set_sliding(base_tabs, false);

    /* Render all tabs */
    render_payloads_tab(base_tabs, argon_ctxt);
    render_tools_tab(base_tabs, argon_ctxt);

    return true;
}

static bool render_payloads_tab(lv_obj_t *par, argon_ctxt_t *ctxt)
{
    char* payloads = dirlist(PAYLOADS_DIR, "*.bin", false);
    u32 i = 0;
    u32 group = 0;

    while(payloads[i * 256])
    {
        if (i % 4 == 0)
        {
            render_single_payload_tab(par, ctxt, payloads, group);
            group++;
        }
        i++;
    }

    if (group == 0)
        render_single_payload_tab(par, ctxt, payloads, group);

    return true;
}

static bool render_single_payload_tab(lv_obj_t *par, argon_ctxt_t * ctxt, char* payloads, u32 group)
{
    /* Setting scrollable view */
    lv_obj_t* payloads_tab = lv_tabview_add_tab(par,
                                    LV_SYMBOL_DIRECTORY " Payloads");
    lv_page_set_sb_mode(payloads_tab, LV_SB_MODE_OFF);

    lv_obj_t*  page = lv_page_create(payloads_tab, NULL);
    lv_obj_set_size(page, lv_obj_get_width(payloads_tab), 400);
    lv_obj_align(page, payloads_tab, LV_ALIGN_CENTER, 0, 50);

    /* Horizontal grid layout */
    lv_obj_t*  cnr = lv_page_get_scrl(page);
    lv_cont_set_layout(cnr, LV_LAYOUT_PRETTY);
    lv_obj_set_size(cnr, LV_HOR_RES_MAX, lv_obj_get_height(page));

    lv_cont_set_style(cnr, 
                    LV_CONT_STYLE_MAIN, 
                    lv_theme_get_argon()->style.panel);
    render_payloads_entries(cnr, ctxt, payloads, group);

    gui_menu_pool_push(ctxt->pool, payloads_tab);
    return true;
}

static void my_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        lv_obj_t label = lv_obj_get_child(obj, NULL)[0];
    gfx_printf("%s\n", lv_label_get_text(&label));
    }
    
}

static bool render_payloads_entries(lv_obj_t *par_tabview, argon_ctxt_t *argon_ctxt, char* payloads, u32 group)
{
    lv_obj_t *btn;
    lv_obj_t *label;
    lv_img_dsc_t* img;

    u32 i = 4 * group;

    static lv_style_t style_pr;
    lv_style_copy(&style_pr, &lv_style_plain);
    style_pr.image.color = LV_COLOR_BLACK;
    style_pr.image.intense = LV_OPA_50;
    style_pr.text.color = lv_color_hex3(0xaaa);

    static lv_style_t inv_label;
    lv_style_copy(&style_pr, &lv_style_plain);
    inv_label.body.opa = LV_OPA_0;

    while (payloads[i * 256] && i < 4 * (group + 1))
    {
        char payload_path[256];
        payload_full_path(&payloads[i * 256], payload_path);
        
        char payload_logo[256];
        payload_logo_path(&payloads[i * 256], payload_logo);

        img = bmp_to_lvimg_obj((const char*)payload_logo);

        if (!img)
        {
            btn = lv_btn_create(par_tabview, NULL);
            lv_obj_set_size(btn, 280, 280);
            
            label = lv_label_create(btn, NULL);
            lv_label_set_text(label, &payloads[i * 256]);
            gui_menu_pool_push(argon_ctxt->pool, label);
        }
        else
        {   
            btn = lv_imgbtn_create(par_tabview, NULL);
            
            label = lv_label_create(btn, NULL);
            lv_label_set_text(label, payload_path);
            lv_obj_set_style(label, &inv_label);
            lv_imgbtn_set_style(btn, LV_BTN_STATE_PR, &style_pr);
            lv_imgbtn_set_src(btn, LV_BTN_STATE_REL, img);
            lv_imgbtn_set_src(btn, LV_BTN_STATE_PR, img);            
        }

        lv_obj_set_event_cb(btn, my_event_cb);
        gui_menu_pool_push(argon_ctxt->pool, btn);

        i++;
    }

    return true;
}


static bool render_tools_tab(lv_obj_t* par, argon_ctxt_t* ctxt)
{
    lv_obj_t *settings_tab = lv_tabview_add_tab(par,
                                                LV_SYMBOL_SETTINGS " Settings");
    
    lv_obj_t *btn = lv_btn_create(settings_tab, NULL);
    lv_obj_set_size(btn, 200, 80);
    lv_obj_set_event_cb(btn, ctrl_reboot_rcm);

    lv_obj_t* label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Reboot RCM");

    btn = lv_btn_create(settings_tab, NULL);
    lv_obj_set_size(btn, 200, 80);
    lv_obj_set_event_cb(btn, ctrl_power_off);
    lv_obj_set_pos(btn, 200, 200);

    label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Power of");

    lv_obj_t* line = lv_line_create(settings_tab, NULL);

    static lv_point_t line_points[] = { {20, 400}, {1000, 400} };
    lv_line_set_points(line, line_points, 2);

    gui_menu_pool_push(ctxt->pool, settings_tab);
    return true;
}

static bool render_title(argon_ctxt_t * ctxt)
{
    lv_obj_t* title = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(title, "Argonnx");
    lv_obj_set_width(title, 500);
    lv_obj_align(title, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 50);
    
    static lv_style_t label_style;
    lv_style_copy(&label_style, &lv_style_plain);
    label_style.text.color = LV_COLOR_WHITE;
    lv_obj_set_style(title, &label_style);

    gui_menu_pool_push(ctxt->pool, title);
    return true;
}