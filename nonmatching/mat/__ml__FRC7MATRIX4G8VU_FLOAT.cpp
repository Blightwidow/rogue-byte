#include "sly2.h"
struct M4 { QW row[4]; };
extern "C" M4 __ml__FRC7MATRIX4G8VU_FLOAT(const M4 &m, QW scale) return res
{
    asm("lqc2 vf2, %0" : : "m" (m.row[0]));
    asm("qmtc2.ni %1, vf3\n\tvmulx.xyzw vf2, vf2, vf3x\n\tsqc2 vf2, %0" : "=m" (res.row[0]) : "r" (scale));
    asm("lqc2 vf1, %1\n\tvmulx.xyzw vf1, vf1, vf3x\n\tsqc2 vf1, %0" : "=m" (res.row[1]) : "m" (m.row[1]));
    asm("lqc2 vf2, %1\n\tvmulx.xyzw vf2, vf2, vf3x\n\tsqc2 vf2, %0" : "=m" (res.row[2]) : "m" (m.row[2]));
    asm("lqc2 vf1, %1\n\tvmulx.xyzw vf3, vf1, vf3x\n\tsqc2 vf3, %0" : "=m" (res.row[3]) : "m" (m.row[3]));
}
