#include "m2c_macros.h"

void *func_001F8198(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    void **var_a0;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xA4);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_a0 = M2C_FIELD(arg0, void ***, 0xA8);
loop_2:
        temp_v1 = *var_a0;
        var_a2 += 1;
        if (M2C_FIELD(temp_v1, s32 *, 0x18) == arg1) {
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
