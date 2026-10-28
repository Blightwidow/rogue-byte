#include "sly2.h"
extern QW g_2a2dc0;
struct EMITDV { QW acc; QW axis; float curl; float damp; };
struct EMITB { char pad0[0x58]; float damp; char pad1[4]; QW acc; QW axis; float curl; };

void SetEmitdvEmitb(EMITDV *pemitdv, EMITB *pemitb)
{
    QW *pfb = &g_2a2dc0;
    float eps = 0.0001f;
    pemitdv->acc = pemitb->acc;
    QW *pout = &pemitdv->axis;
    int bits;
    asm("lqc2 vf3, %0" : : "m" (pemitb->axis));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    QW fallback = *pfb;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    asm("qmfc2.ni %0, vf1" : "=r" (bits));
    float length = *(float *)&bits;
    if (length < eps) {
        asm("qmtc2.ni %0, vf1" : : "r" (fallback));
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
    }
    asm("sqc2 vf1, %0" : "=m" (*pout));
    pemitdv->curl = pemitb->curl;
    pemitdv->damp = pemitb->damp;
}
