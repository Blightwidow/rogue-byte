#include "m2c_macros.h"

extern f32 g_2dded0;

void GoalFollowCrv_SetState(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x4C)) {
        M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) g_2dded0;
    }
}
