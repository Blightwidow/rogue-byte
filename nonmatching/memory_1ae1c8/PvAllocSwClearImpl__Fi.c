#include "m2c_macros.h"

s32 PvAllocSwImpl__Fi(void *);                      /* extern */
M2C_UNK memset(s32, M2C_UNK, s32);                  /* extern */

s32 PvAllocSwClearImpl__Fi(s32 *arg0) {
    char sp[0x400];
    s32 temp_v0;

    M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($s1) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, ($s1) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
    temp_v0 = PvAllocSwImpl__Fi(sp);
    if (temp_v0 != 0) {
        memset(temp_v0, 0, *arg0);
    }
    return temp_v0;
}
