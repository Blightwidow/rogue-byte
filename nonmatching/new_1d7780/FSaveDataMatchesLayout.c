#include "m2c_macros.h"

s32 FSaveDataMatchesLayout(void *arg0, void *arg1) {
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    u8 *var_a1;
    u8 temp_v0;

    var_a2 = 0;
    var_v1 = M2C_FIELD(arg0, s32 *, 0) * 0xA;
    var_a1 = M2C_FIELD(arg0, u8 **, 4);
    if (var_v1 != 0) {
        do {
            temp_v0 = *var_a1;
            var_v1 -= 1;
            var_a1 += 1;
            var_a2 += temp_v0;
        } while (var_v1 != 0);
    }
    var_a3 = 0;
    if (M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0) * 0xA) + M2C_FIELD(arg0, u8 **, 4)), u16 *, -6) == M2C_FIELD(arg1, s32 *, 0x5400)) {
        var_a3 = var_a2 == M2C_FIELD(arg1, s32 *, 0x5404);
    }
    return var_a3;
}
