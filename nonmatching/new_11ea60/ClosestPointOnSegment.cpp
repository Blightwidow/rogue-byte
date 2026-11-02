#include "sly2.h"
/* lane 0 of a 128-bit value to an FP register (mtc1) */
static inline float Lane0(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* a float into lane 0 of a 128-bit general register (mfc1), to feed qmtc2 */
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void ClosestPointOnSegment(QW pos, QW posA, QW posB, QW *pclosest, float *pu, float *pdist)
{
    QW junk, numeratorBits, denominatorBits;
    int f0, f1, f2, f3;
    asm("qmtc2.ni %1, vf6" : "=r" (f0) : "r" (posA));
    float zero = 0.0f;
    asm("qmtc2.ni %1, vf1" : "=r" (f1) : "r" (posB), "r" (f0), "f" (zero));
    asm("vsub.xyzw vf5, vf1, vf6" : "=r" (f2) : "r" (f1));
    asm("qmtc2.ni %1, vf7" : "=r" (f3) : "r" (pos), "r" (f2));
    asm("vsub.xyzw vf1, vf7, vf6\n\tvmul.xyz vf2, vf5, vf5\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\tvmul.xyz vf1, vf1, vf5\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "=r" (f0) : "r" (f3));
    asm("qmfc2.ni %0, vf1" : "=r" (numeratorBits) : "r" (f0));
    float numerator = Lane0(numeratorBits);
    float denominator;
    asm volatile("qmfc2.ni %1, vf2\n\tmtc1 %1, %0\n\tnop" : "=f" (denominator), "=r" (numeratorBits) : "r" (f0));
    float u = numerator / denominator;
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
        asm("qmtc2.ni %1, vf1" : "=r" (f1) : "r" (uBits));
        asm("vadda.xyzw ACC, vf6, vf0\n\tvmaddx.xyzw vf2, vf5, vf1x" : "=r" (f2) : "r" (f1));
        asm("sqc2 vf1, %1" : "=r" (f3), "=m" (junk) : "r" (f2));
        QW closest;
        asm("qmfc2.ni %0, vf2" : "=r" (closest) : "r" (f3));
        if (pclosest != 0) {
            *pclosest = closest;
        }
        if (pdist != 0) {
            int distanceBits;
            asm("vsub.xyzw vf1, vf7, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (distanceBits) : "r" (f2));
            *(int *)pdist = distanceBits;
        }
    }
}
