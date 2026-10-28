#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_001A5EE8(s32, s128 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F3C70();                            /* extern */
extern s128 g_2a2dc0;

void Swarm_Render(void *arg0) {
    M2C_UNK sp80;
    M2C_UNK sp90;
    M2C_UNK unksp3C;
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s32 sp4C;
    s32 sp5C;
    M2C_UNK sp60;
    s128 sp70;
    M2C_UNK spA0;
    f32 temp_f12;
    s32 var_v1;
    void *var_s0;

    func_001F3C70();
    if (M2C_FIELD(arg0, s32 *, 0x1C4) != 0) {
        var_v1 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
            do {
                var_s0 = M2C_FIELD(((var_v1 * 0x30) + arg0), void **, 0x1DC);
                if (var_s0 != NULL) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf7, ($s0) */);
loop_5:
                    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x100($sp) */);
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp70, M2C_FIELD(var_s0, s128 *, 0x10), g_2a2dc0);
                    sp0 = sp70;
                    sp10 = sp80;
                    sp20 = sp90;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x100($sp) */);
                    if (fabsf(M2C_FIELD(var_s0, f32 *, 0x50)) > 1.0f) {
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s3) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
                        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf1, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf7 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf7, $vf2, $vf3x */);
                    }
                    temp_f12 = M2C_FIELD(var_s0, f32 *, 0x54);
                    if (fabsf(temp_f12) > 0.01f) {
                        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x100($sp) */);
                        LoadRotateMatrixRad(&spA0, g_2a2dc0, temp_f12);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf3, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf3, $vf2z */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xc0($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf3, $vf4z */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xd0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xe0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xf0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x100($sp) */);
                    }
                    __as__6VECTORG9VU_VECTOR(&sp60, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */));
                    sp30 = sp0;
                    M2C_FIELD(&sp30, s128 *, 0x10) = sp10;
                    M2C_FIELD(&sp30, s128 *, 0x20) = sp20;
                    sp5C = 0;
                    sp4C = 0;
                    unksp3C = 0;
                    M2C_FIELD(&sp30, f32 *, 0x3C) = 1.0f;
                    func_001A5EE8(M2C_FIELD(arg0, s32 *, 0x1C4), &sp30, 0x3F800000, 0x3F800000);
                    var_s0 = M2C_FIELD(var_s0, void **, 0x60);
                    if (var_s0 != NULL) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf7, ($s0) */);
                        goto loop_5;
                    }
                }
                var_v1 += 1;
            } while (var_v1 < M2C_FIELD(arg0, s32 *, 0x1C8));
        }
    }
}
