#include "m2c_macros.h"

s32 PentryFindSensorLo();                           /* extern */
M2C_UNK SetSensorEntryState(s32, s32, s32);         /* extern */

void func_00154038(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = PentryFindSensorLo();
    if (temp_v0 != 0) {
        SetSensorEntryState(arg0, temp_v0, arg2);
    }
}
