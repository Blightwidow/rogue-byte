#include "m2c_macros.h"

M2C_UNK SetRumbleRums__FP6RUMBLE4RUMS(); /* extern */

void InitRumble__FP6RUMBLEii(void *arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        SetRumbleRums__FP6RUMBLE4RUMS((void *)1);
    } else {
        SetRumbleRums__FP6RUMBLE4RUMS(arg0, 3);
    }
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
}
