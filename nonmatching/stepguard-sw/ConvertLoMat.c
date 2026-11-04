#include "m2c_macros.h"

M2C_UNK InvertMatrix3(M2C_UNK *, s32);              /* extern */
s32 PmatLoWorld(s32);                               /* extern */

void *ConvertLoMat(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s128 sp0;
    s128 sp10;
    s128 sp20;
    M2C_UNK sp60;

    if (arg1 != 0) {
        PmatLoWorld(arg1);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf4, $vf6z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($s0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf4, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf4, $vf5z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
    } else {
        sp0 = M2C_FIELD(arg3, s128 *, 0);
        sp10 = M2C_FIELD(arg3, s128 *, 0x10);
        sp20 = M2C_FIELD(arg3, s128 *, 0x20);
    }
    if (arg2 != 0) {
        InvertMatrix3(&sp60, PmatLoWorld(arg2));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf5z */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf6z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
    }
    M2C_FIELD(arg0, s128 *, 0) = sp0;
    M2C_FIELD(arg0, s128 *, 0x10) = sp10;
    M2C_FIELD(arg0, s128 *, 0x20) = sp20;
    return arg0;
}
