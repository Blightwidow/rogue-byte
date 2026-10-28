#include "m2c_macros.h"

extern M2C_UNK RO_002A4BE0;

M2C_UNK *PchzStringFromId(void *arg0, s32 arg1) {
    s32 *var_a0;
    s32 *var_v1;
    s32 temp_v0;
    s32 var_a2;

    if (arg1 != -1) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x4640);
        var_a2 = 0;
        if (temp_v0 > 0) {
            var_a0 = M2C_FIELD(arg0, s32 **, 0x4644);
            var_v1 = var_a0;
loop_7:
            var_a2 += 1;
            if (*var_v1 != arg1) {
                var_v1 += 8;
                var_a0 += 8;
                if (var_a2 >= temp_v0) {
                    /* Duplicate return node #9. Try simplifying control flow for better match */
                    return &RO_002A4BE0;
                }
                goto loop_7;
            }
            return M2C_FIELD(var_a0, M2C_UNK **, 4);
        }
        return &RO_002A4BE0;
    }
    return &RO_002A4BE0;
}
