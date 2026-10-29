#include "m2c_macros.h"
extern "C" {

s32 PentryFindSensorLo(s32, s32);                           /* extern */
void SetSensorEntryState(s32, s32, s32);

void func_00154038(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = PentryFindSensorLo(arg0, arg1);
    if (temp_v0 != 0) {
        SetSensorEntryState(arg0, temp_v0, arg2);
    }
}
}
