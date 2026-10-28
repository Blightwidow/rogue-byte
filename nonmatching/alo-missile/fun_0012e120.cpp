#include "sly2.h"
struct XF { char pad[0xB0]; QW vecB0; QW vecC0; int unkD0; int pad2[3]; int unkE0; };
struct ACT { char pad[8]; XF *pxf; char pad2[0x14]; QW vec; };
extern "C" void ActivateAct(ACT *);
extern "C" QW g_2a2da0;

extern "C" void func_0012E120(ACT *pact)
{
    ActivateAct(pact);
    QW *pdefault = &g_2a2da0;
    pact->pxf->vecB0 = pact->vec;
    pact->pxf->vecC0 = pact->vec;
    float length;
    int token1, token2, token3;
    asm("qmtc2.ni %1, vf3" : "=r" (token1) : "r" (pact->pxf->vecC0));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (token2) : "r" (token1));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=r" (token3) : "r" (token2));
    register int bits asm("$2");
    asm("qmfc2.ni %0, vf2" : "=r" (bits) : "r" (token3));
    asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
    if (length < 0.0001f) {
        pact->pxf->vecC0 = *pdefault;
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q\n\tsqc2 vf1, %0" : "=m" (pact->pxf->vecC0) : "r" (token3));
    }
    int bits2;
    asm("qmfc2.ni %0, vf2" : "=r" (bits2) : "r" (token3));
    pact->pxf->unkD0 = bits2;
    pact->pxf->unkE0 = 0;
}
