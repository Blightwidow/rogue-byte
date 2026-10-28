#include "m2c_macros.h"

s32 GetThreadId();                                  /* extern */
M2C_UNK WaitSema(s32);                              /* extern */

void EnterCritSect__FP8CRITSECT(void *arg0) {
    s32 temp_v0;

    temp_v0 = GetThreadId();
    if (temp_v0 == M2C_FIELD(arg0, s32 *, 4)) {
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) + 1);
        return;
    }
    WaitSema(M2C_FIELD(arg0, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 4) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0) = 1;
}
