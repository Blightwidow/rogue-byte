#include "m2c_macros.h"

extern M2C_UNK D_002C4430;

s32 VIFS_AddUnpackCommand(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_a1;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;

    var_t1 = arg1;
    if (var_t1 >= 0x10) {
        var_t1 &= 0xF;
        var_t0 = 0x60008000;
    } else {
        var_t0 = 0x6000C000;
    }
    var_t0_2 = var_t0 | (var_t1 << 0x18) | (arg2 << 0x10) | arg3;
    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        var_t0_2 |= 0x10000000;
    }
    temp_a1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a1 + 4);
    *temp_a1 = var_t0_2;
    return *((var_t1 * 4) + &D_002C4430) * arg2;
}
