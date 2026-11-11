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

#endif
