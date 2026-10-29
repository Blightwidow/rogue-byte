#include "m2c_macros.h"
extern "C" {

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M2C_UNK *, s128, s128); /* extern */
s128 ConvertAloPos(M2C_UNK, void *, s128);          /* extern */
M2C_UNK GetPathPosFromS(s32, void *, s128 *, f32);  /* extern */
M2C_UNK PmatLoWorld(void *);                        /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(s32, f32, f32, M2C_UNK); /* extern */
extern s128 g_2a2dc0;

void CalculateTnCrv(void *arg0, s128 arg1, s128 *arg2, s128 *arg3) {
    char sp[0x90];
    M2C_UNK sp40;
    M2C_UNK sp70;
    s128 spA0;
    f32 temp_f12;
    s32 temp_a0;

    spA0 = arg1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x10C);
    if (temp_a0 != 0) {
        GetPathPosFromS(temp_a0, sp, arg3, M2C_FIELD(arg0, f32 *, 0x140));
        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp40, *arg3, g_2a2dc0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($sp) */);
        goto block_4;
    }
    if (M2C_FIELD(arg0, s32 *, 0x12C) != 0) {
        temp_f12 = M2C_FIELD(arg0, f32 *, 0x160);
        SetVectorCylind__FP6VECTORfff(temp_a0, M2C_FIELD(arg0, f32 *, 0x140) / temp_f12, temp_f12, 0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x150($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf4 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf4, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf5, $vf2z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp70, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), g_2a2dc0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
block_4:
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf7, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf8, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf4, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf7, $vf7y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf8, $vf7z */);
        M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf6, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmaddz.y $vf1, $vf8, $vf6z */);
        M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf5, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmaddy.z $vf1, $vf8, $vf5y */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s2) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
        return;
    }
    PmatLoWorld(arg0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    *arg2 = ConvertAloPos(0, arg0, spA0);
}
}
