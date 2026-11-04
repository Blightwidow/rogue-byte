#include "m2c_macros.h"

s128 DecomposeRotateMatrixEuler(M2C_UNK *);         /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, M2C_UNK *);  /* extern */
M2C_UNK PredictAsegEffect(s32, void *, s32, s32, f32, M2C_UNK); /* extern */
f32 TFindAsegLabel__FP4ASEG3OID(s32, M2C_UNK);      /* extern */

void func_0018B348(void *arg0) {
    M2C_UNK sp30;
    M2C_UNK sp70;
    M2C_UNK spB0;
    M2C_UNK sp40;
    M2C_UNK sp80;
    M2C_UNK spC0;
    f32 temp_f0;
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1BC8);
    if (temp_a0 != 0) {
        temp_f0 = TFindAsegLabel__FP4ASEG3OID(temp_a0, 0x167);
        M2C_FIELD(arg0, f32 *, 0x1BD8) = temp_f0;
        PredictAsegEffect(M2C_FIELD(arg0, s32 *, 0x1BC8), arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x19A4), s32 *, 0x60), M2C_FIELD(arg0, s32 *, 0x60), temp_f0, 0);
        M2C_FIELD(arg0, s128 *, 0x1BE0) = sp30;
        PredictAsegEffect(M2C_FIELD(arg0, s32 *, 0x1BC8), arg0, M2C_FIELD(arg0, s32 *, 0x19CC), M2C_FIELD(arg0, s32 *, 0x60), M2C_FIELD(arg0, f32 *, 0x1BD8), 0);
        M2C_FIELD(arg0, s128 *, 0x1BF0) = sp70;
        PredictAsegEffect(M2C_FIELD(arg0, s32 *, 0x1BC8), arg0, M2C_FIELD(arg0, s32 *, 0x19C0), M2C_FIELD(arg0, s32 *, 0x60), M2C_FIELD(arg0, f32 *, 0x1BD8), 0);
        M2C_FIELD(arg0, s128 *, 0x1C00) = spB0;
        M2C_FIELD(arg0, s128 *, 0x1C10) = DecomposeRotateMatrixEuler(&sp80);
        InvertMatrix4Affine(&spC0, &sp80);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xd0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xe0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xf0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x1be0($s1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1c20($s1) */);
    }
}
