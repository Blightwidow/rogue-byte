#include "m2c_macros.h"

s32 FAddAshOid(u32 *arg0, s32 arg1, s32 arg2) {
    u32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < 8U) {
        M2C_FIELD((arg0 + (temp_v1 * 8)), s32 *, 4) = arg1;
        M2C_FIELD((arg0 + (*arg0 * 8)), s32 *, 8) = arg2;
        *arg0 += 1;
        return 1;
    }
    return 0;
}
