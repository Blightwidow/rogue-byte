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

/* every lane of `v` times 1 / lane x of `divisor`: vdiv writes Q (vf0w is 1.0), vwaitq waits for it, vmulq.xyzw multiplies by it. Q has no C
   form, so the three stay together, as in SqrtX; nothing in retail is scheduled inside the chain. The divisor is the second input
   operand in the C but the first in the asm, as in VectorScaleX: GCC then allocates retail's registers (the divisor in the lowest). A float goes in
   through VectorFromFloat or VectorFromWord. Retail users: BuildPlainBlend, AddLaserCustomXps, PresetTarmissAccel (near misses at 6, 67 and 46: the
   chain and its operand registers match; retail's result takes the vector's register, this one the divisor's, and "0" ties make it worse). */
static inline QW ScaleByReciprocalX(QW v, QW divisor)
{
    QW scaled;
    asm("vdiv $Q, $vf0w, %1x\n\tvwaitq\n\tvmulq.xyzw %0, %2, $Q" : "=j"(scaled) : "j"(divisor), "j"(v));
    return scaled;
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

/* vmax.xyz / vmini.xyz: per-lane maximum or minimum of x, y and z; lane w keeps the destination register's previous contents, so the result is
   only read through xyz. A box built from two points is a VectorMaxXyz and a VectorMiniXyz over them (FMatchJtXmg, CobstacleFindPathzoneBox,
   bevy_camera_follow_push_out) */
static inline QW VectorMaxXyz(QW first, QW second)
{
    QW maximum;
    asm("vmax.xyz %0, %1, %2" : "=j"(maximum) : "j"(first), "j"(second));
    return maximum;
}

static inline QW VectorMiniXyz(QW first, QW second)
{
    QW minimum;
    asm("vmini.xyz %0, %1, %2" : "=j"(minimum) : "j"(first), "j"(second));
    return minimum;
}

/* x*x' + y*y' + z*z' of two vectors in lane x: SquaredLength with two operands, the same four instructions through ACC (AddStepCustomXps,
   FillDzgDz, UpdateBombCustomXps, func_001B6DA8, func_0021BD18, func_001467A0). Read the result with LaneX, or VectorWordX for a store */
static inline QW DotProduct(QW first, QW second)
{
    QW products, one;
    asm("vmul.xyz %0, %2, %3\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(products), "=&j"(one) : "j"(first), "j"(second));
    return products;
}

/* the cross product of two vectors in xyz: vopmula.xyz fills ACC, vopmsub.xyz reads it, so the pair stays in one asm (Obstacle_SetConvexHull,
   func_001F6C08). The second operand is read by both instructions */
static inline QW CrossProduct(QW first, QW second)
{
    QW product;
    asm("vopmula.xyz $ACC, %1, %2\n\tvopmsub.xyz %0, %2, %1" : "=j"(product) : "j"(first), "j"(second));
    return product;
}

/* v rotated by three rows, no translation: vmulax.xyz, vmadday.xyz, vmaddz.xyz (TransformPoint is the four-row form that ends in vmaddaz and
   vmaddw). Rows come first so GCC allocates retail's registers (bevy_player_p25_1375d0, GoalAnim_FHandleMessage, ChooseEmitVelocity) */
static inline QW TransformVector(QW v, QW row0, QW row1, QW row2)
{
    QW out;
    asm("vmulax.xyz $ACC, %2, %1x\n\tvmadday.xyz $ACC, %3, %1y\n\tvmaddz.xyz %0, %4, %1z" : "=j"(out) : "j"(v), "j"(row0), "j"(row1), "j"(row2));
    return out;
}

/* a * scaleA.x + b * scaleB.x: vmulax.xyzw then vmaddx.xyzw through ACC, the two-scalar blend (SetRopeSimLength, PresetTarmissAccel); ScaleAddX is
   the form that adds onto vf0 */
static inline QW BlendX(QW scaleA, QW a, QW scaleB, QW b)
{
    QW sum;
    asm("vmulax.xyzw $ACC, %2, %1x\n\tvmaddx.xyzw %0, %4, %3x" : "=j"(sum) : "j"(scaleA), "j"(a), "j"(scaleB), "j"(b));
    return sum;
}

/* qmfc2.ni: lane x of a VU0 register as a 32-bit word in a general register, for a store (retail: qmfc2.ni then sw). A (u32) cast of a QW adds
   dsll32 and dsra32 (FillDzgDz, UpdateBombCustomXps, LoadJumpAnim) */
static inline u32 VectorWordX(QW v)
{
    u32 word;
    asm("qmfc2.ni %0, %1" : "=r"(word) : "j"(v));
    return word;
}

#endif
