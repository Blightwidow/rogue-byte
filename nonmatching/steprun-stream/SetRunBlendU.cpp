#include "sly2.h"
struct ALO;
struct RUNBL { ALO *palo; void *pasegbl; char pad[0x8]; float weight; char pad2[0x3C]; float u; int pblend1; };
extern "C" void ReblendAsegbl(void *);
extern "C" char *func_0020BB48(RUNBL *);
extern "C" QW CalculateBlrunV(RUNBL *);

void SetRunBlendU(RUNBL *prunbl, float u)
{
    QW tmp0 __attribute__((aligned(16)));
    QW tmp1 __attribute__((aligned(16)));
    if (prunbl->pblend1 == 0) {
        prunbl->u = 0.0f;
        prunbl->weight = 1.0f;
    } else {
        prunbl->u = u;
        prunbl->weight = 1.0f - u;
    }
    ReblendAsegbl(prunbl->pasegbl);
    ALO *palo = prunbl->palo;
    int svt = *(int *)(func_0020BB48(prunbl) + 0x40);
    asm("qmtc2.ni %2, vf2\n\tsqc2 vf2, %0\n\tsqc2 vf2, %1" : "=m" (tmp0), "=m" (tmp1) : "r" (svt));
    QW v = CalculateBlrunV(prunbl);
    float minus = -1.0f;
    asm("qmtc2.ni %0, vf4\n\tlqc2 vf2, %2\n\tqmtc2.ni %1, vf1" : : "r" (v), "r" (minus), "m" (tmp1));
    asm("vmulx.xyzw vf3, vf4, vf1x");
    asm("sqc2 vf1, %0" : "=m" (tmp0));
    asm("vmulx.xyzw vf2, vf3, vf2x");
    asm("sqc2 vf2, %0" : "=m" (*(QW *)((char *)palo + 0x190)));
}
