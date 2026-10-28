#include "m2c_macros.h"

void AddProxySlotSource(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    s32 temp_a0;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xF0);
    if (temp_a0 < 8) {
        M2C_FIELD(arg0, s32 *, 0xF0) = (s32) (temp_a0 + 1);
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xF4) + (temp_a0 * 0x10);
        M2C_FIELD(temp_v0, f32 *, 0xC) = fparg0;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) arg2;
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) arg3;
    }
}
