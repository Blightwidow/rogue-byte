#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertAloPos(void *, void *, QW);
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (t)); return f; }

int FCheckJtCaneSide(char *pjt)
{
    struct { QW junk; QW localA; } frame;
    QW posPart = PosLoWorld(*(void **)(pjt + 0x19A4));
    frame.localA = ConvertAloPos(0, pjt, posPart);
    QW localB = ConvertAloPos(0, pjt, *(QW *)(*(char **)(pjt + 0x19C0) + 0x70));
    QW half;
    QW result;
    float zero = 0.0f;
    asm("qmtc2.ni %0, vf3" : : "r" (localB));
    asm volatile("lqc2 vf2, %0" : : "m" (frame.localA));
    asm volatile("mfc1 %0, %3\n\tqmtc2.ni %0, vf1\n\tvmulax.xyzw ACC, vf2, vf1x\n\tvmaddx.xyzw vf2, vf3, vf1x\n\tsqc2 vf1, %2\n\tqmfc2.ni %1, vf2" : "=&r" (half), "=r" (result), "=m" (frame.junk) : "f" (0.5f));
    return zero < LaneY(result);
}
