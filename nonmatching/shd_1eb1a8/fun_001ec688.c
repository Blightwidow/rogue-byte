#include "m2c_macros.h"

M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, s32, s32); /* extern */

s32 func_001EC688(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x20) + (arg1 * 8);
    AddVifUnpack__4VIFS3UPKiPvi(arg3, 0xC, M2C_FIELD(temp_s0, s32 *, 0), M2C_FIELD(temp_s0, s32 *, 4));
    return M2C_FIELD(temp_s0, s32 *, 0);
}
