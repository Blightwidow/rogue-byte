#include "m2c_macros.h"

s32 func_001B1B10(s32);                             /* extern */

void func_001B1B18(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    if ((func_001B1B10(arg1) != 0) && (arg1 != 2) && (arg1 != 5)) {
        temp_v0 = arg0 + ((arg1 * 0xC) + 0x17C);
        M2C_FIELD(temp_v0, s32 *, 0) = arg2;
        if (arg3 != -1) {
            M2C_FIELD(temp_v0, s32 *, 8) = arg3;
        }
    }
}
