#include "m2c_macros.h"

s32 func_001A4258(s32 arg1, void *arg2, f32 fparg0) {
    f32 temp_f1;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_v0;
    void *var_v1;

    var_a3 = 0;
    if (arg1 > 0) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
        var_v1 = arg2;
loop_2:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        var_v0 = 1;
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < (fparg0 + M2C_FIELD(var_v1, f32 *, 0x10)))) {
            var_a3 += 1;
            var_v1 += 0x20;
            if (var_a3 >= arg1) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_a3_2 = 1;
        var_v0 = 0;
        if (arg1 > 1) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf10 */);
loop_6:
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($a2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($a2) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf10, $vf6 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf5, $vf6 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf1 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf4, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf1, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf4, $vf4, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf4 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf4, $q */);
            M2C_ERROR(/* unknown instruction: c1 0x44 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf7x */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf9 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf7, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf6, $vf1, $vf9x */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf8 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf10, $vf6 */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf5 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf1, $vf8x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf9, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf5, $vf6 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf5, $vf5 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf1, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf5 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf8, ($sp) */);
            temp_f1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) / M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < fparg0) || !(temp_f1 >= 0.0f) || (var_v0 = 1, !(temp_f1 <= 1.0f))) {
                var_a3_2 += 1;
                if (var_a3_2 >= arg1) {
                    var_v0 = 0;
                } else {
                    goto loop_6;
                }
            }
        }
    }
    return var_v0;
}
