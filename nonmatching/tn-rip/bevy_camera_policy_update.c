#include "m2c_macros.h"

M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(s128 *, M2C_UNK, void *, void *); /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
M2C_UNK SetCmPosMat(M2C_UNK *, s128 *, s128);       /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);  /* extern */
extern M2C_UNK B_002DDF40;
extern f32 g_2dded0;

void bevy_camera_policy_update(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK sp90;
    M2C_UNK spA0;
    M2C_UNK unksp2C;
    s128 sp20;
    s32 sp3C;
    s32 sp4C;
    M2C_UNK sp50;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    s128 sp80;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_v0;
    f32 var_f2;
    void *temp_a2;

    UpdateCplcy();
    temp_f0 = (g_2dded0 - M2C_FIELD(&B_002DDF40, f32 *, 0x390)) / M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 8);
    var_f2 = 0.0f;
    if (!(temp_f0 < 0.0f)) {
        var_f2 = temp_f0;
        if (temp_f0 > 1.0f) {
            var_f2 = 1.0f;
        }
    }
    temp_f1 = var_f2 * var_f2;
    sp68 = var_f2;
    temp_a2 = M2C_FIELD(arg0, void **, 0x10);
    sp64 = temp_f1;
    sp60 = temp_f1 * var_f2;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($a1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a3) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    temp_f20 = ((1.0f - temp_v0) * M2C_FIELD(M2C_FIELD(temp_a2, void **, 0), f32 *, 0x20)) + (temp_v0 * M2C_FIELD(M2C_FIELD(temp_a2, void **, 4), f32 *, 0x20));
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp80, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), temp_a2, M2C_FIELD(temp_a2, void **, 4));
    __as__6VECTORG9VU_VECTOR(&sp50, sp0);
    sp20 = sp80;
    M2C_FIELD(&sp20, s128 *, 0x10) = sp90;
    M2C_FIELD(&sp20, s128 *, 0x20) = spA0;
    sp4C = 0;
    sp3C = 0;
    unksp2C = 0;
    M2C_FIELD(&sp20, f32 *, 0x3C) = 1.0f;
    SetCmPosMat(&B_002DDF40, &sp20, sp80);
    SetCmFov(&B_002DDF40, temp_f20);
}
