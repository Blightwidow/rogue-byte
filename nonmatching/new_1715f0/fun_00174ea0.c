#include "m2c_macros.h"

s32 func_001EEFA0(void *);                          /* extern */

s32 func_00174EA0(void *arg0) {
    s32 temp_v1;
    s32 var_v0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x40);
    if (M2C_FIELD(temp_a1, s32 *, 0) == 2) {
        temp_v1 = M2C_FIELD(M2C_FIELD(temp_a1, void **, 8), s32 *, 0x10);
        var_v0 = 7;
        if (temp_v1 != 0) {
            if ((temp_v1 >= 0) && (temp_v1 < 5)) {
                var_v0 = 1;
                if (temp_v1 >= 3) {
                    return 7;
                }
                /* Duplicate return node #8. Try simplifying control flow for better match */
                return var_v0;
            }
            return 1;
        }
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = func_001EEFA0(temp_a1);
    return var_v0;
}
