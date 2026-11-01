#include "m2c_macros.h"

f32 GMaxAxisScale(void) {
    f32 temp_v0;
    f32 temp_v0_2;
    f32 temp_v0_3;

    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($a0) */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a0) */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    if ((temp_v0_2 < temp_v0) && (temp_v0_3 < temp_v0)) {

    } else if (temp_v0_3 < temp_v0_2) {

    }
    M2C_ERROR(/* unknown instruction: c1 0x44 */);
    return temp_v0;
}
