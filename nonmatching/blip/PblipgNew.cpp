#include "sly2.h"
struct SLOTHEAP { int pad; int cFree; int pad2; int pad3; int pvFree; };
struct BLIPG;
struct VT { char pad[0x38]; short delta; short index; void (*fn)(void *); char pad2[0x18]; short delta2; short index2; void (*fn2)(void *); char pad3[0x18]; short delta3; short index3; void (*fn3)(void *); };
struct BLIPG { int unk0; int unk4; int unk8; VT *vptr; };
struct SW { char pad[0x407C]; int pvFree; int pad2; int cSlotMax; };
extern char D_002CB5D8;
void *memset(void *, int, unsigned int);
extern "C" {
void *PvAllocSlotheapImpl(void *);
void *PdlFromSwCid(void *, int);
void AppendSlEntry(void *, void *);
}
BLIPG *PblipgNew(SW *psw)
{
    if (psw->pvFree == 0) {
        if (psw->cSlotMax != 0)
            return 0;
    }
    BLIPG *pblipg = (BLIPG *)PvAllocSlotheapImpl((char *)psw + 0x4070);
    memset(pblipg, 0, 0x460);
    pblipg->unk0 = 0;
    pblipg->unk4 = 0;
    pblipg->vptr = (VT *)&D_002CB5D8;
    int i = 31;
    do {
    } while (--i != -1);
    AppendSlEntry(PdlFromSwCid(psw, 0x1C), pblipg);
    pblipg->vptr->fn((char *)pblipg + pblipg->vptr->delta);
    pblipg->vptr->fn2((char *)pblipg + pblipg->vptr->delta2);
    pblipg->vptr->fn3((char *)pblipg + pblipg->vptr->delta3);
    return pblipg;
}
