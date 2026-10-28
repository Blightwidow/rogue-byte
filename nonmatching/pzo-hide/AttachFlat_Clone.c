#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */

s32 AttachFlat_Clone(s32 arg0) {
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x10b($s0) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x104($s0) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    CloneXfm();
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x10b($s0) */);
    return M2C_ERROR(/* unknown instruction: sdr $v0, 0x104($s0) */);
}
