#include "m2c_macros.h"

void func_001F6BC8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_a3;
    s32 var_t0;
    void *temp_v0;

    var_a3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_t0 = 0;
        do {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0xE4) + var_t0;
            if (M2C_FIELD(temp_v0, s32 *, 0xC) == arg1) {
                M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
            }
            var_a3 += 1;
            var_t0 += 0xB0;
        } while (var_a3 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
}
