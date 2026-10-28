#include "m2c_macros.h"

s32 FSpriteHasLabel(s32 arg0, void *arg1, s32 arg2) {
    s32 *var_a1;
    s32 var_v1;
    u16 temp_a0;

    if (arg2 != -1) {
        temp_a0 = M2C_FIELD(arg1, u16 *, 0);
        var_v1 = 0;
        if (temp_a0 != 0) {
            var_a1 = M2C_FIELD(arg1, s32 *, 4) + 0x14;
loop_7:
            var_v1 += 1;
            if (arg2 != *var_a1) {
                var_a1 += 0x18;
                if (var_v1 >= (s32) temp_a0) {
                    /* Duplicate return node #9. Try simplifying control flow for better match */
                    return 0;
                }
                goto loop_7;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
