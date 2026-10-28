#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void ClosestPointOnSegment(QW pos, QW posA, QW posB, QW *pclosest, float *pu, float *pdist)
{
    float numerator, denominator;
    QW junk;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    asm("qmtc2.ni %0, vf6" : : "r" (posA));
    v1 = posB;
    register QW v5 asm("vf5");
    asm("vsub.xyzw vf5, vf1, vf6" : "=j" (v5) : "j" (v1));
    float zero = 0.0f;
    register QW v7 asm("vf7") = pos;
    asm("vsub.xyzw vf1, vf7, vf6\n\tvmul.xyz vf2, vf5, vf5\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\tvmul.xyz vf1, vf1, vf5\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "=j" (v2), "=j" (v1) : "j" (v5), "j" (v7));
    asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f" (numerator) : "j" (v1) : "$2");
    asm("qmfc2.ni $2, vf2\n\tmtc1 $2, %0\n\tnop" : "=f" (denominator) : "j" (v2) : "$2");
    float u = numerator / denominator;
    asm volatile("");
    float one = 1.0f;
    if (u < zero)
        u = zero;
    else if (one < u)
        u = one;
    if (pu != 0) {
        *pu = u;
    }
    if (pclosest != 0 || pdist != 0) {
        QW uBits = Word(u);
        asm("qmtc2.ni %0, vf1" : : "r" (uBits));
        asm("vadda.xyzw ACC, vf0, vf6\n\tvmaddx.xyzw vf2, vf5, vf1x" : "=j" (v2));
        asm("sqc2 vf1, %0" : "=m" (junk));
        if (pclosest != 0) {
            QW closest;
            asm("" : "=r" (closest) : "0" (v2));
            *pclosest = closest;
        }
        if (pdist != 0) {
            int distanceBits;
            asm("vsub.xyzw vf1, vf7, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (distanceBits));
            *(int *)pdist = distanceBits;
        }
    }
}
