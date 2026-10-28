#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct EP { float g; short fMin; short islot; };
struct PZ { char pad[0xFC]; int cslot; int cep; EP *aepX; EP *aepY; int *aslot; };
extern "C" {
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
}
void GrowPathzoneSlots(PZ *pz)
{
    int cslotOld = pz->cslot;
    int cslotNew;
    switch (cslotOld) {
    case 0x10: cslotNew = 0x80; break;
    case 0: cslotNew = 0x10; break;
    }
    int cbEp = cslotNew * 0x10 + 0x10;
    ALLOCREQ req;
    req.cb = cbEp;
    req.cbAlign = 0x10;
    EP *aepX = (EP *)PvAllocSwImpl__Fi(&req);
    req.cb = cbEp;
    req.cbAlign = 0x10;
    EP *aepY = (EP *)PvAllocSwImpl__Fi(&req);
    req.cb = cslotNew << 2;
    req.cbAlign = 0x10;
    int *aslot = (int *)PvAllocSwImpl__Fi(&req);
    CopyAb__FPvT0Ui(aepX, pz->aepX, pz->cep << 3);
    CopyAb__FPvT0Ui(aepY, pz->aepY, pz->cep << 3);
    CopyAb__FPvT0Ui(aslot, pz->aslot, pz->cslot << 2);
    int cslotCur = pz->cslot;
    memset((void *)((cslotCur << 2) + (int)aslot), 0, (cslotNew - cslotCur) << 2);
    pz->aepY = aepY;
    pz->aslot = aslot;
    pz->cslot = cslotNew;
    pz->aepX = aepX;
    if (pz->cep == 0) {
        aepX->g = -3.402823466e+38f;
        pz->aepX->fMin = 1;
        pz->aepX->islot = 0xFF;
        ((float *)pz->aepX)[2] = 3.402823466e+38f;
        ((short *)pz->aepX)[6] = 0;
        ((short *)pz->aepX)[7] = 0xFF;
        pz->aepY->g = -3.402823466e+38f;
        pz->aepY->fMin = 1;
        pz->aepY->islot = 0xFF;
        ((float *)pz->aepY)[2] = 3.402823466e+38f;
        ((short *)pz->aepY)[6] = 0;
        ((short *)pz->aepY)[7] = 0xFF;
        pz->cep = 2;
    }
}
