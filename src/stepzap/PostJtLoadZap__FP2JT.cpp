#include "sly2.h"
struct JTENT { int oid; int unk4; void *pxf; };
struct JT { void *pjt; int unk4; int unk8; int unkC; int unk10; int count; JTENT *aent; };
#include "alloc.h"
extern "C" char D_002BFA30[];
void *PvAllocSwCopyImpl(int, void *);
extern "C" void *func_001F4C58(void *, int, int);
void PostJtLoadZap(JT *pzap)
{
    ALLOCREQ req;
    int i;
    pzap->count = 7;
    req.cb = 0x54;
    req.cbAlign = 0x10;
    pzap->aent = (JTENT *)PvAllocSwCopyImpl((int)&req, D_002BFA30);
    for (i = 0; i < pzap->count; i++) {
        JTENT *pent = &pzap->aent[i];
        pent->pxf = func_001F4C58(pzap->pjt, pent->oid, 6);
    }
}
