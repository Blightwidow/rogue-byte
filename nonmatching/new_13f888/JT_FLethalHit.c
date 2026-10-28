#include "m2c_macros.h"

s32 JT_FLethalHit(void *arg0, void *arg1) {
    s32 temp_a1;

    if (-M2C_FIELD(arg1, s32 *, 0x10) >= M2C_FIELD(arg0, s32 *, 0xDFC)) {
        temp_a1 = M2C_FIELD(arg1, s32 *, 0xC);
        if (temp_a1 != 0x80000) {
            if (temp_a1 <= 0x80000) {
                if ((temp_a1 < 2) && (temp_a1 >= 0)) {
                    /* Duplicate return node #3. Try simplifying control flow for better match */
                    return 0;
                }
                /* Duplicate return node #10. Try simplifying control flow for better match */
                return 1;
            }
            if (temp_a1 != 0x100000) {
                return 1;
            }
            /* Duplicate return node #3. Try simplifying control flow for better match */
            return 0;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
