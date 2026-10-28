#include "m2c_macros.h"

void *PalertEnsure();                               /* extern */

void func_001F82B8(s32 arg1, s32 arg2) {
    M2C_FIELD(PalertEnsure(), s32 *, 0x10) = arg1;
    if (arg2 != 0) {
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($s1) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($s1) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x1b($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x14($v0) */);
    }
}
