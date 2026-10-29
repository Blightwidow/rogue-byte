#include "m2c_macros.h"
extern "C" {

M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s32);    /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, M2C_UNK *, s128); /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
M2C_UNK MatMulMatTransMat(s128 *, void *, void *);  /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(void *, s128, s128, s128, s128); /* extern */
extern M2C_UNK g_2dded0;

s32 AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(void *arg0, s32 arg1, void *arg2) {
    char sp[0xB0];
    M2C_UNK spC0;
    M2C_UNK spD0;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    M2C_UNK sp60;
    s128 spA0;
    s128 spB0;
    f32 spE0;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    void *temp_s0;

    temp_f20 = M2C_FIELD(arg2, f32 *, 0);
    temp_s0 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s0) */);
    temp_f22 = (temp_f20 - M2C_FIELD(arg2, f32 *, 4)) / M2C_FIELD(arg2, f32 *, 8);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_f21 = (temp_f20 * temp_f20) / (2.0f * temp_f22);
    if (temp_f20 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s0) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xf0($s0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s0) */);
    }
    ConvertXfMat(&spB0, 0, M2C_FIELD(temp_s0, s32 *, 0xA0), arg1);
    NormalizeRotateMatrix3__FP7MATRIX3(sp, spB0, spB0, spC0, spD0);
    MatMulMatTransMat(&spA0, temp_s0, sp);
    sp50 = spC0;
    sp30 = spA0;
    sp40 = spB0;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp30, &spE0, &sp60, spA0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    temp_f0 = spE0 - ((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) + GLimitAbs__Fff((spE0 / temp_f21) * temp_f20, temp_f20)) * (M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f));
    if (temp_f0 < temp_f21) {
        GLimitAbs__Fff((temp_f0 / temp_f21) * temp_f20, temp_f20);
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xb0($s0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xf0($s0) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < (temp_f22 * M2C_FIELD(&g_2dded0, f32 *, 4))) {

    }
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xf0($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s0) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
}
}
