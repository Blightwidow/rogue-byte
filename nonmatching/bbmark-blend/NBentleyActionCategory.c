#include "m2c_macros.h"

s32 func_00143C78();                                /* extern */

s32 NBentleyActionCategory(void *arg0) {
    s32 temp_v1;
    s32 var_v0;

    if (M2C_FIELD(arg0, s32 *, 0x204) == 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
        if (temp_v1 != 0xD) {
            if (temp_v1 < 0xE) {
                var_v0 = 5;
                if (temp_v1 != 8) {
                    goto block_9;
                }
            } else {
                var_v0 = 0xF;
                if (temp_v1 != 0xE) {
block_9:
                    var_v0 = func_00143C78();
                }
            }
            return var_v0;
        }
        goto block_3;
    }
block_3:
    return 0;
}
