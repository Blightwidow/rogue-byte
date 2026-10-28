#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct U4 { char b[4]; };
struct TEX { char pad[6]; unsigned char cframe; };
struct SHD { int oid; char pad4; unsigned char b5; unsigned char b6; char pad7; U4 color; char pad0c[12]; TEX *atex; };
struct FRAMES { int oid; int b6; int b5; U4 color; int cframe; long *atex0; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" long func_001EA6C8(TEX *, int, int);

void func_001EB678(SHD *pshd, FRAMES *pframes)
{
    ALLOCREQ allocreq;
    pframes->oid = pshd->oid;
    pframes->b6 = pshd->b6;
    pframes->b5 = pshd->b5;
    pframes->color = pshd->color;
    TEX *atex = pshd->atex;
    int cframe = atex->cframe;
    allocreq.cb = cframe * 8;
    allocreq.cbAlign = 0x10;
    pframes->cframe = cframe;
    pframes->atex0 = (long *)PvAllocSwClearImpl__Fi(&allocreq);
    for (int iframe = 0; iframe < pframes->cframe; iframe++)
    {
        long *slot = (long *)(iframe * 8 + (int)pframes->atex0);
        *slot = func_001EA6C8(atex, iframe, 0);
    }
}
