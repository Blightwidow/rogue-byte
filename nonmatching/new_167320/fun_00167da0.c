#include "m2c_macros.h"

s32 func_00167DA0(s32 arg0, s32 arg1, f32 *arg2) {
    f32 temp_f1;
    f32 temp_v0;
    s32 var_v0;

    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf5, $vf0w */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf6 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf6 */);
    temp_f1 = *arg2;
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf6 */);
    if (temp_f1 < temp_v0) {
        *arg2 = (temp_v0 + temp_f1) * 0.5f;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf6, $vf2, $vf1x */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf6 */);
    }
    return var_v0;
}
