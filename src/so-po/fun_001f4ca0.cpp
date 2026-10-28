#include "sly2.h"
struct XFA { char pad0[0x50]; int count; char *base; char pad1[0x10]; int *seg; };
struct SOA { char pad0[0x10]; SOA *parent; char pad1[0x3C]; int count; char *base; };
extern "C" void func_001F4CA0(SOA *so, SOA *src, int *ref)
{
    int old = *ref;
    if (old == 0) return;
    char *nw = 0;
    int idx = (old - (int)src->base) >> 8;
    if (idx >= 0 && idx < so->count) {
        nw = so->base + (idx << 8);
    } else {
        SOA *srcparent = src->parent;
        idx = (old - (int)srcparent->base) >> 8;
        if (idx >= 0 && idx < srcparent->count)
            nw = so->parent->base + (idx << 8);
    }
    if (*(int *)(nw + 0x88) == old + 0x80)
        *(int *)(nw + 0x88) = (int)nw + 0x80;
    if (*(int *)(nw + 0x8C) == old + 0x84)
        *(int *)(nw + 0x88) = (int)nw + 0x84;
    *ref = (int)nw;
}
