#include "m2c_macros.h"

M2C_UNK SolveSwGroup(s32, s32, s32, s32);           /* extern */
s32 func_001F90D0();                                /* extern */

void func_001F9240(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    f32 temp_f0;
    s32 temp_a1;
    s32 temp_t0;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_condition_bit;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    void **var_a0;
    void **var_a0_2;
    void *temp_v1;

    var_s0 = arg1;
    temp_t0 = func_001F90D0();
    if (var_s0 & 1) {
        var_s0 = (temp_t0 == 0) ? 0 : var_s0;
    } else {
        var_v0 = var_s0 & 2;
        if (var_s0 & 4) {
            var_a2 = 0;
            var_a0 = sp;
loop_5:
            temp_a1 = var_a2 < temp_t0;
            if (temp_a1 != 0) {
                temp_v1 = *var_a0;
                temp_f0 = M2C_FIELD(temp_v1, f32 *, 0x90);
                if (M2C_FIELD(temp_v1, s32 *, 0x9C) == 0xB) {
                    if (!(fabsf(temp_f0) > 0.1f)) {
                        var_a0 += 4;
                        goto block_4;
                    }
                    goto block_12;
                }
                if (!(temp_f0 < -2.0f)) {
                    var_a0 += 4;
block_4:
                    var_a2 += 1;
                    goto loop_5;
                }
block_12:
                var_v0 = var_s0 & 2;
                if (temp_a1 == 0) {
                    goto block_14;
                }
            } else {
block_14:
                var_s0 &= ~4;
                var_v0 = var_s0 & 2;
            }
        }
        if (var_v0 != 0) {
            var_a2_2 = 0;
            if (temp_t0 > 0) {
                var_a0_2 = sp;
loop_18:
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($v1) */);
                if (M2C_FIELD(*var_a0_2, s32 *, 0x9C) == 0xB) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($v1) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    var_condition_bit = fabsf(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) > 5.0f;
                } else {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($v1) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    var_condition_bit = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < -5.0f;
                }
                var_v0_2 = var_a2_2 < temp_t0;
                if (!var_condition_bit) {
                    var_a2_2 += 1;
                    var_a0_2 += 4;
                    if (var_a2_2 >= temp_t0) {
                        var_v0_2 = var_a2_2 < temp_t0;
                    } else {
                        goto loop_18;
                    }
                }
                if (var_v0_2 == 0) {
                    goto block_25;
                }
            } else {
block_25:
                var_s0 &= ~2;
            }
        }
    }
    if (var_s0 != 0) {
        SolveSwGroup(arg0, var_s0, arg2, arg3);
    }
}
