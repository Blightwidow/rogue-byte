#include "m2c_macros.h"

M2C_UNK ConvertCmScreenToWorld();    /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(); /* extern */
M2C_UNK FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(); /* extern */
M2C_UNK LoadRotateMatrixRad(); /* extern */
M2C_UNK MatMulMatTransMat();     /* extern */
extern M2C_UNK B_002DDF40;
extern f32 g_2dded0;

void RenderSmack(void *arg0) {
    char sp[0x400];
    M2C_UNK spE0;
    M2C_UNK spF0;
    M2C_UNK sp90;
    s128 spC0;
    s128 spD0;
    f32 sp160;
    f32 temp_f20;

    ConvertCmScreenToWorld(&B_002DDF40, M2C_FIELD(arg0, s128 *, 0x100));
    M2C_ERROR(/* unknown instruction: por $s4, $zero, $v0 */);
    MatMulMatTransMat(&spD0, arg0 + 0x40, &B_002DDF40 + 0x60);
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(sp, &sp160, &spC0, spD0, spD0, spE0, spF0);
    temp_f20 = (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x14)) / M2C_FIELD(arg0, f32 *, 0x18);
    LoadRotateMatrixRad(&spD0, spC0, sp160 * temp_f20);
    LoadRotateMatrixRad(&spD0, M2C_FIELD(M2C_FIELD(arg0, void **, 0xF0), s128 *, 0x40), 2.0f * temp_f20 * 3.1415927f, spD0, spE0, spF0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf9, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0xf0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf7x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf7y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf7z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf9x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf9y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf9z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf8x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf8y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf8z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($s1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf5, $vf6z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s3) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf5, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x130($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x140($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x150($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf9, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x130($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x140($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xe0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x150($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xf0($sp) */);
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s4 */), &sp90);
}
