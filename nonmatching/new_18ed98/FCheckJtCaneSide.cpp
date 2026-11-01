#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertAloPos(int, void *);
// lane 1 of a QW into an FP register: prot3w rotates lane 1 down to lane 0, mtc1 reads it (+ hazard nop)
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (t)); return f; }

int FCheckJtCaneSide(char *pjt)
{
    struct { QW junk; QW localA; } frame;
    QW posPart = PosLoWorld(*(void **)(pjt + 0x19A4));
    QW localA = ConvertAloPos(0, pjt);
    QW *pq = (QW *)(*(char **)(pjt + 0x19C0) + 0x70);
    frame.localA = localA;
    QW localB = ConvertAloPos(0, pjt);
    float zero = 0.0f;
    float half = 0.5f;
    asm("qmtc2.ni %0, vf3" : : "r" (localB));
    asm("lqc2 vf2, %0" : : "m" (frame.localA));
    asm("qmtc2.ni %0, vf1" : : "r" (half));
    asm("vmulax.xyzw ACC, vf2, vf1x\n\tvmaddx.xyzw vf2, vf3, vf1x");
    asm("sqc2 vf1, %0" : "=m" (frame.junk));
    QW result;
    asm("qmfc2.ni %0, vf2" : "=r" (result));
    float y = LaneY(result);
    int r = 0;
    if (zero < y) r = 1;
    return r;
}
