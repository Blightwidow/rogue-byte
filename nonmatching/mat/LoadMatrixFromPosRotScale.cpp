#include "sly2.h"
struct Mat4 { QW row[4]; };
extern "C" Mat4 *LoadMatrixFromPosRotScale(Mat4 *out, QW pos, QW *rot, int *scale)
{
    float zero = 0.0f;
    float one = 1.0f;
    QW spill;
    int fence;
    asm("qmtc2.ni %2, vf2\n\tlqc2 vf1, %3\n\tvmulx.xyzw vf1, vf1, vf2x\n\tsqc2 vf1, %0" : "=m" (out->row[0]), "=r" (fence) : "r" (scale[0]), "m" (rot[0]));
    asm("lqc2 vf1, %2\n\tqmtc2.ni %3, vf3\n\tsqc2 vf2, %0\n\tvmulx.xyzw vf1, vf1, vf3x\n\tsqc2 vf1, %1" : "=m" (spill), "=m" (out->row[1]) : "m" (rot[1]), "r" (scale[1]), "r" (fence));
    int fence2;
    asm("lqc2 vf1, %2\n\tqmtc2.ni %3, vf2\n\tvmulx.xyzw vf1, vf1, vf2x" : "=r" (fence2) : "r" (fence), "m" (rot[2]), "r" (scale[2]));
    out->row[3] = pos;
    asm("sqc2 vf1, %0\n\tsqc2 vf3, %1" : "=m" (out->row[2]), "=m" (spill) : "r" (fence2));
    ((float *)out)[3] = zero;
    ((float *)out)[15] = one;
    asm("sqc2 vf2, %0" : "=m" (spill));
    ((float *)out)[11] = zero;
    ((float *)out)[7] = zero;
    return out;
}
