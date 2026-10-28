#include "m2c_macros.h"

extern f32 g_2ddf0c;

void func_00212A30(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x58) == 2) {
        M2C_FIELD(arg0, f32 *, 0x5C) = (f32) g_2ddf0c;
    }
}
