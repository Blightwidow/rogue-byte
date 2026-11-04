#include "m2c_macros.h"

void *func_00122730(void *arg0, void *arg2) {
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    return arg0;
}
