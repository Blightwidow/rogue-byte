#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, M2C_UNK *);         /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(void *, f32 *, s128 *); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK MatMulMatTransMat(void *, s32, s32);        /* extern */
M2C_UNK SetTag__4CRef4TAGK(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

s32 RefOpMatrixInterpolateRotate(s32 arg0, void *arg2) {
    char sp[0x400];
    M2C_UNK sp44;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp30;
    M2C_UNK sp40;
    M2C_UNK sp80;
    f32 spE0;

    MatMulMatTransMat(sp, M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC));
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(sp, &spE0, &sp30);
    SetTag__4CRef4TAGK(&sp40, 0x1B);
    memset(sp44, 0, 0x40);
    M2C_FIELD(sp44, f32 *, 0) = 1.0f;
    M2C_FIELD(sp44, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(sp44, f32 *, 0x28) = 1.0f;
    M2C_FIELD(sp44, f32 *, 0x14) = 1.0f;
    LoadRotateMatrixRad(&sp80, sp30, spE0 * M2C_FIELD(arg2, f32 *, 0x14));
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf3, $vf5z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xd0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($s0) */);
    M2C_FIELD(sp44, s128 *, 0x10) = sp60;
    M2C_FIELD(sp44, s128 *, 0x20) = sp70;
    CRef_CopyConstruct(arg0, &sp40);
    CRef_Destruct(&sp40);
    return arg0;
}
