#include "sly2.h"
struct IFACE { char pad[8]; short delta; short index; void (*reserve)(void *, int); };
struct GIFS { char pad0[0xC]; unsigned long *pb; char pad1[0x18 - 0x10]; IFACE *iface; };
void GIFS_AddPrimTag(GIFS *gifs, long prim, int cloop, long creg, unsigned long regs, unsigned feop)
{
    IFACE *iface = gifs->iface;
    iface->reserve((char *)gifs + iface->delta, 0);
    unsigned long *pdw = gifs->pb;
    unsigned long primBits = ((unsigned long)prim << 0x2F) | 0x400000000000UL;
    unsigned long low = (long)cloop | ((unsigned long)feop << 15);
    gifs->pb = pdw + 2;
    pdw[0] = low | primBits | ((unsigned long)creg << 0x3C);
    pdw[1] = regs;
}
