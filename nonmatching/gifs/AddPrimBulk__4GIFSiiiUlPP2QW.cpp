// SPDX-License-Identifier: GPL-3.0-or-later
struct QW;
struct VT { char pad[8]; short delta; short index; void (*reserve)(void *, int); };
struct GIFS { char pad[0xC]; unsigned long *pb; char pad1[8]; VT *vt; };
extern "C" void AddPrimBulk__4GIFSiiiUlPP2QW(GIFS *gifs, int prim, int cloop, int creg, unsigned long regs, QW **ppqw)
{
    gifs->vt->reserve((char *)gifs + gifs->vt->delta, 0);
    unsigned long *pdw = gifs->pb;
    gifs->pb = pdw + 2;
    pdw[0] = (unsigned long)cloop | ((unsigned long)prim << 0x2F) | 0x400000000000UL | ((unsigned long)creg << 0x3C);
    pdw[1] = regs;
    if (ppqw != 0)
        *ppqw = (QW *)gifs->pb;
    gifs->pb = (unsigned long *)((char *)gifs->pb + cloop * creg * 0x10);
}
