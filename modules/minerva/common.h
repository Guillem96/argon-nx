#ifndef _COMMON_H_
#define _COMMON_H_
#include <stddef.h>

#include "gfx.h"
#include "heap.h"

// Module Callback
typedef void (*cbMainModule_t)(const char *s);
typedef void (*memcpy_t)(void *, void *, size_t);
typedef void (*memset_t)(void *, int, size_t);

typedef struct _bdkParams_t
{
	gfx_con_t *gfxCon;
	gfx_ctxt_t *gfxCtx;
	heap_t *sharedHeap;
	memcpy_t memcpy;
	memset_t memset;
} *bdkParams_t;

// Module Entrypoint
typedef void (*moduleEntrypoint_t)(void *, bdkParams_t);

#endif