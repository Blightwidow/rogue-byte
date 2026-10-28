#include "sly2.h"
struct DL;
extern "C" void *PvAllocStackImpl__Fi(void *);
extern "C" void *PvAllocStackClearImpl__Fi(void *);
extern "C" void InitDl__FP2DLi(void *, int);
struct DZG { int cdzMax; int cdzPos; void *adz; char dl[4][12]; int cdz; void *aagPos; void *aagPosCrout; void *asdv; void *adsfPos; };
extern "C" DZG *func_0011A550(DZG *pdzg, int cdzMax)
{
    int req[2];
    pdzg->cdzMax = cdzMax;
    pdzg->cdz = 0;
    pdzg->cdzPos = 0;
    req[0] = cdzMax * 0x28;
    req[1] = 0x10;
    pdzg->adz = PvAllocStackClearImpl__Fi(req);
    memset(pdzg->dl[0], 0, 0xC);
    memset(pdzg->dl[1], 0, 0xC);
    memset(pdzg->dl[2], 0, 0xC);
    memset(pdzg->dl[3], 0, 0xC);
    InitDl__FP2DLi(pdzg->dl[0], 0x20);
    InitDl__FP2DLi(pdzg->dl[1], 0x20);
    InitDl__FP2DLi(pdzg->dl[2], 0x20);
    InitDl__FP2DLi(pdzg->dl[3], 0x20);
    int cbMatrix = cdzMax * cdzMax * 4;
    req[0] = cbMatrix;
    req[1] = 0x10;
    pdzg->aagPos = PvAllocStackImpl__Fi(req);
    req[0] = cbMatrix;
    req[1] = 0x10;
    pdzg->aagPosCrout = PvAllocStackImpl__Fi(req);
    int cbVector = cdzMax << 2;
    req[0] = cbVector;
    req[1] = 0x10;
    pdzg->asdv = PvAllocStackImpl__Fi(req);
    req[0] = cbVector;
    req[1] = 0x10;
    pdzg->adsfPos = PvAllocStackImpl__Fi(req);
    return pdzg;
}
