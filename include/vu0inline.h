/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Shared helpers for VU0 macro instructions (ruled 2026-11-11, docs/build/inline-asm-helpers.md; the rules of include/ps2inline.h
   apply). Their "j" operands are VU0 registers, which GCC only allocates with the VU0 flag (config/us/vu0_regs.txt, docs/build/vu0-mmi.md):
   a function that uses them is listed there. GCC then emits the lqc2/sqc2 moves itself. C and C++. */
#ifndef SLY2_VU0INLINE_H
#define SLY2_VU0INLINE_H
#include "types.h"

/* vadd.xyzw: the lane-wise sum of two quadwords */
static inline QW VectorAdd(QW first, QW second)
{
    QW sum;
    asm("vadd.xyzw %0, %1, %2" : "=j"(sum) : "j"(first), "j"(second));
    return sum;
}

/* vsub.xyzw: the lane-wise difference */
static inline QW VectorSub(QW first, QW second)
{
    QW difference;
    asm("vsub.xyzw %0, %1, %2" : "=j"(difference) : "j"(first), "j"(second));
    return difference;
}

/* x*x + y*y + z*z in lane x. One helper, not four: vadday.x and vmaddz.x go through VU0's accumulator (ACC), which C cannot name, and
   vaddw.x builds the 1.0 the last step multiplies by (vf0 is 0,0,0,1). Retail: vmul.xyz v,v,v; vaddw.x one,vf0,vf0w; vadday.x ACC,v,vy;
   vmaddz.x v,one,vz. Read the result with LaneX (include/ps2inline.h). */
static inline QW SquaredLength(QW v)
{
    QW one;
    asm("vmul.xyz %0, %0, %0\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "+j"(v), "=&j"(one));
    return v;
}

/* the square root of lane x, in lane x: vsqrt writes Q, vwaitq waits for it, vaddq.x copies it out (Q, like ACC, has no C form, so the
   three stay together). With SquaredLength and LaneX it is the distance between two points (BuildJtTargetList, WakeSoWater) */
static inline QW SqrtX(QW v)
{
    QW root;
    asm("vsqrt $Q, %1x\n\tvwaitq\n\tvaddq.x %0, $vf0, $Q" : "=j"(root) : "j"(v));
    return root;
}

/* vmulx.xyzw: every lane of `v` times lane x of `s` (s from VectorFromFloat or QuadFromFloat for a float). The scale is the first
   input operand, as GCC then allocates retail's registers (RefOpDiv) */
static inline QW VectorScaleX(QW v, QW s)
{
    QW scaled;
    asm("vmulx.xyzw %0, %2, %1x" : "=j"(scaled) : "j"(s), "j"(v));
    return scaled;
}

/* qmtc2.ni: a float's bits into lane x of a VU0 register; GCC moves the float to a general register itself (mfc1) first
   (RefOpDiv, UpdateWipe) */
static inline QW VectorFromFloat(float value)
{
    QW quad;
    asm("qmtc2.ni %1, %0" : "=j"(quad) : "r"(value));
    return quad;
}

#endif
