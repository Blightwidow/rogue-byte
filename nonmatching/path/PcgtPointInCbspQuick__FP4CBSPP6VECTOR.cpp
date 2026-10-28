#include "sly2.h"
struct CBSP { CBSP *pbspNeg; CBSP *pbspPos; QW *pplane; };
extern "C" void *func_002564B8(void *);
extern "C" CBSP *PcgtPointInCbspQuick__FP4CBSPP6VECTOR(CBSP *pbsp, CBSP *pbspLimit, QW pos)
{
    struct L { QW a; QW b; QW pos; QW plane; } l;
    l.pos = pos;
    CBSP *next;
    if (!pbsp) return 0;
    for (;;) {
    asm("lqc2 vf1, %0" : : "m" (*pbsp->pplane));
    func_002564B8(&l.a);
    asm("sqc2 vf1, %0" : "=m" (l.plane));
    func_002564B8(&l.b);
    float dist;
    asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %0, vf1" : "=r" (dist) : "m" (l.plane), "m" (l.pos));
    asm("sqc2 vf2, %0" : "=m" (l.b));
    asm("sqc2 vf1, %0" : "=m" (l.a));
    if (dist < 0.0001f) {
    next = pbsp->pbspNeg;
    if (next >= pbspLimit) next = 0;
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
