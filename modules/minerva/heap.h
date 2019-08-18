#ifndef _HEAP_H_
#define _HEAP_H_
#include "types.h"
typedef struct _hnode
{
	int used;
	u32 size;
	struct _hnode *prev;
	struct _hnode *next;
} hnode_t;

typedef struct _heap
{
	u32 start;
	hnode_t *first;
} heap_t;

#endif