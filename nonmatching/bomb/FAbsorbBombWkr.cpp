#include "sly2.h"
struct BOMB;
extern "C" int FAbsorbSoWkr(BOMB *, int *);
extern "C" QW PosLoWorld(BOMB *);
extern "C" void PrepareBombDetonation(BOMB *, QW, QW);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void PrimeBomb__FP4BOMBf(BOMB *, float);
extern QW g_2a2dc0;
extern "C" int FAbsorbBombWkr(BOMB *pbomb, int *pwkr)
{
    if (*(int *)((char *)pbomb + 0x150) == 1)
        return 0;
    int fAbsorbed = FAbsorbSoWkr(pbomb, pwkr);
    if (fAbsorbed != 0) {
        if (pwkr[0x11] & 8) {
            QW normal;
            QW *pnormal = &normal;
            QW def = g_2a2dc0;
            float length;
            asm("lqc2 vf3, %0" : : "m" (pwkr[0xC]));
            asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            float limit = 0.0001f;
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
            asm("qmfc2.ni %0, vf1" : "=r" (length));
            if (length < limit) {
                asm("qmtc2.ni %0, vf1" : : "r" (def));
            } else {
                asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
            }
            asm("sqc2 vf1, 0(%0)" : : "r" (pnormal) : "memory");
            PrepareBombDetonation(pbomb, PosLoWorld(pbomb), normal);
            if (FIsBasicDerivedFrom(*(void **)pwkr, 0x4F)) {
                PrimeBomb__FP4BOMBf(pbomb, 0.25f);
                return fAbsorbed;
            }
            PrimeBomb__FP4BOMBf(pbomb, 0.0f);
        }
    }
    return fAbsorbed;
}
