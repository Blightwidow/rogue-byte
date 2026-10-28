#include "m2c_macros.h"

M2C_UNK CloneCrv();                                 /* extern */

s32 ClonePipe(s32 arg0) {
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x1bb($s0) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x1b4($s0) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    CloneCrv();
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x1bb($s0) */);
    return M2C_ERROR(/* unknown instruction: sdr $v0, 0x1b4($s0) */);
}
