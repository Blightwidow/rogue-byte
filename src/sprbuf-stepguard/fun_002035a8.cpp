#include "sly2.h"
struct RECON { char pad0[0xE0]; float sRadiusFrustum; float sRadiusTarget; float gZoom; char pad1[0x08]; int idName; int idList; char pad2[0x08]; float sFadeLink; };
extern "C" void LoadXfmFromBrx(void *, void *);
extern "C" void func_002035A8(RECON *ptarget, void *pcbis)
{
    ptarget->sRadiusTarget = 0.0f;
    ptarget->sRadiusFrustum = 75.0f;
    ptarget->gZoom = 0.25f;
    ptarget->sFadeLink = 5000.0f;
    LoadXfmFromBrx(ptarget, pcbis);
    float zero;
    asm("mtc1 $0,%0\n\tnop" : "=f"(zero));
    float r = ptarget->sRadiusTarget;
    if (r == zero)
        ptarget->sRadiusTarget = ptarget->sRadiusFrustum;
    if (ptarget->idList == -2)
        ptarget->idList = ptarget->idName;
}
