#include "m2c_macros.h"

M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, M2C_UNK, void *, s128); /* extern */

s32 func_001EC6D0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    AddVifUnpack__4VIFS3UPKiPvi(arg3, 0xC, 1, sp, M2C_FIELD(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x20) + (arg1 * 8)), void **, 4), s128 *, 0x30));
    return 1;
}
