#include "m2c_macros.h"

M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, M2C_UNK *, s32); /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */
M2C_UNK memset(s32, M2C_UNK, s32);                  /* extern */

void func_00203D00(void *arg0, void *arg1, s32 arg2) {
    s128 sp40;
    M2C_UNK sp80;
    s32 var_a0;
    void *temp_v0;

    M2C_FIELD(arg0, void **, 0x25C) = arg1;
    if (arg2 != 0) {
        InvertMatrix4Affine(&sp80, M2C_FIELD(M2C_FIELD(arg0, void **, 0x258), s32 *, 0) + 0x40);
        __ml__FRC7MATRIX4T0(&sp40, &sp80, M2C_FIELD(M2C_FIELD(arg0, void **, 0x25C), s32 *, 0) + 0x40);
        var_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x25C), s32 *, 0x78) - 1;
        if (var_a0 >= 0) {
            do {
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
                var_a0 -= 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($a1) */);
            } while (var_a0 >= 0);
        }
        temp_v0 = M2C_FIELD(arg0, void **, 0x258);
        memset(*M2C_FIELD(temp_v0, s32 **, 0x10), 0, M2C_FIELD(temp_v0, s32 *, 0x78) * 0x10);
        func_001F4BF8(arg0);
    }
}
