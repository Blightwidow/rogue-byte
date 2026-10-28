#include "m2c_macros.h"

M2C_UNK SetAlertState(M2C_UNK);                     /* extern */
extern f32 g_2dded0;

void AddAlertGuard(void *arg0, s32 arg1) {
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        M2C_FIELD(arg0, f32 *, 0) = (f32) g_2dded0;
        SetAlertState(0);
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x2C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (temp_v1 + 1);
}
