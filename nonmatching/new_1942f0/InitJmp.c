#include "m2c_macros.h"

extern s128 D_002BF740;

void InitJmp(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s128 *, 0xF0) = (s128) D_002BF740;
    M2C_FIELD(arg0, f32 *, 0x164) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x108) = -60.0f;
    M2C_FIELD(arg0, f32 *, 0x10C) = -50.0f;
    M2C_FIELD(arg0, f32 *, 0x114) = 50.0f;
    M2C_FIELD(arg0, f32 *, 0x11C) = 75.0f;
    M2C_FIELD(arg0, f32 *, 0x118) = -150.0f;
    M2C_FIELD(arg0, f32 *, 0x110) = 75.0f;
}
