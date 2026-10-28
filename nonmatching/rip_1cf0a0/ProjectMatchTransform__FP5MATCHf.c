#include "m2c_macros.h"

M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, M2C_UNK); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK PredictXfTransform(s32, M2C_UNK, void *, M2C_UNK, f32); /* extern */
extern M2C_UNK g_2dded0;

void ProjectMatchTransform__FP5MATCHf(void *arg0) {
    char sp[0x400];
    M2C_UNK sp80;
    f32 temp_f20;

    if (!(M2C_FIELD(&g_2dded0, f32 *, 0) < M2C_FIELD(arg0, f32 *, 0x14))) {
        M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
        temp_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f20, $f0 */);
        PredictXfTransform(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0x60), 0, sp, 0, temp_f20);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf7x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf8, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf8, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x70($sp) */);
        EvaluateBezierPos__FfffP6VECTORN63(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf8 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf8 */), temp_f20, M2C_FIELD(&g_2dded0, f32 *, 4), 0x3F800000);
        LoadRotateMatrixRad(&sp80, M2C_FIELD(arg0, s128 *, 0xF0), (M2C_FIELD(arg0, f32 *, 0x100) * temp_f20) / M2C_FIELD(arg0, f32 *, 0x18));
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf6, $vf1z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf6, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf6, $vf3z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xd0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
    }
}
