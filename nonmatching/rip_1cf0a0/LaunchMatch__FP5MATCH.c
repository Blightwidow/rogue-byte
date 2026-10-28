#include "m2c_macros.h"

M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, void *, void *, s128); /* extern */
M2C_UNK MatMulMatTransMat(s128 *, void *, void *);  /* extern */
void *PmatLoWorld(void *);                          /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK PredictXfTransform(s32, M2C_UNK, void *, M2C_UNK, f32); /* extern */

void LaunchMatch__FP5MATCH(void *arg0) {
    char sp[0x400];
    M2C_UNK sp90;
    M2C_UNK spA0;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp80;
    f32 temp_f1;
    f32 var_f0;
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;

    M2C_FIELD(arg0, s128 *, 0x70) = PosLoWorld(M2C_FIELD(arg0, void **, 0x104));
    temp_v0 = PmatLoWorld(M2C_FIELD(arg0, void **, 0x104));
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(temp_v0, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
    PredictXfTransform(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 0x60), 0, sp, 0, M2C_FIELD(arg0, f32 *, 0x18));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($s0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
    MatMulMatTransMat(&sp80, sp, arg0 + 0x40);
    sp40 = sp80;
    sp50 = sp90;
    sp60 = spA0;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp40, arg0 + 0x100, arg0 + 0xF0, sp80);
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x100);
    if (temp_f1 > 0.0f) {
        var_f0 = temp_f1 + 6.2831855f;
    } else {
        var_f0 = temp_f1 - 6.2831855f;
    }
    M2C_FIELD(arg0, f32 *, 0x100) = var_f0;
    temp_a1 = M2C_FIELD(arg0, void **, 0x104);
    temp_v0_2 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x48), temp_a1);
    M2C_FIELD(arg0, void **, 0x104) = NULL;
}
