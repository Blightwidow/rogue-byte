#include "m2c_macros.h"
extern "C" {

M2C_UNK InvertMatrix3(M2C_UNK *, s32);              /* extern */
M2C_UNK memcpy(s32, void *, M2C_UNK);               /* extern */

s32 ConvertXfMat(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    char sp[0xB0];
    M2C_UNK sp30;
    M2C_UNK sp60;

    if (arg1 != 0) {
        if (arg2 != 0) {
            InvertMatrix3(&sp60, arg2 + 0x40);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0x20($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf7, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf4z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf7, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf5, $vf1z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf9, 0x10($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf7, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf8x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf8y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf8, $vf3, $vf8z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf3, $vf6z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf9x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf9y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf3, $vf9z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xb0($sp) */);
            memcpy(arg0, sp, 0x30);
        } else {
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf5, $vf6z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf3z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
            memcpy(arg0, sp, 0x30);
        }
    } else if (arg2 != 0) {
        InvertMatrix3(&sp30, arg2 + 0x40);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($s1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf6y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf1, $vf6z */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf2z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf5y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf5z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x80($sp) */);
        memcpy(arg0, sp, 0x30);
    } else {
        memcpy(arg0, arg3, 0x30);
    }
    return arg0;
}
}
