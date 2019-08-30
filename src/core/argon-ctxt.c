#include "core/argon-ctxt.h"
#include "mem/heap.h"
#include "libs/lvgl/lvgl.h"

void argon_ctxt_init(argon_ctxt_t* argon_ctxt)
{
    /* Screen setting init */
    argon_ctxt->is_display_init = false;
    argon_ctxt->vdb = (u32*)malloc(sizeof(u32) * LV_HOR_RES_MAX * LV_VER_RES_MAX);
    
    /* Lv objects pool */
    argon_ctxt->pool = (gui_menu_pool_t*)malloc(sizeof(gui_menu_pool_t));
    gui_menu_pool_init(argon_ctxt->pool);

    /* Minerva */
    argon_ctxt->mtc_conf = (mtc_config_t*)malloc(sizeof(mtc_config_t));
}

void argon_ctxt_destroy(argon_ctxt_t* argon_ctxt)
{
    free(argon_ctxt->vdb);

    free(argon_ctxt->mtc_conf);

    gui_menu_pool_cleanup(argon_ctxt->pool);
    
    free(argon_ctxt);
}