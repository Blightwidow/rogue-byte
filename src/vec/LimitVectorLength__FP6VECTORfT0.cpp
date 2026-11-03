#include "sly2.h"
static inline float LaneNop(QW q) { float f; asm volatile("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" QW LimitVectorLength__FP6VECTORfT0(QW vec, float limit)
{
    QW junk;
    QW lengthBits;
    QW result;
    int fenceA, fenceB;
    asm("qmtc2.ni %1, vf3" : "=r" (fenceA) : "r" (vec));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceB) : "r" (fenceA));
    asm("qmfc2.ni %0, vf1" : "=r" (lengthBits) : "r" (fenceB));
    float length = LaneNop(lengthBits);
    asm("qmfc2.ni %0, vf3" : "=r" (result) : "r" (fenceB));
    if (limit < length) {
        QW scaleBits;
        asm("mfc1 %1, %2\n\tqmtc2.ni %1, vf1\n\tsqc2 vf1, %0\n\tvmulx.xyzw vf2, vf3, vf1x\n\tqmfc2.ni %1, vf2" : "=m" (junk), "=r" (result) : "f" (limit / length), "r" (fenceB));
    }
    return result;
}
