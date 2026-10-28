#include "sly2.h"
struct CAND { QW pos; float rad; float pad[3]; };
struct CANDS { QW posFrom; float radHeading; unsigned ccand; char pad18[8]; CAND acand[64]; QW posCand; };
struct LM;
extern LM RO_002A53C0;
extern LM RO_002A53C8;
extern "C" void DecomposeSphere(QW, float *, float *, float *);
extern "C" int FCheckLm__FP2LMf(LM *, float);
extern "C" float RadNormalize__Ff(float);
extern "C" int FAddSearchCand(CANDS *pcands)
{
    float rad, radElev, s;
    register QW v3 asm("vf3");
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1" : "=j" (v3) : "m" (pcands->posCand), "m" (pcands->posFrom));
    DecomposeSphere(v3, &rad, &radElev, &s);
    if (!FCheckLm__FP2LMf(&RO_002A53C0, s))
        return 0;
    if (!FCheckLm__FP2LMf(&RO_002A53C8, radElev))
        return 0;
    if (pcands->ccand >= 0x40)
        return 0;
    CAND *pcand = &pcands->acand[pcands->ccand++];
    pcand->pos = pcands->posCand;
    float radRel = RadNormalize__Ff(rad - pcands->radHeading);
    pcand->rad = radRel;
    float zero;
    asm("mtc1 $0, %0
	nop" : "=f" (zero));
    if (radRel < zero) {
        float twopi;
        asm("lui $1, 0x40C9
	ori $1, $1, 0xFDB
	mtc1 $1, %0
	nop" : "=f" (twopi) : : "$1");
        pcand->rad = twopi - radRel;
    }
    return 1;
}
