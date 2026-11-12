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
   vaddw.x builds the 1.0 the last step multiplies by (vf0 is 0,0,0,1). Retail: vmul.xyz r,v,v; vaddw.x one,vf0,vf0w; vadday.x ACC,r,ry;
   vmaddz.x r,one,rz. `v` is an input only: r is v's register when v dies there (BuildJtTargetList, CloneCloth), another one when v is
   still needed, as when it is then normalized (GoalBrain_FHandleMessage). Read the result with LaneX (include/ps2inline.h). */
static inline QW SquaredLength(QW v)
{
    QW squares, one;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(squares), "=&j"(one) : "j"(v));
    return squares;
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

/* vmul.xy: lanes x and y of `first` times those of `second`; lanes z and w of the result are not written. With SumXyInX and SqrtX it
   is the distance in the xy plane (FSeqnodeRecordDone, GoalGoto_Replan, func_00173A68, AdjustSlyNewXp) */
static inline QW VectorMultiplyXy(QW first, QW second)
{
    QW product;
    asm("vmul.xy %0, %1, %2" : "=j"(product) : "j"(first), "j"(second));
    return product;
}

/* vaddy.x: lane x plus lane y, in lane x; the other lanes of the result are not written */
static inline QW SumXyInX(QW v)
{
    QW sum;
    asm("vaddy.x %0, %1, %1y" : "=j"(sum) : "j"(v));
    return sum;
}

/* vmul.xy then vaddy.x: x*x + y*y in lane x, the squared length in the xy plane. A pair without ACC or Q between them, allowed as one
   helper by ruling (Theo, 2026-11-12): retail has the two instructions adjacent in all four users (FSeqnodeRecordDone, GoalGoto_Replan,
   func_00173A68, AdjustSlyNewXp), and as two helpers GCC schedules a load between them (AdjustSlyNewXp: 7 with the pair split, 0
   with this). Lanes y, z and w of the result are not meaningful. */
static inline QW SquaredLengthXy(QW v)
{
    QW squared;
    asm("vmul.xy %0, %1, %1\n\tvaddy.x %0, %0, %0y" : "=j"(squared) : "j"(v));
    return squared;
}

/* Accumulator chains. ACC (like Q) has no C form and cannot be an asm operand, so a chain of instructions that writes ACC (vmula,
   vadda, vmadda) stays in one helper together with the instruction that reads ACC into a VU0 register (vmadd), as SquaredLength does:
   no ACC value crosses a helper boundary. Each helper is one operation of retail's vector code, never one function's sequence. */

/* a point through a 4x3 matrix given as rows: row0 * v.x + row1 * v.y + row2 * v.z + row3 in xyz (vmulax, vmadday, vmaddaz through
   ACC, then vmaddw with vf0's w = 1). Lane w of the result is not written: it keeps what its register held (GCC's choice, as in
   retail, where it is a new register, or that of v or of a row whose value dies there). func_00169198, func_001CC5E8, BuildLaserBeams */
static inline QW TransformPoint(QW v, QW row0, QW row1, QW row2, QW row3)
{
    QW point;
    asm("vmulax.xyz $ACC, %2, %1x\n\tvmadday.xyz $ACC, %3, %1y\n\tvmaddaz.xyz $ACC, %4, %1z\n\tvmaddw.xyz %0, %5, $vf0w"
        : "=j"(point)
        : "j"(v), "j"(row0), "j"(row1), "j"(row2), "j"(row3));
    return point;
}

/* a + b * s.x in every lane: vadda.xyzw puts vf0 + a in ACC, vmaddx.xyzw adds b * s.x. As vf0 is (0, 0, 0, 1), lane w also gains 1.
   The vadda operands are written a, vf0: ps2eeas encodes that text as retail's vadda ACC, vf0, a (StartNextSeqnodeRecord,
   GoalBrain_FHandleMessage, SetJtState) */
static inline QW ScaleAddX(QW a, QW b, QW s)
{
    QW sum;
    asm("vadda.xyzw $ACC, %1, $vf0\n\tvmaddx.xyzw %0, %2, %3x" : "=j"(sum) : "j"(a), "j"(b), "j"(s));
    return sum;
}

/* qmtc2.ni: a float's bits into lane x of a VU0 register; GCC moves the float to a general register itself (mfc1) first
   (RefOpDiv, UpdateWipe) */
static inline QW VectorFromFloat(float value)
{
    QW quad;
    asm("qmtc2.ni %1, %0" : "=j"(quad) : "r"(value));
    return quad;
}

/* qmtc2.ni from a 32-bit word: retail loads a float with lw straight into a general register and moves it to lane x
   (VectorFromWord(*(u32 *)&value)), where VectorFromFloat gives lwc1 and mfc1 (StartNextSeqnodeRecord, GoalAnimLeap_SetState) */
static inline QW VectorFromWord(u32 word)
{
    QW quad;
    asm("qmtc2.ni %1, %0" : "=j"(quad) : "r"(word));
    return quad;
}

#endif
