#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(); /* extern */
M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(); /* extern */
M2C_UNK ProjectSoTransform();                 /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();  /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dc0;

void ProjectDprizeTransform(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK spC0;
    M2C_UNK spD0;
    s32 sp8;
    M2C_UNK sp10;
    M2C_UNK sp20;
    s128 sp30;
    M2C_UNK sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 spB0;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s2;
    void **var_s4;
    void **var_s5;
    void *temp_a0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s3;
    void *temp_s6;
    void *temp_v0;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    switch (temp_v1) {                              /* irregular */
    case 6:
        ProjectSoTransform();
        return;
    case 0:
    case 5:
        /* fallthrough */
    default:
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x180($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x180($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x170($s1) */);
        temp_s0 = M2C_FIELD(arg0, void **, 0x58);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x170($s1) */);
        __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
        M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s128 *, 0xB0) = (s128) M2C_FIELD(arg0, s128 *, 0x180);
        temp_v1_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v1_2;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xA4) = temp_v1_2;
        temp_v0 = M2C_FIELD(arg0, void **, 0x168);
        if (temp_v0 != NULL) {
            temp_s6 = M2C_FIELD(temp_v0, void **, 0x30);
            var_s5 = NULL;
            if (temp_s6 != NULL) {
                temp_s3 = M2C_FIELD(temp_s6, void **, 0x14);
                var_s2 = 0;
                var_s4 = NULL;
                if (M2C_FIELD(temp_s3, s32 *, 0x5C) > 0) {
loop_10:
                    temp_s0_2 = M2C_FIELD(temp_s3, s32 *, 0x60) + (var_s2 * 8);
                    temp_a1 = M2C_FIELD(temp_s0_2, s32 *, 0);
                    if ((temp_a1 & 0x40000000) && (((s32) (temp_a1 << 0xC) >> 0xC) == M2C_FIELD(arg0, s32 *, 0x18))) {
                        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                        temp_v0_2 = M2C_FIELD(temp_v1_3, s32 (**)(void *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x198), (s32) (temp_a1 * 4) >> 0x16);
                        if (temp_v0_2 != M2C_FIELD(arg0, void **, 0x58)) {
                            if (temp_v0_2 == M2C_FIELD(arg0, void **, 0x5C)) {
                                var_s4 = M2C_FIELD(temp_s0_2, void ***, 4);
                            }
                        } else {
                            var_s5 = M2C_FIELD(temp_s0_2, void ***, 4);
                        }
                        if ((var_s5 == NULL) || (var_s4 == NULL)) {
                            goto block_20;
                        }
                    } else {
block_20:
                        var_s2 += 1;
                        if (var_s2 < M2C_FIELD(temp_s3, s32 *, 0x5C)) {
                            goto loop_10;
                        }
                    }
                }
                if ((var_s5 != NULL) || (var_s4 != NULL)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($a0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($v0) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                    sp8 = 0;
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&spB0, sp0, g_2a2dc0);
                    sp50 = spB0;
                    sp60 = spC0;
                    sp70 = spD0;
                    if (var_s5 != NULL) {
                        temp_v1_4 = *var_s5;
                        M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK *, f32, f32), 0x1C)(var_s5 + M2C_FIELD(temp_v1_4, s16 *, 0x18), &sp10, &sp20, M2C_FIELD(temp_s6, f32 *, 0x1C), M2C_FIELD(temp_s6, f32 *, 0x40));
                        temp_s0_3 = M2C_FIELD(arg0, void **, 0x58);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf3z */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($s0) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
                        __as__6VECTORG9VU_VECTOR(temp_s0_3 + 0x30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
                        M2C_FIELD(temp_s0_3, f32 *, 0x3C) = 1.0f;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($v1) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
                        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf3 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($v1) */);
                        temp_v0_3 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_3;
                        M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xA4) = temp_v0_3;
                    }
                    if (var_s4 != NULL) {
                        temp_v1_5 = *var_s4;
                        M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, s128 *, M2C_UNK *, f32, f32), 0x1C)(var_s4 + M2C_FIELD(temp_v1_5, s16 *, 0x18), &sp30, &sp40, M2C_FIELD(temp_s6, f32 *, 0x1C), M2C_FIELD(temp_s6, f32 *, 0x40));
                        LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&spB0, sp30);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xc0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xd0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf8x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf8y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf8z */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf7, $vf1, $vf6z */);
                        temp_a0 = M2C_FIELD(arg0, void **, 0x5C);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf5z */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0xd0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xe0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xf0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x80($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xa0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x100($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a0) */);
                        M2C_FIELD(temp_a0, s128 *, 0x10) = spC0;
                        M2C_FIELD(temp_a0, s32 *, 0xC) = 0;
                        M2C_FIELD(temp_a0, s128 *, 0x20) = spD0;
                        M2C_FIELD(temp_a0, s32 *, 0x2C) = 0;
                        M2C_FIELD(temp_a0, s32 *, 0x1C) = 0;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf2z */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xb0($v1) */);
                        temp_v0_4 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
                        M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_4;
                        M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0xA4) = temp_v0_4;
                    }
                }
            }
        }
        ProjectSoTransform(arg0);
        return;
    }
}
