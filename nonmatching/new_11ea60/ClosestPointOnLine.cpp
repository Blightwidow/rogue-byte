#include "sly2.h"
/* lane 0 of a 128-bit value to an FP register (mtc1) */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* same, with the hazard nop retail has before the divide */
static inline float Lane0Nop(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
/* a float into lane 0 of a 128-bit general register (mfc1), to feed qmtc2 */
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void ClosestPointOnLine(QW pos, QW posA, QW posB, QW *pclosest, float *pu, float *pdist)
{
    QW numeratorBits, denominatorBits;
    QW junk;
    int f0, f1, f2;
    asm("qmtc2.ni %1, vf5" : "=r" (f0) : "r" (posA));
    asm("qmtc2.ni %1, vf1" : "=r" (f1) : "r" (posB), "r" (f0));
    asm("qmtc2.ni %1, vf7" : "=r" (f2) : "r" (pos), "r" (f1));
    asm("vsub.xyzw vf6, vf1, vf5\n\tvmove.xyzw vf1, vf6\n\tvsub.xyzw vf2, vf7, vf5\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "=r" (f0) : "r" (f2));
    asm("qmfc2.ni %0, vf2" : "=r" (numeratorBits) : "r" (f0));
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z" : "=r" (f1) : "r" (f0));
    float numerator = Lane0(numeratorBits);
    float denominator;
    asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (denominator), "=r" (denominatorBits) : "r" (f1));
    float u = numerator / denominator;
    if (pu != 0) {
        *pu = u;
    }
    if (pclosest != 0 || pdist != 0) {
        QW uBits = Word(u);
        asm("qmtc2.ni %1, vf1" : "=r" (f2) : "r" (uBits));
        asm("vadda.xyzw ACC, vf0, vf5\n\tvmaddx.xyzw vf2, vf6, vf1x" : "=r" (f0) : "r" (f2));
        asm("sqc2 vf1, %0" : "=m" (junk) : "r" (f0));
        if (pclosest != 0) {
            QW closest;
            asm("qmfc2.ni %0, vf2" : "=r" (closest) : "r" (f0));
            *pclosest = closest;
        }
        if (pdist != 0) {
            int distanceBits;
            asm("vsub.xyzw vf1, vf7, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (distanceBits) : "r" (f0));
            *(int *)pdist = distanceBits;
        }
    }
}
