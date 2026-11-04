#include "m2c_macros.h"

M2C_UNK CalculateEmitvx__FiP2LMiP6EMITVX(s32, s32, s32, M2C_UNK *); /* extern */
M2C_UNK ChooseEmitoPos(void *, s32, s32, s32);      /* extern */
M2C_UNK ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7(void *, M2C_UNK *, void *, s32, s32); /* extern */
M2C_UNK ConvertEmitoPosVec__FP5EMITOP6VECTORT1(void *, s32, s32); /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */

void OriginateParticles__FiP5EMITBP7EMITGEN(s32 arg0, void *arg1, void *arg2) {
    s32 sp10;
    M2C_UNK sp20;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s5;

    temp_s2 = arg0 * 0x10;
    temp_s3 = arg0 * 4;
    sp10 = temp_s2;
    var_s5 = 0;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s2;
    M2C_FIELD(arg2, s32 *, 0) = temp_v0;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s3;
    M2C_FIELD(arg2, s32 *, 4) = temp_v0_2;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0_3 = PvAllocStackImpl__Fi(&sp10);
    sp10 = temp_s3;
    M2C_FIELD(arg2, s32 *, 8) = temp_v0_3;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg2, s32 *, 0xC) = PvAllocStackImpl__Fi(&sp10);
    CalculateEmitvx__FiP2LMiP6EMITVX(M2C_FIELD(arg1, s32 *, 0x84), arg1 + 0x90, arg0, &sp20);
    if (arg0 > 0) {
loop_2:
        temp_s0 = var_s5 * 0x10;
        ChooseEmitoPos(arg1, var_s5, arg0, M2C_FIELD(arg2, s32 *, 0) + temp_s0);
        ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7(arg1 + 0x50, &sp20, arg1 + 0x10, var_s5, M2C_FIELD(arg2, s32 *, 0xC) + (var_s5 * 4));
        if (M2C_FIELD(arg1, s32 *, 0x1C) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($a0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf3z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf5, $vf1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($a0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($a1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf6, $vf2z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($a1) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf4 */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf5 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf5, $vf1 */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($v1) */);
        }
        if (M2C_FIELD(arg2, s32 *, 0x10) != 0) {
            ConvertEmitoPosVec__FP5EMITOP6VECTORT1(arg1, M2C_FIELD(arg2, s32 *, 0) + temp_s0, M2C_FIELD(arg2, s32 *, 4) + temp_s0);
        }
        var_s5 += 1;
        if (var_s5 < arg0) {
            goto loop_2;
        }
    }
}
