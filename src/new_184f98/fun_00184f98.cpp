#include "m2c_macros.h"

s128 PosLoWorld();                                  /* extern */
extern f32 g_2be910;

void func_00184F98(s32 arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg2, s128 *, 0) = PosLoWorld();
    M2C_FIELD(arg2, f32 *, 8) = (f32) (M2C_FIELD(arg2, f32 *, 8) + g_2be910);
}
