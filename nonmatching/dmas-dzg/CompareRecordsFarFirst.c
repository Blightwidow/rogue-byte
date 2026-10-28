#include "m2c_macros.h"

s32 func_00157A50(void **arg0, void **arg1) {
    f32 temp_f0;
    f32 temp_f1;
    void *temp_a0;
    void *temp_v0;

    temp_a0 = *arg0;
    temp_v0 = *arg1;
    temp_f1 = M2C_FIELD(temp_a0, f32 *, 4);
    temp_f0 = M2C_FIELD(temp_v0, f32 *, 4);
    if (temp_f0 < temp_f1) {
        return -1;
    }
    if (!(temp_f1 < temp_f0)) {
        return (s32) (temp_a0 - temp_v0) >> 4;
    }
    return 1;
}
