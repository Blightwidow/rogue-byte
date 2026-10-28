#include "m2c_macros.h"

M2C_UNK ClearSle(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK RO_002A3A10;

void InitDepthSlot(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x44) = &RO_002A3A10;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 0x50) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x64) = -1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 4) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 0x40) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    ClearSle(arg0 + 0x68, 0x7F7F7F7F, 0xFFFFFFFF, -1);
}
