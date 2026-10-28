#include "m2c_macros.h"

s32 CalculateBlrunV(void *arg0) {
    u32 var_a1;

    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
    var_a1 = 0;
    do {
        var_a1 += 1;
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($a0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    } while (var_a1 < 2U);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
}
