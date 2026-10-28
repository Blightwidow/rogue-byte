#include "m2c_macros.h"

extern f32 g_2ddf0c;

void SetTimerTimers__FP5TIMER6TIMERS(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x64) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x64) = arg1;
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) g_2ddf0c;
    }
}
