#include "m2c_macros.h"

s32 func_001409B8();                                /* extern */

s32 GetSlyExposeMode(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_001409B8();
    var_v0 = temp_v0;
    if (temp_v0 == -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x18C8);
        if (temp_a0 < 7) {
            if ((temp_a0 < 5) && (temp_a0 != 1)) {
                return -1;
            }
            goto block_6;
        }
        var_v0 = -1;
        if (temp_a0 == 9) {
block_6:
            var_v0 = 1;
        }
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
