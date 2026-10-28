#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
extern f32 D_FLT_002BDCD0;

void func_001564E8(void *arg0) {
    InitLo();
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_FLT_002BDCD0;
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($a2) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($a2) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x5f($s0) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, 0x58($s0) */);
    M2C_FIELD(arg0, f32 *, 0x60) = 0.25f;
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) | 0x40);
}
