#include "m2c_macros.h"

s32 func_0019B0A8(void *arg0, void *arg1) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_v1;
    void *temp_a1;

    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x21))) {
        temp_a1 = M2C_FIELD(M2C_FIELD(arg1, void **, 4), void **, 0xEC);
        if (!(M2C_FIELD(temp_a1, s64 *, 0x70) & 4)) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0);
            var_v1 = 0;
            if (temp_v0 > 0) {
                var_a0 = M2C_FIELD(arg0, s32 **, 4);
loop_7:
                var_v1 += 1;
                if (temp_a1 != *var_a0) {
                    var_a0 += 4;
                    if (var_v1 >= temp_v0) {
                        /* Duplicate return node #9. Try simplifying control flow for better match */
                        return 1;
                    }
                    goto loop_7;
                }
                /* Duplicate return node #4. Try simplifying control flow for better match */
                return 0;
            }
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
