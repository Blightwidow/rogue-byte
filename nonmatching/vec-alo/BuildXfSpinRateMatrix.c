#include "m2c_macros.h"

M2C_UNK memset(M2C_UNK, M2C_UNK);                   /* extern */

void *BuildXfSpinRateMatrix(void *arg0, s32 arg2) {
    f32 temp_s0;
    f32 temp_v0;
    f32 temp_v0_2;

    temp_s0 = M2C_ERROR(/* unknown instruction: por $s0, $zero, $a3 */);
    memset(0, 0x40);
    temp_v0 = M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */);
    M2C_FIELD(arg0, f32 *, 4) = temp_v0;
    M2C_FIELD(arg0, f32 *, 0x20) = temp_v0_2;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) -temp_s0;
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) -temp_v0;
    M2C_FIELD(arg0, f32 *, 0x18) = temp_s0;
    M2C_FIELD(arg0, f32 *, 8) = (f32) -temp_v0_2;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($s2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($s2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($s2) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf1, $vf5z */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf6z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($sp) */);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    return arg0;
}
