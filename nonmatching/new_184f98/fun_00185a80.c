#include "m2c_macros.h"

M2C_UNK SolveInequalities(s32, s32 *, f32 *, M2C_UNK *, f32); /* extern */

s32 func_00185A80(s32 arg0, s32 *arg1) {
    char sp[0x400];
    f32 sp90;
    M2C_UNK spB0;
    f32 *var_a3_2;
    f32 temp_f0;
    s32 *var_a3;
    s32 temp_v0;
    s32 var_a1;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    void *var_a0;

    temp_v0 = *arg1;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf4 */);
    if (temp_v0 != 0) {
        var_a3 = sp;
        var_v1 = 0;
        if (temp_v0 > 0) {
            var_a1 = 0;
loop_3:
            if (*arg1 > 0) {
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
                    var_a1 += 1;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                    *var_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    var_a3 += 4;
                } while (var_a1 < *arg1);
            }
            var_v1 += 1;
            if (var_v1 < *arg1) {
                var_a1 = 0;
                goto loop_3;
            }
        }
        var_a3_2 = &sp90;
        var_v1_2 = 0;
        if (*arg1 > 0) {
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf4 */);
            var_a0 = arg1 + 0x10;
            do {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                var_v1_2 += 1;
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                temp_f0 = M2C_FIELD(var_a0, f32 *, 0xC);
                var_a0 += 0x10;
                *var_a3_2 = temp_f0 + M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                var_a3_2 += 4;
            } while (var_v1_2 < *arg1);
        }
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xe0($sp) */);
        SolveInequalities(*arg1, sp, &sp90, &spB0, 3.4028235e38f);
        var_v1_3 = *arg1;
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xe0($sp) */);
        if (var_v1_3 > 0) {
            do {
                var_v1_3 -= 1;
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
            } while (var_v1_3 != 0);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xd0($sp) */);
        }
    }
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
}
