#include "m2c_macros.h"

s32 FReconTargetPickable(void *arg0) {
    s32 var_v0;
    void *temp_a0;
    void *temp_v0;

    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x100);
        if ((temp_v0 == NULL) || !(((u64) M2C_FIELD(temp_v0, u64 *, 0x28) >> 0x3C) & 1)) {
            temp_a0 = M2C_FIELD(arg0, void **, 0xEC);
            if ((temp_a0 == NULL) || (var_v0 = 0, (M2C_FIELD(temp_a0, s32 *, 0x54) == 1))) {
                var_v0 = 1;
            }
            return var_v0;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
