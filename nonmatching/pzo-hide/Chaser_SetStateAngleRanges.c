#include "m2c_macros.h"

void Chaser_SetStateAngleRanges(s32 arg0, u32 arg1) {
    if (arg1 < 5U) {
        M2C_FIELD((arg0 + ((arg1 * 0x28) + 0x270)), s32 *, 4) = 1;
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a2) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($a2) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x1f($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x18($v0) */);
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x27($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x20($v0) */);
    }
}
