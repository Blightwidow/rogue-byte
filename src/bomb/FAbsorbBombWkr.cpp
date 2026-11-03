#include "sly2.h"
struct BOMB;
extern "C" int FAbsorbSoWkr(BOMB *, int *);
extern "C" QW PosLoWorld(BOMB *);
extern "C" void PrepareBombDetonation(BOMB *, QW, QW);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void PrimeBomb__FP4BOMBf(BOMB *, float);
extern QW g_2a2dc0;
static inline void NormalizeSafe(QW *presult, QW *pvec, QW def)
{
    QW vec = *pvec;
    QW square;
    QW one;
    QW length4;
    float length;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j" (square), "=j" (one) : "j" (vec));
    float limit = 0.0001f;
    asm("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "=j" (length4) : "j" (square));
    asm("qmfc2.ni %0, %1" : "=r" (length) : "j" (length4));
    if (length < limit) {
        length4 = def;
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, %0x\n\tvwaitq\n\tvmulq.xyzw %0, %1, Q" : "+j" (length4) : "j" (vec));
    }
    *presult = length4;
}
extern "C" int FAbsorbBombWkr(BOMB *pbomb, int *pwkr)
{
    if (*(int *)((char *)pbomb + 0x150) == 1)
        return 0;
    int fAbsorbed = FAbsorbSoWkr(pbomb, pwkr);
    if (fAbsorbed != 0) {
        if (pwkr[0x11] & 8) {
            QW normal;
            NormalizeSafe(&normal, (QW *)&pwkr[0xC], g_2a2dc0);
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
