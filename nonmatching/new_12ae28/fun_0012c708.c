#include "m2c_macros.h"

s32 func_0012C708(void *arg0, f32 fparg0) {
    f32 *var_a0;
    s32 temp_v1;
    s32 var_a1;
    void *temp_a0;

    var_a1 = 1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 4) - 1;
    if (temp_v1 > 1) {
        temp_a0 = M2C_FIELD(arg0, void **, 8);
        var_a0 = temp_a0 + 4;
        if (!(fparg0 < M2C_FIELD(temp_a0, f32 *, 4))) {
            var_a1 = 2;
loop_3:
            var_a0 += 4;
            if (var_a1 < temp_v1) {
                if (!(fparg0 < *var_a0)) {
                    var_a1 += 1;
                    goto loop_3;
                }
            }
        }
    }
    return var_a1;
}
