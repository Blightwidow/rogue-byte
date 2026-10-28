#include "m2c_macros.h"

s32 *PentryFindSensorLo(void *arg0, s32 arg1) {
    s32 *var_a0;
    s32 *var_v1;
    s32 temp_v1;
    s32 var_a2;

    if (arg1 != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xFC);
        var_a2 = 0;
        if (temp_v1 > 0) {
            var_a0 = arg0 + 0x100;
            var_v1 = var_a0;
loop_7:
            var_a2 += 1;
            if (*var_v1 != arg1) {
                var_v1 += 0x10;
                var_a0 += 0x10;
                if (var_a2 >= temp_v1) {
                    /* Duplicate return node #9. Try simplifying control flow for better match */
                    return NULL;
                }
                goto loop_7;
            }
            return var_a0;
        }
        return NULL;
    }
    return NULL;
}
