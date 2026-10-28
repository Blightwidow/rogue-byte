#include "m2c_macros.h"

s32 *func_001F0458(void *arg0, s32 arg1) {
    s32 *var_a0;
    s32 temp_a2;
    s32 var_v1;

    temp_a2 = M2C_FIELD(arg0, s32 *, 0x60);
    var_v1 = 0;
    if (temp_a2 > 0) {
        var_a0 = M2C_FIELD(arg0, s32 **, 0x64);
loop_2:
        var_v1 += 1;
        if (*var_a0 & arg1) {
            return var_a0;
        }
        var_a0 += 8;
        if (var_v1 >= temp_a2) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
