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

#endif
