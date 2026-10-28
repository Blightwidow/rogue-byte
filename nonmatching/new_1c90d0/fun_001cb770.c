#include "m2c_macros.h"

s32 func_001CB770(void *arg0, s32 arg1) {
    s32 *var_a0;
    s32 temp_a2;
    s32 var_v1;

    temp_a2 = M2C_FIELD(arg0, s32 *, 0x3F04);
    var_v1 = 0;
    if (temp_a2 > 0) {
        var_a0 = M2C_FIELD(arg0, s32 *, 0x3F08) + 0x10;
loop_2:
        if (*var_a0 != arg1) {
            var_v1 += 1;
            var_a0 += 0x6C;
            if (var_v1 >= temp_a2) {
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return -1;
            }
            goto loop_2;
        }
        return var_v1;
    }
    return -1;
}
