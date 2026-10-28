#include "m2c_macros.h"

M2C_UNK InitSaa();                                  /* extern */

void InitScroller__FP8SCROLLERP4SAAF(void *arg0, void *arg1) {
    InitSaa();
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(arg1, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) M2C_FIELD(arg1, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 0x60) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg1, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x64) = 1.0f;
}
