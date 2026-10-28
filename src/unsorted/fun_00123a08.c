#include "m2c_macros.h"

extern f32 g_2dded0;

void *func_00123A08(void *arg0) {
    M2C_FIELD(arg0, f32 *, 4) = (f32) g_2dded0;
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    return arg0;
}
