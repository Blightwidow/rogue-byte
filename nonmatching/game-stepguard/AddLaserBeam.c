#include "m2c_macros.h"

void AddLaserBeam(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    s32 temp_v1;
    void *temp_t1;
    void *temp_t1_2;
    void *temp_v0;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x198);
    if (temp_v1 < 0x40) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x19C) + (temp_v1 * 0x150);
        M2C_FIELD(temp_v0, f32 *, 0x18) = fparg0;
        temp_t1 = temp_v0 + 0x18;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_t1, s32 *, 0xC) = arg2;
        M2C_FIELD(temp_t1, f32 *, 4) = fparg1;
        M2C_FIELD(temp_t1, f32 *, 8) = fparg2;
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x19C) + (M2C_FIELD(arg0, s32 *, 0x198) * 0x150);
        M2C_FIELD(temp_v1_2, f32 *, 0xB8) = fparg3;
        temp_t1_2 = temp_v1_2 + 0xB8;
        M2C_FIELD(temp_v1_2, s32 *, 0xA0) = arg3;
        M2C_FIELD(temp_t1_2, s32 *, 0xC) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
        M2C_FIELD(temp_t1_2, f32 *, 4) = fparg4;
        M2C_FIELD(temp_t1_2, f32 *, 8) = fparg5;
        M2C_FIELD(arg0, s32 *, 0x198) = (s32) (M2C_FIELD(arg0, s32 *, 0x198) + 1);
    }
}
