#include "sly2.h"
struct IFACE { char pad[8]; short delta; short index; void (*reserve)(void *, int); };
struct GIFS { char pad0[0xC]; unsigned long *pb; char pad1[0x18 - 0x10]; IFACE *iface; };
void GIFS_AddPrimTag(GIFS *gifsArg, long prim, int cloop, long creg, unsigned long regs, unsigned feop)
{
    register GIFS *gifs asm("$18") = gifsArg;
    register long primReg asm("$17") = prim;
    IFACE *iface = gifs->iface;
    iface->reserve((char *)gifs + iface->delta, 0);
    unsigned long *pdw = gifs->pb;
    gifs->pb = pdw + 2;
    pdw[0] = ((unsigned long)feop << 15) | (long)cloop | 0x400000000000UL | ((unsigned long)primReg << 0x2F) | ((unsigned long)creg << 0x3C);
    pdw[1] = regs;
}
