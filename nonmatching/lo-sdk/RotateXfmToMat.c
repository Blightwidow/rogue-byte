#include "m2c_macros.h"

M2C_UNK ConvertXfMat(void *, M2C_UNK, s32, s32);    /* extern */
M2C_UNK InvalidateXfmMatWorld(void *, s128);        /* extern */

void RotateXfmToMat(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    void *temp_v1;

    ConvertXfMat(sp, 0, M2C_FIELD(arg0, s32 *, 0x50), arg1);
    temp_v1 = arg0 + 0x60;
    M2C_FIELD(arg0, s128 *, 0x60) = sp0;
    M2C_FIELD(temp_v1, s128 *, 0x10) = sp10;
    M2C_FIELD(temp_v1, s32 *, 0xC) = 0;
    M2C_FIELD(temp_v1, s128 *, 0x20) = sp20;
    M2C_FIELD(temp_v1, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x1C) = 0;
    InvalidateXfmMatWorld(arg0, sp10);
}
