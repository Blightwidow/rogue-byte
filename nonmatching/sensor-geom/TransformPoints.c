#include "m2c_macros.h"

void TransformPoints(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a3;
    s32 temp_v0;
    s32 var_a3;

    var_a3 = arg3;
    if (arg1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($a2) */);
        temp_v0 = var_a3 + (arg1 * 0x10);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a0) */);
        M2C_ERROR(/* unknown instruction: vcallms 0x120 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($a2) */);
loop_2:
        M2C_ERROR(/* unknown instruction: vcallms 0xf0 */);
        M2C_ERROR(/* unknown instruction: vnop */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($a3) */);
        temp_a3 = var_a3 + 0x10;
        if (temp_a3 != temp_v0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($a2) */);
            M2C_ERROR(/* unknown instruction: vcallms 0x120 */);
            M2C_ERROR(/* unknown instruction: vnop */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($a3) */);
            var_a3 = temp_a3 + 0x10;
            if (var_a3 != temp_v0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($a2) */);
                goto loop_2;
            }
        }
    }
}
