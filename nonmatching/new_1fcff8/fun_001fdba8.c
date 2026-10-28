#include "m2c_macros.h"

M2C_UNK func_002330D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s64); /* extern */

void func_001FDBA8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xA0) == 0) {
        M2C_FIELD(arg0, s32 *, 0xA0) = 1;
        func_002330D0(0x524B5553, 0xC, 0, 0, (s64) arg0);
    }
}
