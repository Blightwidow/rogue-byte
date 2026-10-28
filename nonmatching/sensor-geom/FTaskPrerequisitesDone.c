#include "m2c_macros.h"

s32 FTaskPrerequisitesDone(void *arg0) {
    s32 temp_v1;
    s32 var_a3;
    s32 var_t0;
    void **var_a2;
    void *var_a1;

    var_t0 = 1;
    var_a3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x94) > 0) {
        var_a2 = M2C_FIELD(arg0, void ***, 0x98);
        var_a1 = *var_a2;
loop_2:
        temp_v1 = M2C_FIELD(var_a1, s32 *, 0x54);
        var_t0 = 0;
        if ((temp_v1 >= 2) || ((temp_v1 == 1) && (M2C_FIELD(var_a1, s32 *, 0x6C) != 0))) {
            var_t0 = 1;
        }
        var_a2 += 4;
        var_a3 += 1;
        if (var_t0 != 0) {
            if (var_a3 < M2C_FIELD(arg0, s32 *, 0x94)) {
                var_a1 = *var_a2;
                goto loop_2;
            }
        }
    }
    return var_t0;
}
