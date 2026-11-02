#include "sly2.h"
struct CPDEFI { char pad[0x50]; } __attribute__((aligned(16)));
struct VT { char pad[0x190]; short delta; short index; void (*fn)(void *, float, CPDEFI *); };
struct SO { char pad[0xC]; VT *vt; };
struct CM { char pad[0x260]; SO *psoCpdefi; char pad2[0xC]; CPDEFI cpdefi; };
extern "C" QW CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(CM *, CPDEFI *);
void GetCmCpdefi(CM *cm, SO *so, float dt, CPDEFI *cpdefi)
{
    if (so == cm->psoCpdefi) {
        *cpdefi = cm->cpdefi;
    } else {
        so->vt->fn((short *)so + so->vt->delta, dt, cpdefi);
        QW adjust = CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(cm, cpdefi);
        asm("lqc2 vf1, 0x10(%0)" : : "r" (cpdefi));
        asm("qmtc2.ni %0, vf2" : : "r" (adjust));
        asm("vadd.xyzw vf1, vf1, vf2");
        asm("sqc2 vf1, 0x40(%0)" : : "r" (cpdefi));
    }
}
