#include "m2c_macros.h"

M2C_UNK PcmdAllocScript(M2C_UNK, M2C_UNK);          /* extern */

void func_00170BA0(s32 arg1) {
    PcmdAllocScript(2, -1);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($s0) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($s0) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0xf($v0) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, 0x8($v0) */);
}
