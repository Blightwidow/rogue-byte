#include "sly2.h"
struct XF { char pad[0x70]; QW row3; char pad2[0x90 - 0x80]; struct ACT *pactFirst; };
struct XFP { char pad[0x40]; QW r0; QW r1; QW r2; QW r3; };
struct LIMB { int pxfAnchor; XFP *pxfUpper; XFP *pxfLower; XFP *pxfEnd; char pad[0xB0 - 0x10]; QW effector; float sUpper; float sLower; };
struct ACT { int kind; char pad[0xC]; ACT *pnext; char pad2[8]; LIMB *plimb; };
struct ALO { char pad[0x50]; int cxf; char *paxf; char pad2[0x148 - 0x58]; unsigned long flags; };
extern "C" void RefreshAloIkLimbLengths(ALO *palo)
{
    if (palo->flags & 0x1000000000UL) {
        for (int ixf = 0; ixf < palo->cxf; ixf++) {
            XF *pxf = (XF *)(palo->paxf + ixf * 0x100);
            for (ACT *pact = pxf->pactFirst; pact; pact = pact->pnext) {
                if (pact->kind != 7)
                    continue;
                LIMB *plimb = pact->plimb;
                XFP *pend = plimb->pxfEnd;
                XFP *plower = plimb->pxfLower;
                QW *prow = &pend->r0;
                asm("lqc2 vf2, %0" : : "m" (pend->r0));
                asm("lqc2 vf4, %0" : : "m" (prow[2]));
                asm("lqc2 vf6, %0" : : "m" (prow[3]));
                asm("lqc2 vf5, %0" : : "m" (prow[1]));
                asm("lqc2 vf3, %0" : : "m" (plimb->effector));
                asm("lqc2 vf1, %0" : : "m" (plower->r3));
                asm("vmulax.xyz ACC, vf2, vf3x\n\tvmadday.xyz ACC, vf5, vf3y\n\tvmaddaz.xyz ACC, vf4, vf3z\n\tvmaddw.xyz vf2, vf6, vf0w");
                XFP *pupper = plimb->pxfUpper;
                asm("vsub.xyzw vf2, vf2, vf1\n\tvmul.xyz vf2, vf2, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z");
                asm("lqc2 vf3, %0" : : "m" (pupper->r3));
                asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
                asm("vsub.xyzw vf1, vf1, vf3");
                int bitsLower;
                asm volatile("qmfc2.ni %0, vf2" : "=r" (bitsLower));
                asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z");
                *(int *)&plimb->sLower = bitsLower;
                asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                int bitsUpper;
                asm volatile("qmfc2.ni %0, vf1" : "=r" (bitsUpper));
                *(int *)&plimb->sUpper = bitsUpper;
            }
        }
    }
}
