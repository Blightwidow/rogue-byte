#include "sly2.h"
#include "alloc.h"
#include "vu0inline.h"
struct VT { char pad[0xF8]; short d; short i; QW *(*fn)(void *); };
struct CRV { char pad0[0xC]; VT *vt; char pad1[0xE8 - 0x10]; int ccv; int pad2[2]; QW *apos; };
struct ROPESIM {
    int g0; int g4; float gz; char pad0[0x20 - 0xC]; QW anchor0; QW anchor1; void *pxf0; void *pxf1; CRV *pcrv; int mode; int pad50;
    QW *apos; QW *avel; float *as; float drag; char pad60[0x6C - 0x64]; float k6c; float k70; char pad74[0x84 - 0x74]; int capacity; float dsNode;
};
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" int RemeasureRopeSim(ROPESIM *);
extern "C" char D_002C44F0;

static inline QW TransformByRows(QW *rows, QW *source)
{
    return TransformPoint(*source, rows[0], rows[1], rows[2], rows[3]);
}

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
    prope->capacity = crv->ccv;
    prope->dsNode = 300.0f;
    QW *mat = crv->vt->fn((char *)crv + crv->vt->d);
    for (int icv = 0; icv < prope->pcrv->ccv; icv++) {
        int offset = icv << 4;
        QW *ppos = (QW *)(offset + (int)prope->pcrv->apos);
        QW *pdest = (QW *)(offset + (int)prope->apos);
        *pdest = TransformByRows(mat, ppos);
    }
    prope->pxf1 = &D_002C44F0;
    prope->pxf0 = &D_002C44F0;
    CRV *crv2 = prope->pcrv;
    if (crv2->ccv > 0) {
        QW *apos = prope->apos;
        prope->anchor0 = apos[0];
        prope->anchor1 = apos[crv2->ccv - 1];
    }
    RemeasureRopeSim(prope);
    return prope;
}
