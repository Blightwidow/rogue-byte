#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct VT { char pad[0xF8]; short d; short i; QW *(*fn)(void *); };
struct CRV { char pad0[0xC]; VT *vt; char pad1[0xE8 - 0x10]; int ccv; int pad2[2]; QW *apos; };
struct ROPESIM {
    int g0; int g4; float gz; char pad0[0x20 - 0xC]; QW anchor0; QW anchor1; void *pxf0; void *pxf1; CRV *pcrv; int mode; int pad50;
    QW *apos; QW *avel; float *as; float drag; char pad60[0x6C - 0x64]; float k6c; float k70; char pad74[0x84 - 0x74]; int capacity; float dsNode;
};
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" void RemeasureRopeSim(ROPESIM *);
extern "C" char D_002C44F0;

ROPESIM *ConstructRopeSim(ROPESIM *prope, CRV *pcrv)
{
    prope->pcrv = pcrv;
    prope->mode = -1;
    ALLOCREQ request;
    request.cbAlign = 0x10;
    request.cb = pcrv->ccv << 4;
    prope->apos = (QW *)PvAllocSwClearImpl__Fi(&request);
    request.cbAlign = 0x10;
    request.cb = pcrv->ccv << 4;
    prope->avel = (QW *)PvAllocSwClearImpl__Fi(&request);
    request.cbAlign = 0x10;
    request.cb = pcrv->ccv << 2;
    void *pvArc = PvAllocSwClearImpl__Fi(&request);
    prope->gz = -1750.0f;
    prope->as = (float *)pvArc;
    prope->drag = 3.0f;
    prope->k6c = 500.0f;
    prope->k70 = 5.0f;
    prope->g0 = 0;
    prope->g4 = 0;
    CRV *crv = prope->pcrv;
    asm volatile("" : : "r" (crv));
    prope->dsNode = 300.0f;
    prope->capacity = crv->ccv;
    QW *mat = crv->vt->fn((char *)crv + crv->vt->d);
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4");
    register QW v5 asm("vf5");
    for (int icv = 0; icv < prope->pcrv->ccv; icv++) {
        int offset = icv << 4;
        QW *ppos = (QW *)(offset + (int)prope->pcrv->apos);
        QW *pdest = (QW *)(offset + (int)prope->apos);
        asm("lqc2 vf3, %1" : "=j" (v3) : "m" (mat[0]));
        asm("lqc2 vf5, %1" : "=j" (v5) : "m" (*ppos));
        asm("lqc2 vf4, %1" : "=j" (v4) : "m" (mat[1]));
        asm("lqc2 vf2, %1" : "=j" (v2) : "m" (mat[2]));
        asm("lqc2 vf1, %1" : "=j" (v1) : "m" (mat[3]));
        asm("vmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf3, vf1, vf0w" : "=j" (v3) : "j" (v1), "j" (v2), "j" (v3), "j" (v4), "j" (v5));
        asm volatile("sqc2 vf3, %0" : "=m" (*pdest) : "j" (v3));
    }
    prope->pxf0 = &D_002C44F0;
    prope->pxf1 = &D_002C44F0;
    CRV *crv2 = prope->pcrv;
    if (crv2->ccv > 0) {
        QW *apos = prope->apos;
        prope->anchor0 = apos[0];
        prope->anchor1 = apos[crv2->ccv - 1];
    }
    RemeasureRopeSim(prope);
    return prope;
}
