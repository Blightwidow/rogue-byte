#include "m2c_macros.h"

s32 FOpenSector__18CBinaryInputStreamUiUi(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a0;

    var_a0 = M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    M2C_FIELD(arg0, s32 *, 0x48) = arg2;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    if (var_a0 < 0) {
        var_a0 += 0xFFFFF;
    }
    temp_a0 = var_a0 >> 0x14;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    temp_v0 = (temp_a0 > 2) ? temp_a0 : 2;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) (temp_v0 - 1);
    return 1;
}
