#include "m2c_macros.h"

s128 VecVelocityAtPos();                            /* extern */

void func_001FADD0(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    if (M2C_FIELD(arg0, s32 *, 0xE8) == 0) {
        M2C_FIELD(arg3, s32 *, 0) = 0;
        M2C_FIELD(arg3, s32 *, 8) = 0;
        M2C_FIELD(arg3, s32 *, 4) = 0;
        return;
    }
    M2C_FIELD(arg3, s32 *, 0) = VecVelocityAtPos();
}
