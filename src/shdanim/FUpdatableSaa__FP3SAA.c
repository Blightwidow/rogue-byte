#include "m2c_macros.h"

extern f32 g_2dded0;

s32 FUpdatableSaa__FP3SAA(void *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x10) != g_2dded0) {
        M2C_FIELD(arg0, f32 *, 0x10) = (f32) g_2dded0;
        return 1;
    }
    return 0;
}
