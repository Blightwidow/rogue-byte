#include "m2c_macros.h"

s32 func_001FD080(void *arg0, s32 arg1) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 0xF0);
    if (var_v0 != NULL) {
loop_2:
        if (var_v0 != arg1) {
            var_v0 = M2C_FIELD(var_v0, void **, 0x44);
            if (var_v0 == NULL) {
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return ((M2C_FIELD(arg0, s32 *, 0xF4) ^ arg1) == 0) ? 0 : 2;
            }
            goto loop_2;
        }
        return 1;
    }
    return ((M2C_FIELD(arg0, s32 *, 0xF4) ^ arg1) == 0) ? 0 : 2;
}
