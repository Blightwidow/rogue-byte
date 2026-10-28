#include "sly2.h"
struct VT { char pad[0x38]; short d0; short i0; void (*f0)(void *); char pad2[0x18]; short d1; short i1; void (*f1)(void *); char pad3[0x18]; short d2; short i2; void (*f2)(void *); };
struct PRIPG { int a; int b; int c; VT *vt; char pad[0x80 - 0x10]; char globset[0xD0]; int mode; };
struct SW { char pad[0x403C]; char slotheap[0x30]; int cached; };
extern "C" void *PvAllocSlotheapImpl(void *);
void *memset(void *, int, unsigned int);
extern "C" void *__4CRef(void *);
extern "C" void *PdlFromSwCid(SW *, int);
extern "C" void AppendSlEntry(void *, void *);
extern char D_002D9978[];
extern char D_002D77D8[];

PRIPG *PripgNew(SW *sw, int mode)
{
    if (mode == 0 && sw->cached != 0)
        return (PRIPG *)sw->cached;
    PRIPG *pripg = (PRIPG *)PvAllocSlotheapImpl(sw->slotheap);
    if (pripg == 0)
        return 0;
    memset(pripg, 0, 0x1B0);
    pripg->a = 0;
    pripg->b = 0;
    pripg->vt = (VT *)D_002D9978;
    __4CRef(pripg->globset);
    pripg->mode = mode;
    pripg->vt = (VT *)D_002D77D8;
    AppendSlEntry(PdlFromSwCid(sw, 0x57), pripg);
    pripg->vt->f0((char *)pripg + pripg->vt->d0);
    pripg->vt->f1((char *)pripg + pripg->vt->d1);
    pripg->vt->f2((char *)pripg + pripg->vt->d2);
    if (mode == 0)
        sw->cached = (int)pripg;
    return pripg;
}
