#include "sly2.h"
struct CBSP { CBSP *pbspNeg; CBSP *pbspPos; QW *pplane; };
extern "C" void *func_002564B8(void *);
extern "C" CBSP *PcgtPointInCbsp(CBSP *pbsp, CBSP *pbspLimit, QW pos)
{
    QW a;
    QW b;
    QW plane;
    while (pbsp) {
        asm("lqc2 vf1, %0" : : "m" (*pbsp->pplane));
        func_002564B8(&a);
        asm("sqc2 vf1, %0" : "=m" (plane));
        func_002564B8(&b);
        float dist;
        asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %0, vf1" : "=r" (dist) : "m" (plane), "m" (pos));
        asm("sqc2 vf2, %0" : "=m" (b));
        asm("sqc2 vf1, %0" : "=m" (a));
        CBSP *next;
        if (dist < -0.0001f) {
            next = pbsp->pbspNeg;
            if (next >= pbspLimit) next = 0;
            if (!next) return pbsp;
            pbsp = next;
        } else if (dist > 0.0001f) {
            next = pbsp->pbspPos;
            if (next >= pbspLimit) next = 0;
            if (!next) return 0;
            pbsp = next;
        } else {
            next = pbsp->pbspPos;
            if (next >= pbspLimit) next = 0;
            if (next) {
                CBSP *found = PcgtPointInCbsp(next, pbspLimit, pos);
                if (found) return found;
            }
            next = pbsp->pbspNeg;
            if (next >= pbspLimit) next = 0;
            if (!next) return pbsp;
            pbsp = next;
        }
    }
    return 0;
}
