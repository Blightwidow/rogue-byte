#include "m2c_macros.h"

M2C_UNK EvaluateBezierPos__FfffP6VECTORN63(s128, s128, s128, s128, f32, f32, M2C_UNK); /* extern */

void FillCrvcCache(void *arg0, s32 arg1) {
    M2C_UNK sp20;
    M2C_UNK sp30;
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp10;
    f32 temp_f20;
    s32 var_s2;
    void *temp_a0;
    void *var_s0;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x148)) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x30($a1) */);
        var_s2 = 0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($a2) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x10($a2) */);
        var_s0 = arg0 + 0x14C;
        M2C_ERROR(/* unknown instruction: lqc2 $vf8, ($v1) */);
        M2C_FIELD(arg0, s32 *, 0x14C) = 0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x100($s1) */);
        temp_a0 = (arg1 * 4) + M2C_FIELD(arg0, s32 *, 0xEC);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf9, $vf2, $vf5z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf9, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf7x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf7y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf7z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf6, $vf0w */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf9, $vf6, $vf0w */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf8x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf8y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf2, $vf8z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf9, 0x20($sp) */);
        temp_f20 = M2C_FIELD(temp_a0, f32 *, 4) - M2C_FIELD(temp_a0, f32 *, 0);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        do {
            EvaluateBezierPos__FfffP6VECTORN63(sp20, sp40, sp30, sp50, temp_f20, (f32) var_s2 * 0.1f * temp_f20, 0x3F800000);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
            if (var_s2 > 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_FIELD(var_s0, f32 *, 0) = (f32) (M2C_FIELD(var_s0, f32 *, -4) + M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */));
            }
            var_s2 += 1;
            var_s0 += 4;
        } while (var_s2 < 0xB);
        M2C_FIELD(arg0, s32 *, 0x148) = arg1;
    }
}
