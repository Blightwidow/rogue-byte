#include "m2c_macros.h"

s32 TickReadCount(void *arg0) {
    u64 temp_a1;

    temp_a1 = M2C_ERROR(/* mfc0 Count */) & (-1U >> 0x20);
    if (temp_a1 < (u64) M2C_FIELD(arg0, u64 *, 0x50)) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + 1);
    }
    M2C_FIELD(arg0, u64 *, 0x50) = temp_a1;
    return ((s64) M2C_FIELD(arg0, s32 *, 0x58) << 0x20) | temp_a1;
}
