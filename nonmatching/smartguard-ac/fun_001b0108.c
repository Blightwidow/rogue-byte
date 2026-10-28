#include "m2c_macros.h"

s32 func_001B0078();                                /* extern */

s32 func_001B0108(void) {
    s32 temp_v0;

    temp_v0 = func_001B0078();
    if (temp_v0 != 0x19) {
        if (temp_v0 >= 0x19) {
            if (temp_v0 < 0x20) {
                if (temp_v0 >= 0x1E) {
                    goto block_4;
                }
                /* Duplicate return node #6. Try simplifying control flow for better match */
                return 0;
            }
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
        return 0;
    }
block_4:
    return 1;
}
