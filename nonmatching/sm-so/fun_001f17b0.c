#include "m2c_macros.h"

void func_001F17B0(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_v0;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x484);
    var_v0 = temp_v1 * 0x10;
    if ((temp_v1 <= 0) || (var_v0 = temp_v1 * 0x10, (M2C_FIELD(arg0, s32 *, 0x490) != 0))) {
        M2C_FIELD(arg0, s32 *, 0x484) = (s32) (temp_v1 + 1);
        temp_v0 = arg0 + (var_v0 + 0x404);
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, s32 *, 0xC) = 1;
        M2C_FIELD(temp_v0, s32 *, 8) = -1;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
    }
}
