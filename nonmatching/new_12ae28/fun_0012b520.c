#include "m2c_macros.h"

void func_0012B520(void *arg0, void *arg1) {
    void *temp_a3;
    void *temp_t0;

    M2C_FIELD(arg1, s16 *, 0x9A) = 2;
    temp_a3 = arg1 + 0xD0;
    M2C_FIELD(arg1, f32 *, 0x84) = 1.0f;
    temp_t0 = arg1 + 0xF0;
    M2C_FIELD(arg1, s32 *, 0x88) = (s32) (arg1 + 0x80);
    M2C_FIELD(arg1, s32 *, 0x8C) = (s32) (arg1 + 0x84);
    M2C_FIELD(arg1, s32 *, 0x80) = 0;
    M2C_ERROR(/* unknown instruction: ldl $v0, 0xb($a0) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x4($a0) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0xc7($a1) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, 0xc0($a1) */);
    M2C_FIELD(arg1, s32 *, 0xC8) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg1, s128 *, 0xE0) = (s128) M2C_FIELD(arg1, s128 *, 0xC0);
    M2C_FIELD(temp_a3, s32 *, 4) = 0;
    M2C_FIELD(temp_a3, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0xD0) = 0;
    M2C_FIELD(temp_t0, s32 *, 4) = 0;
    M2C_FIELD(temp_t0, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0xF0) = 0;
}
