#include "m2c_macros.h"

s32 IinstFindFreeSprite(void *arg0) {
    s16 *var_a0;
    s32 var_v1;
    u16 temp_a1;

    temp_a1 = M2C_FIELD(arg0, u16 *, 2);
    var_v1 = 0;
    if (temp_a1 != 0) {
        var_a0 = M2C_FIELD(arg0, s32 *, 8) + 8;
loop_2:
        if (*var_a0 >= 0) {
            var_v1 += 1;
            var_a0 += 0x18;
            if (var_v1 >= (s32) temp_a1) {
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_2;
        }
        return var_v1;
    }
    return 0;
}
