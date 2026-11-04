#include "m2c_macros.h"

s32 FFindCmClearInterval(s32, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
extern M2C_UNK D_002BD8B0;

s128 FindCmClosestClearPos(s32 arg0, s32 arg1, f32 fparg0) {
    M2C_UNK sp20;
    f32 sp10;
    M2C_UNK sp14;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f21;
    s32 temp_s1;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf6 */);
    temp_f20 = 5.0f / fparg0;
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
    var_a0 = 0;
    var_f21 = 3.4028235e38f;
    var_v0 = -4;
    do {
        temp_s1 = *((var_a0 * 4) + &D_002BD8B0);
        var_s0 = 0;
        if (temp_s1 > 0) {
            do {
                M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
                SetVectorSphere__FP6VECTORfff(((f32) var_s0 * 3.1415927f) / (f32) temp_s1, (f32) var_v0 * 0.3926991f, 0x3F800000);
                M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x50($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $s3, $vf1 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf5, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x50($sp) */);
                if (FFindCmClearInterval(arg0, arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf6 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf4 */), 2.0f * temp_f20) != 0) {
                    var_f0 = sp10;
                    if (var_f0 > 0.0f) {
                        temp_f0 = var_f0 + temp_f20;
                        sp10 = temp_f0;
                        var_f0 = temp_f0;
                    }
                    if (var_f0 < var_f21) {
                        var_f21 = var_f0;
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $s6, $vf3 */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf6, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf7, $vf5, $vf3x */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
                    }
                }
                var_s0 += 1;
            } while (var_s0 < temp_s1);
        }
        var_a0 += 1;
        var_v0 = var_a0 - 4;
    } while (var_a0 < 9);
    return sp20;
}
