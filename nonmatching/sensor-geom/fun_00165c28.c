#include "m2c_macros.h"

s32 func_00165C28(void **arg0, void **arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v1;
    void *temp_a0;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1_2;

    temp_a0 = *arg0;
    temp_a1 = *arg1;
    var_v0 = M2C_FIELD(temp_a0, s32 *, 0x104);
    var_v1 = M2C_FIELD(temp_a1, s32 *, 0x104);
    if (var_v0 == var_v1) {
        temp_v1_2 = M2C_FIELD(temp_a0, void **, 0x7C);
        var_v0 = -1;
        if (temp_v1_2 != NULL) {
            var_v0 = M2C_FIELD(temp_v1_2, s32 *, 0x18);
        }
        temp_a2 = M2C_FIELD(temp_a1, void **, 0x7C);
        var_v1 = -1;
        if (temp_a2 != NULL) {
            var_v1 = M2C_FIELD(temp_a2, s32 *, 0x18);
        }
        if (var_v0 == var_v1) {
            temp_v0 = M2C_FIELD(temp_a0, s32 *, 0x100);
            temp_v1 = M2C_FIELD(temp_a1, s32 *, 0x100);
            if (temp_v0 == temp_v1) {
                return M2C_FIELD(temp_a0, s32 *, 0x18) - M2C_FIELD(temp_a1, s32 *, 0x18);
            }
            return temp_v0 - temp_v1;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        return var_v0 - var_v1;
    }
    return var_v0 - var_v1;
}
