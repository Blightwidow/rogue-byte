#include "m2c_macros.h"

void *PeaFindAsegLabel(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a2;
    void *var_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xA0);
    var_a2 = 0;
    if (temp_v1 > 0) {
        var_a0 = M2C_FIELD(arg0, void **, 0xA4);
loop_2:
        var_a2 += 1;
        if ((((M2C_FIELD(var_a0, s32 *, 4) ^ 0xB) != 0) ? 0 : (M2C_FIELD(var_a0, s32 *, 8) == arg1)) != 0) {
            return var_a0;
        }
        var_a0 += 0x10;
        if (var_a2 >= temp_v1) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
