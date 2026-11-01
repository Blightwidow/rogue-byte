#include "sly2.h"
struct CBSP { CBSP *pbspNeg; CBSP *pbspPos; QW *pplane; };
struct Frame_119090 { QW a; QW b; QW pos; QW plane; };
extern "C" void *func_002564B8(void *);
static inline CBSP *Within(CBSP *pbsp, CBSP *pbspLimit)
{
    if (pbsp >= pbspLimit)
        pbsp = 0;
    return pbsp;
}
extern "C" CBSP *PcgtPointInCbsp(CBSP *pbsp, CBSP *pbspLimit, QW pos)
{
    Frame_119090 frame;
    frame.pos = pos;
    while (pbsp) {
        asm("lqc2 vf1, %0" : : "m" (*pbsp->pplane));
        func_002564B8(&frame.a);
        asm("sqc2 vf1, %0" : "=m" (frame.plane));
        func_002564B8(&frame.b);
        float dist;
        asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %0, vf1" : "=r" (dist) : "m" (frame.plane), "m" (frame.pos));
        asm("sqc2 vf2, %0" : "=m" (frame.b));
        asm("sqc2 vf1, %0" : "=m" (frame.a));
        CBSP *next;
        if (dist < -0.0001f) {
            next = Within(pbsp->pbspNeg, pbspLimit);
            if (!next) return pbsp;
            pbsp = next;
        } else if (dist > 0.0001f) {
            next = Within(pbsp->pbspPos, pbspLimit);
            if (!next) return 0;
            pbsp = next;
        } else {
            next = Within(pbsp->pbspPos, pbspLimit);
            if (next) {
                CBSP *found = PcgtPointInCbsp(next, pbspLimit, frame.pos);
                if (found) return found;
            }
            next = Within(pbsp->pbspNeg, pbspLimit);
            if (!next) return pbsp;
            pbsp = next;
        }
    }
    return 0;
}
