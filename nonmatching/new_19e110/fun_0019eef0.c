#include "m2c_macros.h"

s32 FActiveCplcy(M2C_UNK *);                        /* extern */
extern M2C_UNK B_002DE2E0;
extern s32 g_2dfbc0;

s32 func_0019EEF0(void **arg0, s32 arg1) {
    s32 var_a0;

    if (arg1 == 3) {
        var_a0 = 0;
        if (M2C_FIELD(*arg0, s32 *, 0x12F0) != 0) {
            if (!(g_2dfbc0 & 2)) {
                return 0;
            }
            var_a0 = FActiveCplcy(&B_002DE2E0) == 0;
            goto block_6;
        }
block_6:
        return var_a0;
    }
    return 0;
}
