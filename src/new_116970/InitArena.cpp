#include "sly2.h"
extern char D_002CA550[];
struct Arena { void *vt; int cb; void *base; int used; };
Arena *InitArena(Arena *a, int cb, void *base)
{
    a->vt = D_002CA550;
    a->cb = cb;
    a->base = base;
    a->used = 0;
    return a;
}
