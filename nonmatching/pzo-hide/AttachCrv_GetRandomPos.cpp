#include "sly2.h"
extern "C" {
float SRandNearCrv(float, void *, float);
void GetPathPosFromS(float, void *, QW *, QW *);
float GRandInRange(float, float);
extern QW g_2a2dc0;
extern QW g_2a2da0;
extern float g_2be8b8;
extern float g_2be8bc;
}
extern "C" void AttachCrv_GetRandomPos(float sNear, void *pcrv, QW *ppos, QW *pnormal)
{
    struct { QW pos; QW tangent; QW scratch; QW side; QW saved; } l;
    float sArc = SRandNearCrv(sNear, pcrv, g_2be8b8);
    GetPathPosFromS(sArc, pcrv, &l.pos, &l.tangent);
    float length;
    QW *pup = &g_2a2dc0;
    asm("lqc2 vf2, %0" : : "m" (l.tangent));
    float eps = 0.0001f;
    asm("lqc2 vf1, %0" : : "m" (g_2a2dc0));
    asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf3, vf1, vf2\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    QW fallback = g_2a2da0;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    int bits;
    asm("qmfc2.ni %0, vf1" : "=r" (bits));
    asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
    if (length < eps) {
        l.side = fallback;
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q");
        asm("sqc2 vf2, %0" : "=m" (l.side));
    }
    float gRand = GRandInRange(0.0f, g_2be8bc);
    l.saved = l.pos;
    asm("qmtc2.ni %0, vf1" : : "r" (gRand));
    asm("lqc2 vf3, %0" : : "m" (l.saved));
    asm("lqc2 vf4, %0" : : "m" (l.side));
    asm("sqc2 vf1, %0" : "=m" (l.scratch));
    asm("vadda.xyzw ACC, vf3, vf0\n\tvmaddx.xyzw vf2, vf4, vf1x");
    asm("sqc2 vf2, 0(%0)" : : "r" (ppos) : "memory");
    *pnormal = *pup;
}
