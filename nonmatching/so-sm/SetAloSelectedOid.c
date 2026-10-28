#include "m2c_macros.h"

void SetAloSelectedOid(void *arg0, s32 arg1) {
    s32 *var_a2;
    s32 temp_v0;
    s32 var_v1;

    if (arg1 != -1) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xAC);
        var_v1 = 0;
        if (temp_v0 > 0) {
            var_a2 = M2C_FIELD(arg0, s32 **, 0xB0);
loop_7:
            if (arg1 != *var_a2) {
                var_v1 += 1;
                var_a2 += 4;
                if (var_v1 >= temp_v0) {
                    /* Duplicate return node #3. Try simplifying control flow for better match */
                    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
                    return;
                }
                goto loop_7;
            }
            M2C_FIELD(arg0, s32 *, 0xB4) = (s32) -(var_v1 + 3);
            return;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        M2C_FIELD(arg0, s32 *, 0xB4) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
}
