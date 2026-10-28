#include "m2c_macros.h"

M2C_UNK InvalidateXfmMatWorld(void *, s128, s128);  /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(void *, s32);           /* extern */

void ApplyXfmProxy(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    __ml__FRC7MATRIX4T0(sp, arg0 + 0x60);
    M2C_FIELD(arg0, s128 *, 0x60) = sp0;
    M2C_FIELD(arg0, s128 *, 0x70) = sp10;
    M2C_FIELD(arg0, s128 *, 0x80) = sp20;
    M2C_FIELD(arg0, s128 *, 0x90) = sp30;
    InvalidateXfmMatWorld(arg0, sp30, sp0);
}
