#include "m2c_macros.h"

M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(void *, s32, M2C_UNK *); /* extern */

void CalculateDmat4(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    M2C_UNK sp40;

    InvertMatrix4Affine(&sp40, arg0);
    __ml__FRC7MATRIX4T0(sp, arg1, &sp40);
    M2C_FIELD(arg2, s128 *, 0) = sp0;
    M2C_FIELD(arg2, s128 *, 0x30) = sp30;
    M2C_FIELD(arg2, s128 *, 0x10) = sp10;
    M2C_FIELD(arg2, s128 *, 0x20) = sp20;
}
