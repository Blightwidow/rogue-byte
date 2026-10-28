#include "m2c_macros.h"

void func_00201D78(void *arg0, s32 arg1) {
    void *temp_v0;

    M2C_FIELD(arg0, f32 *, 0x10) = 0.0f;
    temp_v0 = arg0 + 0x10;
    M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
    M2C_FIELD(temp_v0, M2C_UNK32 *, 4) = 0;
    M2C_FIELD(temp_v0, M2C_UNK32 *, 8) = 0;
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) ((M2C_FIELD(arg0, f32 *, 0x10) * 320.0f) + 320.0f);
    M2C_FIELD(temp_v0, M2C_UNK32 *, 8) = (M2C_UNK32) M2C_FIELD(temp_v0, M2C_UNK32 *, 4);
    M2C_FIELD(temp_v0, M2C_UNK32 *, 4) = 0x43766667;
    M2C_FIELD(arg0, s32 *, 0) = -1;
}
