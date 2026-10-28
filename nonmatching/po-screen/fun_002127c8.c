#include "m2c_macros.h"

extern void *B_003E106C;
extern s32 g_2be538;

s32 func_002127C8(void) {
    s32 temp_v1;
    s32 var_v0_2;
    void *var_a0;
    void *var_v0;

    var_a0 = B_003E106C;
    if (var_a0 != NULL) {
        var_v0 = M2C_FIELD(var_a0, void **, 0x40);
loop_2:
        temp_v1 = M2C_FIELD(var_v0, s32 *, 0x58);
        switch (temp_v1) {                          /* irregular */
        case 0:
            var_a0 = M2C_FIELD(var_a0, void **, 0x4C);
block_13:
            if (var_a0 != NULL) {
                var_v0 = M2C_FIELD(var_a0, void **, 0x40);
                goto loop_2;
            }
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return 1;
        default:
            var_v0_2 = M2C_FIELD(var_v0, s32 *, 0x64);
block_9:
            if (var_v0_2 >= 2) {
                var_a0 = M2C_FIELD(var_a0, void **, 0x4C);
                goto block_13;
            }
            return 0;
        case 1:
            var_v0_2 = g_2be538 - M2C_FIELD(var_v0, s32 *, 0x60);
            goto block_9;
        }
    } else {
        return 1;
    }
}
