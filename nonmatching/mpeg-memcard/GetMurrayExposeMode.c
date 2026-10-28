#include "m2c_macros.h"

s32 func_001409B8();                                /* extern */

s32 GetMurrayExposeMode(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = func_001409B8();
    var_v0 = temp_v0;
    if (temp_v0 == -1) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
        if (temp_v1 == 9) {
            var_v0 = (M2C_FIELD(arg0, s32 *, 0x17F4) == 0) ? temp_v0 : 1;
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        }
        if (temp_v1 < 0xA) {
            if (temp_v1 != 1) {
                return -1;
            }
            goto block_8;
        }
        var_v0 = -1;
        if (temp_v1 == 0xC) {
block_8:
            return 1;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
