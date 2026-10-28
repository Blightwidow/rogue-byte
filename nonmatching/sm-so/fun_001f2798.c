#include "m2c_macros.h"

void *func_001F2798(void *arg0) {
    s32 temp_v1;
    void *temp_v0;
    void *var_a0;
    void *var_a1;

    var_a0 = arg0;
    var_a1 = NULL;
loop_1:
    if ((var_a0 != NULL) && ((var_a1 = var_a0, temp_v0 = M2C_FIELD(var_a0, void **, 0xE8), (temp_v0 == NULL)) || ((temp_v1 = M2C_FIELD(temp_v0, s32 *, 0xC0), (temp_v1 == 3)) && (M2C_FIELD(temp_v0, s32 *, 0xA0) == temp_v1)))) {
        if (!(M2C_FIELD(var_a1, s64 *, 0x148) & (0x8000 << 0x13))) {
            var_a0 = M2C_FIELD(var_a1, void **, 0x10);
            goto loop_1;
        }
    }
    return var_a1;
}
