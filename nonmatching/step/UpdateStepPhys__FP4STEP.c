#include "m2c_macros.h"

f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, M2C_UNK *, s32); /* extern */
extern M2C_UNK D_002C3C68;
extern M2C_UNK g_2dded0;

void UpdateStepPhys__FP4STEP(void *arg0) {
    f32 sp40;
    s128 sp50;
    M2C_UNK sp90;
    f32 *spD0;
    f32 *var_s0;
    f32 *var_s1;
    f32 *var_s2;
    f32 *var_s3;
    f32 *var_s4;
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    s32 var_a0;
    s32 var_s3_2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x258);
    if (temp_v1 != NULL) {
        if (M2C_FIELD(arg0, void **, 0x25C) != NULL) {
            var_s3 = M2C_FIELD(temp_v1, f32 **, 0x7C);
            var_s4 = *M2C_FIELD(temp_v1, f32 ***, 0x10);
            InvertMatrix4Affine(&sp90, M2C_FIELD(temp_v1, s32 *, 0) + 0x40);
            __ml__FRC7MATRIX4T0(&sp50, &sp90, M2C_FIELD(M2C_FIELD(arg0, void **, 0x25C), s32 *, 0) + 0x40);
            var_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x25C), s32 *, 0x1C) - 1;
            if (var_a0 >= 0) {
                spD0 = &sp40;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s2) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                    var_s2 = var_s4;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
                    var_s1 = var_s3;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
                    var_s0 = spD0;
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
                    var_s4 += 0x10;
                    var_s3_2 = 2;
loop_5:
                    temp_f13 = *var_s0;
                    var_s0 += 4;
                    var_s3_2 -= 1;
                    temp_f0 = GSmooth__FfffP3SMPPf(&D_002C3C68, 0, *var_s1, temp_f13, M2C_FIELD(&g_2dded0, f32 *, 4));
                    temp_f1 = *var_s1;
                    var_s1 += 4;
                    *var_s2 = (temp_f0 - temp_f1) / M2C_FIELD(&g_2dded0, f32 *, 4);
                    var_s2 += 4;
                    if (var_s3_2 >= 0) {
                        goto loop_5;
                    }
                    var_a0 -= 1;
                    var_s3 += 0x10;
                } while (var_a0 >= 0);
            }
        }
    }
}
