#include "m2c_macros.h"

void *PgFindCrvExcludedRange(void *arg0, f32 fparg0) {
    s32 temp_a1;
    s32 var_v0;
    s32 var_v1;
    void *var_a0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xC);
    var_v1 = 0;
    if (temp_a1 > 0) {
        var_a0 = arg0 + 0x10;
loop_2:
        var_v1 += 1;
        if (M2C_FIELD(var_a0, f32 *, 0) <= fparg0) {
            var_v0 = var_v1 < temp_a1;
            if (fparg0 <= M2C_FIELD(var_a0, f32 *, 4)) {
                return var_a0;
            }
            goto block_6;
        }
        var_v0 = var_v1 < temp_a1;
block_6:
        var_a0 += 8;
        if (var_v0 == 0) {
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return NULL;
        }
        goto loop_2;
    }
    return NULL;
}
