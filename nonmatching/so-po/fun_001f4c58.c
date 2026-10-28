#include "m2c_macros.h"

void *func_001F4C58(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a3;
    s32 var_v0;
    s32 var_v1;
    void *var_a0;

    temp_a3 = M2C_FIELD(arg0, s32 *, 0x50);
    var_v1 = 0;
    if (temp_a3 > 0) {
        var_a0 = M2C_FIELD(arg0, void **, 0x54);
loop_2:
        var_v1 += 1;
        if (M2C_FIELD(var_a0, s32 *, 0x9C) == arg1) {
            var_v0 = var_v1 < temp_a3;
            if (M2C_FIELD(var_a0, s32 *, 0x94) == arg2) {
                return var_a0;
            }
            goto block_6;
        }
        var_v0 = var_v1 < temp_a3;
block_6:
        var_a0 += 0x100;
        if (var_v0 == 0) {
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
