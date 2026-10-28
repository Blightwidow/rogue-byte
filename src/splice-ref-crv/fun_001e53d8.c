#include "m2c_macros.h"

M2C_UNK StopJsg(s32);                               /* extern */

void func_001E53D8(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_a0 != 0) {
        StopJsg(temp_a0);
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
}
