#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */

void func_001E1870(s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x4F, M2C_ERROR(/* Read from unset register $t2 */));
    M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_ERROR(/* Read from unset register $t1 */);
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x1C) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0x20) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
}
