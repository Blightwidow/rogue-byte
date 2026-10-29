#include "m2c_macros.h"
extern "C" {

M2C_UNK LoadRotateMatrixRad(void *, M2C_UNK, s128, f32, f32); /* extern */
M2C_UNK ProjectRipTransform__FP3RIPf(void *);       /* extern */
M2C_UNK SProjectVector__FP6VECTORT0(M2C_UNK, s128, s128 *, M2C_UNK *); /* extern */
extern s128 g_2a2da0;
extern M2C_UNK g_2c2010;
extern M2C_UNK g_2c2020;
extern M2C_UNK g_2dded0;

void ProjectLeafTransform__FP4LEAFf(void *arg0) {
    char sp[0x30];
    s128 sp30;
    M2C_UNK sp40;
    s128 sp90;
    f32 temp_a3;
    f32 temp_f20;
    f32 var_f0;

    sp90 = M2C_FIELD(arg0, s128 *, 0x40);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf1 */);
    var_f0 = M2C_FIELD(&g_2c2010, f32 *, 0) + (temp_a3 * (M2C_FIELD(&g_2c2010, f32 *, 4) + (temp_a3 * M2C_FIELD(&g_2c2010, f32 *, 8))));
    if (var_f0 < M2C_FIELD(&g_2c2020, f32 *, 0)) {
        var_f0 = M2C_FIELD(&g_2c2020, f32 *, 0);
    } else if (M2C_FIELD(&g_2c2020, f32 *, 4) < var_f0) {
        var_f0 = M2C_FIELD(&g_2c2020, f32 *, 4);
    }
    LoadRotateMatrixRad(sp, M2C_ERROR(/* unknown instruction: por $a1, $zero, $a2 */), M2C_FIELD(arg0, s128 *, 0x50), temp_a3, var_f0 * M2C_FIELD(&g_2dded0, f32 *, 4));
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($s1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf5, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf4z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($s1) */);
    temp_f20 = M2C_FIELD(arg0, f32 *, 0xC4);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($s1) */);
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
    SProjectVector__FP6VECTORT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), sp90, &sp30, &sp40);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {
        sp30 = g_2a2da0;
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    }
    M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
    ProjectRipTransform__FP3RIPf(arg0);
    M2C_FIELD(arg0, f32 *, 0xC4) = temp_f20;
}
}
