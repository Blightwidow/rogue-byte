#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(s32, s32, s32);             /* extern */
s32 PvAllocSwImpl__Fi(void *);                      /* extern */

s32 PvAllocSwCopyImpl__FiPv(s32 *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_v0;

    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($s1) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($s1) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    temp_v0 = PvAllocSwImpl__Fi(sp);
    if (temp_v0 != 0) {
        CopyAb__FPvT0Ui(temp_v0, arg1, *arg0);
    }
    return temp_v0;
}
