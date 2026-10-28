#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(s32, s32, s32);             /* extern */

s32 PvAllocCopyImpl(void **arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    void *temp_t0;

    temp_t0 = *arg0;
    temp_v0 = M2C_FIELD(temp_t0, s32 (**)(void *, s32), 0xC)(arg0 + M2C_FIELD(temp_t0, s16 *, 8), arg3);
    CopyAb__FPvT0Ui(temp_v0, arg2, arg1);
    return temp_v0;
}
