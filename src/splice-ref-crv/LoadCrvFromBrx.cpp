#include "bis.h"
#include "alloc.h"
struct CRV {
    char pad0[0xE0];
    int flagsE0;
    int valueE4;
    int count;
    int *intsEC;
    int *intsF0;
    VECTOR *vectorsF4;
    char padF8[0x48];
    VECTOR *vectors140;
    VECTOR *vectors144;
};
extern "C" {
void CBinaryInputStream_Read_thunk(CBinaryInputStream *, int, void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, CBinaryInputStream *);
void LoadXfmBaseFromBrx(CRV *, CBinaryInputStream *);
void MeasureCrv(CRV *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
}
extern "C" void LoadCrvFromBrx(CRV *pcrv, CBinaryInputStream *pbis)
{
    ALLOCREQ req;
    int index;
    LoadXfmBaseFromBrx(pcrv, pbis);
    pcrv->flagsE0 = pbis->S8Read();
    pcrv->valueE4 = pbis->S8Read();
    pcrv->count = pbis->U16Read();
    req.cb = pcrv->count * 4;
    req.cbAlign = 0x10;
    pcrv->intsEC = (int *)PvAllocSwImpl__Fi(&req);
    req.cb = pcrv->count * 4;
    req.cbAlign = 0x10;
    pcrv->intsF0 = (int *)PvAllocSwImpl__Fi(&req);
    req.cb = pcrv->count * 0x10;
    req.cbAlign = 0x10;
    pcrv->vectorsF4 = (VECTOR *)PvAllocSwImpl__Fi(&req);
    CBinaryInputStream_Read_thunk(pbis, pcrv->count * 4, pcrv->intsEC);
    for (index = 0; index < pcrv->count; index++)
        pbis->ReadVector(&pcrv->vectorsF4[index]);
    if (pcrv->flagsE0 != 0) {
        req.cb = pcrv->count * 0x10;
        req.cbAlign = 0x10;
        pcrv->vectors140 = (VECTOR *)PvAllocSwImpl__Fi(&req);
        req.cb = pcrv->count * 0x10;
        req.cbAlign = 0x10;
        pcrv->vectors144 = (VECTOR *)PvAllocSwImpl__Fi(&req);
        for (index = 0; index < pcrv->count; index++)
            pbis->ReadVector(&pcrv->vectors140[index]);
        for (index = 0; index < pcrv->count; index++)
            pbis->ReadVector(&pcrv->vectors144[index]);
    }
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(pcrv, pbis);
    MeasureCrv(pcrv);
}
