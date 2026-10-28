#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, s32);                  /* extern */

s32 func_00208B38(void *arg0, s32 arg1) {
    s32 *var_s0;
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3C0) > 0) {
        var_s0 = arg0 + 0x3C4;
loop_2:
        var_v0 = 1;
        if (FIsBasicDerivedFrom(arg1, *var_s0) == 0) {
            var_s1 += 1;
            var_s0 += 4;
            if (var_s1 >= M2C_FIELD(arg0, s32 *, 0x3C0)) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_v0 = 0;
    }
    return var_v0;
}
