#include "m2c_macros.h"

M2C_UNK StartSpooling__18CBinaryAsyncStream(s32);   /* extern */

s32 FOpenSector__18CBinaryAsyncStreamUiUi(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a3;

    M2C_FIELD(arg0, s32 *, 0x2C) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    temp_a3 = M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x28) = arg2;
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 0x20) = temp_a3;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    StartSpooling__18CBinaryAsyncStream(temp_a3);
    return 1;
}
