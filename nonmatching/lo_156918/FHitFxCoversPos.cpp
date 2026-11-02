#include "sly2.h"
struct HITFX;
struct HITFXPARMS { char pad[0x58]; };
struct HITFX { char pad0[0x14]; HITFXPARMS *pparms; char pad1[0xC]; QW pos; };
extern "C" int FCheckLm__FP2LMf(void *, float);
extern "C" float HitFx_GIntensity(HITFX *);
int FHitFxCoversPos(HITFX *hitfx, QW pos)
{
    QW slot;
    QW offset;
    int fence1, fence2;
    asm("qmtc2.ni %1, vf2" : "=r" (fence1) : "r" (pos));
    asm("lqc2 vf1, 0x20(%1)" : "=r" (fence2) : "r" (hitfx), "r" (fence1));
    asm volatile("vsub.xyzw vf2, vf2, vf1" : : "r" (fence2));
    asm volatile("sqc2 vf2, %0" : "=m" (slot));
    asm volatile("qmfc2.ni %0, vf2" : "=r" (offset));
    QW zlane;
    asm("pextuw %0, $0, %1" : "=r" (zlane) : "r" (offset));
    float z;
    asm("mtc1 %1, %0" : "=f" (z) : "r" (zlane));
    if (FCheckLm__FP2LMf((char *)hitfx->pparms + 0x58, z) == 0)
        return 0;
    int fence3, fence4;
    asm("lqc2 vf2, %1" : "=r" (fence3) : "m" (slot));
    asm("vmul.xy vf1, vf2, vf2" : "=r" (fence4) : "r" (fence3));
    asm volatile("vaddy.x vf1, vf1, vf1y" : : "r" (fence4));
    asm volatile(".word 0x4A0103BD");
    asm volatile(".word 0x4A0003BF");
    asm volatile("vaddq.x vf1, vf0, Q");
    QW lenq;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (lenq));
    float length;
    asm("mtc1 %1, %0" : "=f" (length) : "r" (lenq));
    int farther = HitFx_GIntensity(hitfx) < length;
    return farther ^ 1;
}
