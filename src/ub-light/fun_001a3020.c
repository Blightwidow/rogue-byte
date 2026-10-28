#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetTimerTimers__FP5TIMER6TIMERS(s32, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_001A3020(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x373, 0);
    *arg0 = temp_v0;
    if (temp_v0 != 0) {
        SetTimerTimers__FP5TIMER6TIMERS(temp_v0, 1);
    }
}
