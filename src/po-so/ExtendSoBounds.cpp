#include "sly2.h"
struct OXA { QW vmin; QW vmax; QW center; float radius; };
struct SO { char pad[0xEC]; OXA *oxa; };
void ExtendSoBounds(SO *so, QW pos, float radius)
{
    int bits;
    float dist;
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (radius));
    asm("qmtc2.ni %0, vf2" : : "r" (pos));
    OXA *oxa = so->oxa;
    asm("pextlw %0, %0, %0\n\tpextlw %0, %0, %0" : "+r" (bits));
    asm("qmtc2.ni %0, vf3" : : "r" (bits));
    asm("lqc2 vf1, %0" : : "m" (oxa->vmin));
    asm("vsub.xyzw vf4, vf2, vf3\n\tvmini.xyz vf1, vf1, vf4\n\tvadd.xyzw vf3, vf2, vf3");
    asm("sqc2 vf1, %0" : "=m" (oxa->vmin));
    OXA *oxb = so->oxa;
    asm("lqc2 vf1, %0" : : "m" (oxb->vmax));
    asm("vmax.xyz vf1, vf1, vf3");
    asm("sqc2 vf1, %0" : "=m" (oxb->vmax));
    OXA *oxc = so->oxa;
    asm("lqc2 vf1, %0" : : "m" (oxc->center));
    asm("vsub.xyzw vf2, vf2, vf1");
    float old = oxc->radius;
    asm("vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
    asm("qmfc2.ni %0, vf2" : "=r" (dist));
    asm("mtc1 %1, %0\n\tnop" : "=f" (dist) : "r" (dist));
    if (old < dist) oxc->radius = dist;
}
