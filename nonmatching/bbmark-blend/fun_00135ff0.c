#include "m2c_macros.h"

s32 func_00135FF0(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
    if (temp_v1 != 5) {
        if (temp_v1 < 6) {
            if (temp_v1 < 2) {
                if (temp_v1 >= 0) {
                    return 1;
                }
                /* Duplicate return node #8. Try simplifying control flow for better match */
                return 0;
            }
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return 0;
        }
        if (temp_v1 == 7) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 1;
        }
        return 0;
    }
    return 1;
}
