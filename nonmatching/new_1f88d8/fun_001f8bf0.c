#include "m2c_macros.h"

void func_001F8BF0(void *arg0, s32 arg1, s128 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    void *temp_a0;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a0, s16 *, 0x98) == 0x10) {
        temp_v0 = M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xA8), void **, 0x60);
        M2C_FIELD(temp_v0, s128 *, 0x20) = arg2;
        M2C_FIELD(temp_v0, s32 *, 8) = arg1;
        M2C_FIELD(temp_v0, f32 *, 0xC) = fparg0;
        M2C_FIELD(temp_v0, f32 *, 0x10) = fparg1;
        M2C_FIELD(temp_v0, f32 *, 0x14) = fparg2;
        M2C_FIELD(temp_v0, f32 *, 0x18) = (f32) (fparg3 * 0.017453294f);
    }
}
