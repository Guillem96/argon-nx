#ifndef _ARGON_CTXT_H_
#define _ARGON_CTXT_H_

#include "minerva/minerva.h"
#include "menu/gui/gui_menu_pool.h"

typedef struct
{
    /* Screen settings */
    u32* vdb;
    bool is_display_init;

    /* Keep a reference to all menu objects */
    gui_menu_pool_t* pool;

    /* Minerva configuration */
    mtc_config_t* mtc_conf;
} argon_ctxt_t;

void argon_ctxt_init(argon_ctxt_t* argon_ctxt);
void argon_ctxt_destroy(argon_ctxt_t* argon_ctxt);

#endif