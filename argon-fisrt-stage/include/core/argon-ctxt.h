#ifndef _ARGON_CTXT_H_
#define _ARGON_CTXT_H_

#include "minerva/minerva.h"

typedef struct
{
    /* Minerva configuration */
    mtc_config_t* mtc_conf;
} argon_ctxt_t;

void argon_ctxt_init(argon_ctxt_t* argon_ctxt);
void argon_ctxt_destroy(argon_ctxt_t* argon_ctxt);

#endif