#include "core/argon-ctxt.h"
#include "mem/heap.h"

void argon_ctxt_init(argon_ctxt_t* argon_ctxt)
{
    /* Minerva */
    argon_ctxt->mtc_conf = (mtc_config_t*)malloc(sizeof(mtc_config_t));
}

void argon_ctxt_destroy(argon_ctxt_t* argon_ctxt)
{
    free(argon_ctxt->mtc_conf);    
    free(argon_ctxt);
}