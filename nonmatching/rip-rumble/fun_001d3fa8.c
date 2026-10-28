#include "m2c_macros.h"

void *func_001D3FA8(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    void **var_a0;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x4F8);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_a0 = arg0 + 0x4FC;
loop_2:
        temp_v1 = *var_a0;
        var_a2 += 1;
        if (M2C_FIELD(temp_v1, s32 *, 0x14) == arg1) {
            return temp_v1;
        }
        var_a0 += 4;
        if (var_a2 >= temp_v0) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
