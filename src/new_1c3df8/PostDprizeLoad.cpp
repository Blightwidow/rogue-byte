#include "sly2.h"
struct VTH { char pad[0x48]; short delta; short idx; void (*fn)(void *); char pad2[0x260 - 0x50]; short delta2; short idx2; void (*fn2)(void *, int); };
struct DPRIZE {
    char pad[0xC]; VTH *vt;
    char pad1[0x158 - 0x10];
    int dprizes;
    char pad2[0x16C - 0x15C];
    void *shadow;
    char pad3[0x1A4 - 0x170];
    int oid0; void *plo0;
    int oid1; void *plo1;
    int oid2; void *plo2;
    char pad4[0x204 - 0x1BC];
    int oid3; void *plo3;
    int oid4; void *plo4;
    int oid5; void *plo5;
};
extern "C" char B_003DD490[];
extern "C" void PostSoLoad(DPRIZE *);
extern "C" void *PloFindSwObjectByClass(void *, int, int, void *);
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
void PostDprizeLoad(DPRIZE *pdprize)
{
    PostSoLoad(pdprize);
    void *shadow = PloFindSwObjectByClass(B_003DD490, 1, 0x12, pdprize);
    pdprize->shadow = shadow;
    if (shadow != 0) {
        VTH *vt = ((DPRIZE *)shadow)->vt;
        vt->fn((char *)shadow + vt->delta);
    }
    if (pdprize->oid0 != -1)
        pdprize->plo0 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid0, pdprize);
    if (pdprize->oid1 != -1)
        pdprize->plo1 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid1, pdprize);
    if (pdprize->oid2 != -1)
        pdprize->plo2 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid2, pdprize);
    if (pdprize->oid3 != -1)
        pdprize->plo3 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid3, pdprize);
    if (pdprize->oid4 != -1)
        pdprize->plo4 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid4, pdprize);
    if (pdprize->oid5 != -1)
        pdprize->plo5 = PloFindSwObject_thunk(B_003DD490, 4, pdprize->oid5, pdprize);
    pdprize->vt->fn2((char *)pdprize + pdprize->vt->delta2, pdprize->dprizes);
}
