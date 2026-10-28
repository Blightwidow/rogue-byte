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
    asm volatile("qmtc2.ni %0, vf2" : : "r" (pos));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r" (hitfx));
    asm volatile("vsub.xyzw vf2, vf2, vf1");
    asm volatile("sqc2 vf2, %0" : "=m" (slot));
    asm volatile("qmfc2.ni %0, vf2" : "=r" (offset));
    QW zlane;
    asm volatile("pextuw %0, $0, %1" : "=r" (zlane) : "r" (offset));
    float z;
    asm volatile("mtc1 %1, %0" : "=f" (z) : "r" (zlane));
    if (FCheckLm__FP2LMf((char *)hitfx->pparms + 0x58, z) == 0)
        return 0;
    asm volatile("lqc2 vf2, %0" : : "m" (slot));
    asm volatile("vmul.xy vf1, vf2, vf2");
    asm volatile("vaddy.x vf1, vf1, vf1y");
    asm volatile(".word 0x4A0103BD");
    asm volatile(".word 0x4A0003BF");
    asm volatile("vaddq.x vf1, vf0, Q");
    QW lenq;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (lenq));
    float length;
    asm volatile("mtc1 %1, %0" : "=f" (length) : "r" (lenq));
    int farther = HitFx_GIntensity(hitfx) < length;
    return farther ^ 1;
}
