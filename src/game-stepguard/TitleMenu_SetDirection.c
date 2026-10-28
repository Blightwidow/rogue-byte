#include "m2c_macros.h"

extern f32 g_2ddf0c;

void TitleMenu_SetDirection(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x28)) {
        M2C_FIELD(arg0, s32 *, 0x28) = arg1;
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) g_2ddf0c;
    }
}
