#include "sly2.h"
struct JT { char pad[0x240]; QW grab; char pad2[0x103C - 0x250]; int reach; int flip; };
extern "C" {
void GetPathPosFromS(float, void *, QW *, QW *);
float atan2f(float, float);
extern QW g_2a2dc0;
extern QW g_2a2da0;
}
// lane 0 of a QW into an FP register (mtc1 reads the low word)
static inline float LaneX(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
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
    asm("vopmula.xyz ACC, vf2, vf1");
    asm("vopmsub.xyz vf3, vf1, vf2");
    asm("vmul.xyz vf1, vf3, vf3");
    asm("vaddw.x vf2, vf0, vf0w");
    asm("vadday.x ACC, vf1, vf1y");
    asm("vmaddz.x vf1, vf2, vf1z");
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
            float negOne = -1.0f;
            asm volatile("nop" : "+f" (negOne));
            asm("qmtc2.ni %0, vf1" : : "r" (negOne));
            asm("sqc2 vf1, %0" : "=m" (scratch));
            asm("vmulx.xyzw vf4, vf4, vf1x");
        }
        asm volatile("qmfc2.ni %0, vf4" : "=r" (side));
        float x = LaneX(side);
        side = __builtin_prot3w(side);
        float y = LaneX(side);
        *pradHeading = atan2f(y, x);
    }
}
