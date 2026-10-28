#include "m2c_macros.h"

extern M2C_UNK D_002BAAE8;

s32 FIsCidDerivedFrom(s32 arg0, s32 arg1) {
    void *var_a0;

    var_a0 = (arg0 * 0x14) + &D_002BAAE8;
    if (var_a0 != NULL) {
loop_1:
        if (M2C_FIELD(var_a0, s32 *, 4) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0);
            if (var_a0 == NULL) {
                /* Duplicate return node #6. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_1;
        }
        return 1;
    }
    return 0;
}
