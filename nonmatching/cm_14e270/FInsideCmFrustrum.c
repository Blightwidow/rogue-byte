#include "m2c_macros.h"

s32 FInsideCmFrustrum(void) {
    M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc0($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($a0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($a0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf5 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf6 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyzw $acc, $vf1, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyzw $acc, $vf3, $vf5z */);
    M2C_ERROR(/* unknown instruction: vmsubax.xyzw $acc, $vf4, $vf6x */);
    M2C_ERROR(/* unknown instruction: vnop */);
    M2C_ERROR(/* unknown instruction: vnop */);
    M2C_ERROR(/* unknown instruction: vnop */);
    M2C_ERROR(/* unknown instruction: vnop */);
    return M2C_ERROR(/* unknown instruction: cfc2.ni $v0, $vi17 */) == 0xF0;
}
