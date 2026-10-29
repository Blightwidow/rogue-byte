#include "m2c_macros.h"
extern "C" {

M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s32);    /* extern */
M2C_UNK ConvertXfVec(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, M2C_UNK *, s128); /* extern */
M2C_UNK MatMulMatTransMat(s128 *, void *, void *);  /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(void *, s128, s128, s128, s128); /* extern */
extern f32 g_2dded4;

void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(void *arg0, s32 arg1, void *arg2) {
    char sp[0x90];
    M2C_UNK sp80;
    M2C_UNK sp90;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    M2C_UNK sp60;
    s128 sp70;
    f32 spA0;
    f32 temp_v0;
    void *temp_s1;
    void *temp_s3;

    temp_s3 = M2C_ERROR(/* Read from unset register $t0 */);
    M2C_ERROR(/* unknown instruction: por $s4, $zero, $a3 */);
    temp_s1 = M2C_FIELD(arg0, void **, 0x5C);
    if (arg2 != NULL) {
        ConvertXfMat(&sp70, 0, M2C_FIELD(temp_s1, s32 *, 0xA0), arg1);
        NormalizeRotateMatrix3__FP7MATRIX3(sp, sp70, sp70, sp80, sp90);
        MatMulMatTransMat(&sp70, temp_s1, sp);
        sp30 = sp70;
        sp40 = sp80;
        sp50 = sp90;
        DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp30, &spA0, &sp60, sp70);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
        if (spA0 > 0.0001f) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xf0($s1) */);
        }
    }
    if (temp_s3 != NULL) {
        ConvertXfVec(0, M2C_FIELD(temp_s1, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s4 */));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        if (temp_v0 > 0.0001f) {
            if ((1.0f / g_2dded4) < ((M2C_FIELD(temp_s3, f32 *, 8) * temp_v0) + M2C_FIELD(temp_s3, f32 *, 4) + (M2C_FIELD(temp_s3, f32 *, 0) / temp_v0))) {

            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xf0($s1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s1) */);
        }
    }
}
}
