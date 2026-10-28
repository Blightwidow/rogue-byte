#include "m2c_macros.h"

M2C_UNK memset(s32, M2C_UNK, s32);                  /* extern */

s32 PvAllocSlotheapClearImpl__FP8SLOTHEAP(void **arg0, s32 arg1) {
    s32 temp_v0;
    void *temp_a3;

    temp_v0 = M2C_FIELD(temp_a3, s32 (**)(void *, void *), 0xC)(arg0 + M2C_FIELD(temp_a3, s16 *, 8), temp_a3);
    temp_a3 = *arg0;
    memset(temp_v0, 0, arg1);
    return temp_v0;
}
