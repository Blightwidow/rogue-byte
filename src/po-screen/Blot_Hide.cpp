#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void SetBlotBlots(s8 *, M2C_UNK);              /* extern */
s32 SetTimerTimers__FP5TIMER6TIMERS(s8 *, s32);   /* extern */

void Blot_Hide(s8 *arg0) {
    SetTimerTimers__FP5TIMER6TIMERS(arg0, 1);
    if (M2C_FIELD(arg0, s32 *, 0x78) == -1) {
        SetBlotBlots(arg0, 1);
    }
}

}
