#include "sly2.h"
struct JT { char pad[0x240]; QW grab; char pad2[0x103C - 0x250]; int reach; int flip; };
extern "C" {
void GetPathPosFromS(float, void *, QW *, QW *);
float atan2f(float, float);
extern QW g_2a2dc0;
extern QW g_2a2da0;
}
extern "C" void AttachCrv_GetPosFromParam(float sArc, void *pcrv, JT *pjt, QW *ppos, float *pradHeading)
{
    QW pos;
    QW tangent;
    QW scratch;
    GetPathPosFromS(sArc, pcrv, &pos, &tangent);
    float length;
    QW *pfallback = &g_2a2da0;
    QW *pup = &g_2a2dc0;
    asm("lqc2 vf2, %0" : : "m" (tangent));
    float eps = 0.0001f;
    asm("lqc2 vf1, 0(%0)" : : "r" (pup));
    asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf3, vf1, vf2\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    QW fallback = *pfallback;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    int bits;
    asm("qmfc2.ni %0, vf1" : "=r" (bits));
    asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
    if (length < eps)
        asm("qmtc2.ni %0, vf1" : : "r" (fallback));
    else
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
    asm("vmove.xyzw vf4, vf1");
    if (ppos) {
        int reach = pjt->reach;
        asm("qmtc2.ni %0, vf1" : : "r" (reach));
        asm("lqc2 vf2, %0" : : "m" (pos));
        asm("lqc2 vf3, 0x240(%0)" : : "r" (pjt));
        asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf4, vf1x\n\tvsub.xyzw vf2, vf2, vf3");
        asm("sqc2 vf1, %0" : "=m" (scratch));
        asm("sqc2 vf2, 0(%0)" : : "r" (ppos) : "memory");
    }
    if (pradHeading) {
        QW side;
        if (pjt->flip == 1) {
            int bitsNeg;
            float negOne = -1.0f;
            asm("mfc1 %0, %1" : "=r" (bitsNeg) : "f" (negOne));
            asm("qmtc2.ni %0, vf1" : : "r" (bitsNeg));
            asm("sqc2 vf1, %0" : "=m" (scratch));
            asm("vmulx.xyzw vf4, vf4, vf1x");
        }
        register QW v4a asm("vf4");
        side = v4a;
        float x;
        float y;
        asm volatile("mtc1 %1, %0" : "=f" (x) : "r" (side));
        side = __builtin_prot3w(side);
        asm("mtc1 %1, %0" : "=f" (y) : "r" (side));
        *pradHeading = atan2f(y, x);
    }
}
