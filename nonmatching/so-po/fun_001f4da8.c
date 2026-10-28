#include "m2c_macros.h"

M2C_UNK FreeSwMqList__FP2SWP2MQ(M2C_UNK *, void *); /* extern */
M2C_UNK func_001F5078(void **, void *);             /* extern */
extern M2C_UNK B_003DD490;

void func_001F4DA8(s32 arg0, s32 arg1, void **arg2) {
    void **var_a2;
    void *temp_a3;
    void *var_s0;

    var_a2 = arg2;
    var_s0 = NULL;
loop_1:
    temp_a3 = *var_a2;
    if (temp_a3 != NULL) {
        if (M2C_FIELD((temp_a3 + ((M2C_FIELD(temp_a3, s32 *, 8) == arg0) << 6)), s32 *, 8) != arg1) {
            var_a2 = temp_a3 + 0xAC;
        } else {
            *var_a2 = M2C_FIELD(temp_a3, void **, 0xAC);
            M2C_FIELD(temp_a3, void **, 0xAC) = var_s0;
            var_s0 = temp_a3;
        }
        goto loop_1;
    }
    if (var_s0 != NULL) {
        func_001F5078(var_a2, temp_a3);
        FreeSwMqList__FP2SWP2MQ(&B_003DD490, var_s0);
    }
}
