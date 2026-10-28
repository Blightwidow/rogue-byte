#include "m2c_macros.h"

s32 func_00143C78();                                /* extern */

s32 NMurrayActionCategory(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x204) == 0) {
        if ((M2C_FIELD(arg0, s32 *, 0x13D8) == 1) || (M2C_FIELD(arg0, s32 *, 0x13D0) == 0x14)) {
            return 0;
        }
        var_v0 = func_00143C78();
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
