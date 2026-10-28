#include "m2c_macros.h"

void func_001F1768(void *arg0, s32 arg1) {
    s32 temp_v1;
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x490) != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x484);
        M2C_FIELD(arg0, s32 *, 0x484) = (s32) (temp_v1 + 1);
        temp_v0 = arg0 + ((temp_v1 * 0x10) + 0x404);
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg1;
        M2C_FIELD(temp_v0, s32 *, 0) = 0x2B3;
        M2C_FIELD(temp_v0, s32 *, 8) = -1;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
    }
}
