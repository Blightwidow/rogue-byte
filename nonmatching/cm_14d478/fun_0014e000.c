#include "m2c_macros.h"

s32 func_0014E000(void **arg0, void **arg1) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_v0;
    void *temp_a0;
    void *temp_a2;

    temp_a2 = *arg0;
    temp_a0 = *arg1;
    var_v0 = M2C_FIELD(temp_a0, s32 *, 0x110) - M2C_FIELD(temp_a2, s32 *, 0x110);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(temp_a0, s32 *, 0xE4) - M2C_FIELD(temp_a2, s32 *, 0xE4);
        if (var_v0 == 0) {
            temp_f1 = M2C_FIELD(temp_a2, f32 *, 0x114);
            temp_f0 = M2C_FIELD(temp_a0, f32 *, 0x114);
            var_v0 = -1;
            if (!(temp_f1 < temp_f0)) {
                if (temp_f0 < temp_f1) {
                    return 1;
                }
                return (s32) ((temp_a2 - temp_a0) * 0x38E38E39) >> 5;
            }
        }
    }
    return var_v0;
}
