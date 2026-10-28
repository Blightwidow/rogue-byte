#include "m2c_macros.h"

M2C_UNK SetBlotBlots(void *, M2C_UNK);              /* extern */
M2C_UNK SetTimerTimers__FP5TIMER6TIMERS(M2C_UNK);   /* extern */

void Blot_Hide(void *arg0) {
    SetTimerTimers__FP5TIMER6TIMERS(1);
    if (M2C_FIELD(arg0, s32 *, 0x78) == -1) {
        SetBlotBlots(arg0, 1);
    }
}
