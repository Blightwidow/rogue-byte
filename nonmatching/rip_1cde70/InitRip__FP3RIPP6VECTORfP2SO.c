#include "m2c_macros.h"

extern s128 D_002C1F50;
extern M2C_UNK RO_002A2D00;
extern f32 g_2dded0;

void InitRip__FP3RIPP6VECTORfP2SO(void *arg0, s128 arg1, s32 arg2, f32 fparg0) {
    M2C_FIELD(arg0, s32 *, 0xE0) = arg2;
    M2C_FIELD(arg0, f32 *, 0x18) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) g_2dded0;
    M2C_FIELD(arg0, f32 *, 0x20) = fparg0;
    M2C_FIELD(arg0, s128 *, 0x70) = arg1;
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) D_002C1F50;
    M2C_FIELD(arg0, s128 *, 0x80) = arg1;
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(&RO_002A2D00, s128 *, 0x20);
}
