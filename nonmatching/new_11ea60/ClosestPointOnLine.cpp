#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void ClosestPointOnLine(QW pos, QW posA, QW posB, QW *pclosest, float *pu, float *pdist)
{
    float numerator, denominator;
    QW junk;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    asm("qmtc2.ni %0, vf5" : : "r" (posA));
    v1 = posB;
    register QW v7 asm("vf7") = pos;
    asm("vsub.xyzw vf6, vf1, vf5\n\tvmove.xyzw vf1, vf6\n\tvsub.xyzw vf2, vf7, vf5\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "=j" (v2) : "j" (v1), "j" (v7));
    asm("qmfc2.ni %0, vf2" : "=r" (numerator) : "j" (v2));
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z" : "=j" (v1));
    asm("qmfc2.ni %0, vf1" : "=r" (denominator) : "j" (v1));
    float u = numerator / denominator;
    if (pu != 0) {
        *pu = u;
    }
    if (pclosest != 0 || pdist != 0) {
        QW uBits = Word(u);
        asm("qmtc2.ni %0, vf1" : : "r" (uBits));
        asm("vadda.xyzw ACC, vf0, vf5\n\tvmaddx.xyzw vf2, vf6, vf1x" : "=j" (v2));
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
