#include "m2c_macros.h"

void AddProxySnd(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    s32 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xE4);
    if (temp_v1 < 8) {
        M2C_FIELD(arg0, s32 *, 0xE4) = (s32) (temp_v1 + 1);
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xE8) + (temp_v1 * 0x14);
        M2C_FIELD(temp_v0, f32 *, 0x10) = fparg1;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) arg2;
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) arg3;
        M2C_FIELD(temp_v0, f32 *, 0xC) = fparg0;
    }
}
