#include "m2c_macros.h"

M2C_UNK memset(s32 *, M2C_UNK, M2C_UNK);            /* extern */
extern s32 B_002E1E68;

s32 *PentryAddBootQueue(u32 *arg0, s32 arg1) {
    s32 *temp_s0;
    u32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < 0x10U) {
        *arg0 = temp_v1 + 1;
        temp_s0 = arg0 + ((temp_v1 * 0x1C) + 4);
        memset(temp_s0, 0, 0x1C);
        *temp_s0 = arg1;
        return temp_s0;
    }
    return &B_002E1E68;
}
