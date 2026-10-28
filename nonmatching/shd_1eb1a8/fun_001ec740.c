#include "m2c_macros.h"

extern M2C_UNK B_003DA798;

void func_001EC740(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 var_a0;
    u32 temp_a1;
    void *var_v1;

    if (arg0 < arg1) {
        var_a0 = arg1 - arg0;
        var_v1 = (arg0 * 0x14) + &B_003DA798;
        do {
            temp_a1 = M2C_FIELD(var_v1, u32 *, 8);
            if ((temp_a1 >= arg3) && (temp_a1 < (u32) (arg3 + arg2))) {
                M2C_FIELD(var_v1, u32 *, 8) = (u32) (M2C_ERROR(/* Read from unset register $t0 */) + (temp_a1 - arg3));
            }
            var_a0 -= 1;
            var_v1 += 0x14;
        } while (var_a0 != 0);
    }
}
