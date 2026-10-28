#include "sly2.h"
struct SO { char pad[0x218]; QW *ppos; int unk; float half; };
extern "C" QW *PmatLoWorld(SO *);
extern "C" QW PosLoWorld(SO *);
extern "C" const int D_002C3CC8[2][3];
void func_002057E8(SO *pso, QW (*out)[3])
{
    struct Frame { QW apos[5]; QW junk; QW base; QW rowx; QW rowy; } f;
    f.base = *pso->ppos;
    QW *pmat = PmatLoWorld(pso);
    f.rowx = pmat[0];
    QW *pmat2 = PmatLoWorld(pso);
    asm volatile("lqc2 vf4, %1\n\tsqc2 vf4, %0" : "=m" (f.rowy) : "m" (pmat2[1]));
    f.apos[0] = PosLoWorld(pso);
    float half = pso->half;
    int bits = *(int *)&half;
    asm("qmtc2.ni %0, vf1" : : "r" (bits));
    float nhalf = -half;
    int nbits = *(int *)&nhalf;
    asm("lqc2 vf4, %0" : : "m" (f.rowy));
    asm("vmulx.xyzw vf2, vf4, vf1x");
    asm("lqc2 vf6, %0" : : "m" (f.rowx));
    asm("qmtc2.ni %0, vf3" : : "r" (nbits));
    asm("sqc2 vf1, %0" : "=m" (f.junk));
    asm("vmulx.xyzw vf5, vf6, vf3x\n\tvmulx.xyzw vf1, vf6, vf1x");
    asm("lqc2 vf6, %0" : : "m" (f.base));
    asm("vmulx.xyzw vf4, vf4, vf3x\n\tvadd.xyzw vf4, vf6, vf4\n\tvadd.xyzw vf1, vf6, vf1\n\tvadd.xyzw vf2, vf6, vf2\n\tvadd.xyzw vf5, vf6, vf5");
    asm("sqc2 vf3, %0" : "=m" (f.junk));
    asm("sqc2 vf1, %0" : "=m" (f.apos[1]));
    asm("sqc2 vf2, %0" : "=m" (f.apos[2]));
    asm("sqc2 vf5, %0" : "=m" (f.apos[3]));
    asm("sqc2 vf4, %0" : "=m" (f.apos[4]));
    for (unsigned i = 0; i < 2; i++)
        for (unsigned j = 0; j < 3; j++)
            out[i][j] = f.apos[D_002C3CC8[i][j]];
}
