#include "m2c_macros.h"

M2C_UNK func_00162250(s32, s32, s32, M2C_UNK);      /* extern */

void ApplyTaskAnims(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    s32 var_s1;

    if (arg2 > 0) {
        var_s1 = arg3;
        var_s0 = arg2;
        do {
            func_00162250(arg0, var_s1, arg1, M2C_ERROR(/* Read from unset register $t0 */));
            var_s0 -= 1;
            var_s1 += 0x18;
        } while (var_s0 != 0);
    }
}
