#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(f32 *, f32 *, f32); /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
f32 GRandInRange(M2C_UNK, f32);                     /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(M2C_UNK, s128, s128, M2C_UNK *); /* extern */
M2C_UNK ProjectRipTransform__FP3RIPf();             /* extern */
extern s128 g_2a2da0;
extern s128 g_2a2dc0;
extern s128 g_2a2dd0;

s32 ProjectBubletTransform__FP6BUBLETf(void *arg0) {
    M2C_UNK sp10;
    f32 sp50;
    f32 sp54;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;

    var_s3 = 0;
    var_s4 = 0;
    ProjectRipTransform__FP3RIPf();
    temp_f20 = GRandInRange(0, 1.0f);
    var_v0 = FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(arg0, s128 *, 0x90), 0x38D1B717);
    if (var_v0 != 0) {
        var_v0 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717);
        if (var_v0 != 0) {
            var_v0 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717);
            var_s3 = var_v0 != 0;
        }
    }
    if ((var_s3 == 0) && (temp_f20 < 0.3f)) {
        var_s4 = 1;
    }
    if (var_s4 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s2) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), g_2a2da0, g_2a2dc0, &sp10);
        temp_f20_2 = GRandInRange(0x42C80000, ((1.0f - (temp_f20 * 3.3333333f)) * 300.0f) + 100.0f);
        CalculateSinCos__FfPfT1(&sp50, &sp54, GRandInRange(0, 6.2831855f));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($s2) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf5x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($s2) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
    }
    return var_v0;
}
