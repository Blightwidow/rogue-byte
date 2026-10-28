#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(s128, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK ForceRipFade__FP3RIPf(void *, f32);         /* extern */
M2C_UNK LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(s32, s128, void *, M2C_UNK); /* extern */
M2C_UNK VelocityXfAtPos(s32, M2C_UNK, s128);        /* extern */
extern s128 g_2a2dd0;
extern f32 g_2c1f60;
extern f32 g_2c1f68;
extern f32 g_2c1f6c;
extern f32 g_2dded0;

s32 FBounceRip__FP3RIPP2SOP6VECTORT2(void *arg0, void *arg1, s128 arg2) {
    char sp[0x400];
    f32 sp40;
    M2C_UNK sp44;
    s128 sp50;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f20;
    void *temp_v1;

    sp50 = arg2;
    if (M2C_FIELD(arg0, s32 *, 0) == 8) {
        var_f20 = M2C_FIELD(arg0, f32 *, 0xF0);
    } else {
        var_f20 = 100.0f;
    }
    temp_v1 = arg0 + 0x20;
    temp_f0 = (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x14)) / M2C_FIELD(arg0, f32 *, 0x18);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xa0($sp) */);
    temp_f20 = var_f20 * (M2C_FIELD(arg0, f32 *, 0x20) + (temp_f0 * (M2C_FIELD(temp_v1, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v1, f32 *, 8)))));
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xa0($sp) */);
    if (FIsBasicDerivedFrom(M2C_FIELD(arg1, s32 *, 4), 0x59, M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf8 */)) != 0) {
        LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(M2C_FIELD(arg1, s32 *, 4), sp50, sp, 0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf4x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($s0) */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        ForceRipFade__FP3RIPf(arg0, g_2c1f60);
        return 1;
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf10, $vf8 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf8, $vf10 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf10, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
    VelocityXfAtPos(M2C_FIELD(arg1, s32 *, 0), 0, sp50);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xd0($s0) */);
    M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf10, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf10 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf10, $vf2 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf9, $vf1, $vf5 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf9, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf10 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf10, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf11, $vf8 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf2, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf9 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf7, $vf7 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf7, $q */);
    }
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf11 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf1, $vf6x */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf10, $vf5 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf5, $vf10 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf9, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf10 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf10, $vf1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf6 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf5 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf2, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf9 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    ClosestPointOnSegment(g_2a2dd0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xd0($s0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf3, $vf5 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($s0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf5, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf7, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf6x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xd0($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($sp) */);
    if (M2C_FIELD(arg0, f32 *, 0x98) < g_2c1f68) {
        M2C_FIELD(arg0, f32 *, 0x98) = (f32) g_2c1f68;
        M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xa0($sp) */);
        ForceRipFade__FP3RIPf(arg0, g_2c1f6c);
        M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xa0($sp) */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf8 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f1 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($s0) */);
    return 1;
}
