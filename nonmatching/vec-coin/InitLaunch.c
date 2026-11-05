#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */

void InitLaunch(void *arg0) {
    void *temp_v0;
    void *temp_v1;

    InitLo();
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    temp_v1 = arg0 + 0x70;
    M2C_FIELD(temp_v1, s32 *, 8) = 0;
    temp_v0 = arg0 + 0x90;
    M2C_FIELD(temp_v1, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, f32 *, 0x84) = 3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    M2C_FIELD(temp_v0, f32 *, 4) = 1.0f;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(arg0, f32 *, 0xB0) = 0.5f;
    M2C_FIELD(arg0, f32 *, 0xA4) = 3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0xA0) = 0;
}
