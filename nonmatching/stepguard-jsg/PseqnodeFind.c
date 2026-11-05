#include "m2c_macros.h"

void *PseqnodeFind(void *arg0, s32 arg1, s32 arg2) {
    void *var_a0;

    var_a0 = M2C_FIELD(arg0, void **, 0x5C);
    if (var_a0 != NULL) {
loop_2:
        if (var_a0 == arg2) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xE4);
            goto block_9;
        }
        if (M2C_FIELD(M2C_FIELD(var_a0, void **, 0x28), s32 *, 0x10) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xE4);
block_9:
            if (var_a0 == NULL) {
                goto block_10;
            }
            goto loop_2;
        }
        return var_a0;
    }
block_10:
    return NULL;
}
