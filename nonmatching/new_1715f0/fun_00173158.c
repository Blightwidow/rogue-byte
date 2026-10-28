#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */

void func_00173158(void *arg0) {
    InitLo();
    M2C_FIELD(arg0, f32 *, 0x80) = 5500.0f;
    M2C_FIELD(arg0, f32 *, 0xA4) = 50.0f;
    M2C_FIELD(arg0, s32 *, 0x84) = 1;
    M2C_FIELD(arg0, f32 *, 0xA0) = 30.0f;
    M2C_FIELD(arg0, s32 *, 0x88) = 1;
    M2C_FIELD(arg0, s32 *, 0x8C) = 1;
}
