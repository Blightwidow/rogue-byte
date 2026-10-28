#include "m2c_macros.h"

void CopyAqw__FPvT0i(s128 *arg0, s128 *arg1, s32 arg2) {
    s128 *var_a3;
    s128 *var_t0;
    s128 temp_a1;
    s128 temp_v0_2;
    s128 temp_v0_3;
    s128 temp_v1;
    s32 temp_t2;
    s32 temp_v0;
    s32 var_t1;
    s32 var_t1_2;

    temp_v0 = arg2 & 3;
    var_t0 = arg0;
    var_a3 = arg1;
    temp_t2 = arg2 - temp_v0;
    if (temp_v0 != 0) {
        var_t1 = temp_v0;
        do {
            temp_v0_2 = *var_a3;
            var_t1 -= 1;
            var_a3 += 0x10;
            *var_t0 = temp_v0_2;
            var_t0 += 0x10;
        } while (var_t1 != 0);
    }
    var_t1_2 = 0;
    if (temp_t2 > 0) {
        do {
            var_t1_2 += 4;
            temp_a1 = M2C_FIELD(var_a3, s128 *, 0x10);
            temp_v0_3 = M2C_FIELD(var_a3, s128 *, 0x20);
            temp_v1 = M2C_FIELD(var_a3, s128 *, 0x30);
            M2C_FIELD(var_t0, s128 *, 0) = M2C_FIELD(var_a3, s128 *, 0);
            var_a3 += 0x40;
            M2C_FIELD(var_t0, s128 *, 0x10) = temp_a1;
            M2C_FIELD(var_t0, s128 *, 0x20) = temp_v0_3;
            M2C_FIELD(var_t0, s128 *, 0x30) = temp_v1;
            var_t0 += 0x40;
        } while (var_t1_2 < temp_t2);
    }
}
