#include "m2c_macros.h"

s32 ConvertCmScreenToWorld(void *arg0, s32 arg1) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 temp_f1;
    f32 temp_v0;
    f32 temp_v0_2;

    temp_v0 = M2C_ERROR(/* unknown instruction: prot3w $v0, $a1 */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $a1 */);
    sp8 = temp_v0;
    sp0 = temp_v0_2;
    temp_f1 = -M2C_BITWISE(f32, arg1);
    sp4 = temp_f1;
    if (temp_v0_2 > 0.0001f) {
        sp8 = temp_v0 * temp_v0_2;
        sp4 = temp_f1 * temp_v0_2;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x60($a0) */);
    sp4 *= M2C_FIELD(arg0, f32 *, 0x40);
    sp8 *= M2C_FIELD(arg0, f32 *, 0x44);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf3z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf4, $vf0w */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf6 */);
}
