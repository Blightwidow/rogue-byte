#include "sly2.h"
extern "C" void AdjustStepXpVelocity(void *, void *, int);
extern "C" QW PosLoWorld(void *);
struct VT { char pad[0x110]; short delta; short index; QW (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vt; };
struct Side { char pad[0xC]; Obj *plo; QW contact; QW unk; QW velocity; };

void AdjustSlyXpVelocity(void *pjt, Side *pxp, int ixpd)
{
    struct { QW velocity; QW omega; QW contact; } frame;
    AdjustStepXpVelocity(pjt, pxp, ixpd);
    Side *pside = (Side *)((char *)pxp + ixpd * 0x40);
    Obj *plo = pside->plo;
    if (plo == pjt) {
        frame.velocity = pside->velocity;
        frame.omega = plo->vt->fn((char *)plo + plo->vt->delta);
        QW posWorld;
        asm volatile("" : "=r" (posWorld));
        frame.contact = pside->contact;
        posWorld = PosLoWorld(plo);
        asm volatile("lqc2 vf2, %0\n\tqmtc2.ni %1, vf3\n\tvsub.xyzw vf1, vf2, vf3" : : "m" (frame.contact), "r" (posWorld));
        asm volatile("lqc2 vf2, %0\n\tlqc2 vf3, %1\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2\n\tvsub.xyzw vf1, vf3, vf1\n\tsqc2 vf1, %2" : : "m" (frame.omega), "m" (frame.velocity), "m" (pside->velocity));
    }
}
