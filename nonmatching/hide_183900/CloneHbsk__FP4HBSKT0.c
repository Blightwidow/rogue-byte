#include "m2c_macros.h"

M2C_UNK CloneSo();                                  /* extern */

s32 CloneHbsk__FP4HBSKT0(s32 arg0) {
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x17b($s0) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x174($s0) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    CloneSo();
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x17b($s0) */);
    return M2C_ERROR(/* unknown instruction: sdr $v0, 0x174($s0) */);
}
