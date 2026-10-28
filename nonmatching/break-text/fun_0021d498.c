#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */

s32 func_0021D498(s32 arg0) {
    M2C_ERROR(/* unknown instruction: ldl $v0, 0xe7($s0) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0xe0($s0) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    CloneXfm();
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0xe7($s0) */);
    return M2C_ERROR(/* unknown instruction: sdr $v0, 0xe0($s0) */);
}
