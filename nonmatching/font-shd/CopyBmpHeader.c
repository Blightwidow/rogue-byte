#include "m2c_macros.h"

void *CopyBmpHeader(void *arg0) {
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($a1) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($a1) */);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0xf($a1) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, 0x8($a1) */);
    M2C_ERROR(/* unknown instruction: ldl $a2, 0x17($a1) */);
    M2C_ERROR(/* unknown instruction: ldr $a2, 0x10($a1) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($a0) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($a0) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0xf($a0) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, 0x8($a0) */);
    M2C_ERROR(/* unknown instruction: sdl $a2, 0x17($a0) */);
    M2C_ERROR(/* unknown instruction: sdr $a2, 0x10($a0) */);
    M2C_FIELD(arg0, u32 *, 0x18) = (u32) ((u32) (M2C_FIELD(arg0, s32 *, 0x10) + 0xF) >> 4);
    return arg0;
}
