#include "sly2.h"
struct CBSP { CBSP *pbspNeg; CBSP *pbspPos; QW *pplane; };
extern "C" void *func_002564B8(void *);
/* lane 0 of a 128-bit value to an FP register */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline CBSP *PbspClip(CBSP *pbsp, CBSP *pbspLimit)
{
    if (pbsp >= pbspLimit) pbsp = 0;
    return pbsp;
}
extern "C" CBSP *PcgtPointInCbspQuick__FP4CBSPP6VECTOR(CBSP *pbsp, CBSP *pbspLimit, QW pos)
{
    struct L { QW a; QW b; } l;
    CBSP *next;
    if (!pbsp) return 0;
    for (;;) {
        QW plane = *pbsp->pplane;
        func_002564B8(&l.a);
        func_002564B8(&l.b);
        QW distance;
        QW one;
        asm("vmul.xyz %0, %2, %3\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddaz.x ACC, %1, %0z\n\tvmsubw.x %0, %1, %0w"
            : "=j"(distance), "=j"(one) : "j"(plane), "j"(pos));
        l.b = one;
        l.a = distance;
        if (Lane0(distance) < 0.0001f) {
            next = PbspClip(pbsp->pbspNeg, pbspLimit);
            if (!next) return pbsp;
            pbsp = next;
        } else {
            CBSP *child = pbsp->pbspPos;
            pbsp = 0;
            if (child < pbspLimit) pbsp = child;
            if (!pbsp) return 0;
        }
    }
}
