#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E0840(s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x18, 1);
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
}
