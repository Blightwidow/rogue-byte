#include "m2c_macros.h"

extern void *B_003E126C;

void *PsmaFindAlo(s32 arg0, s32 arg1) {
    void *var_a2;
    void *var_v0;

    var_a2 = B_003E126C;
    if (var_a2 != NULL) {
loop_2:
        if (M2C_FIELD(var_a2, s32 *, 0x28) != arg0) {
            var_a2 = M2C_FIELD(var_a2, void **, 0x1C);
            goto block_10;
        }
        var_v0 = var_a2;
        if (arg1 != -1) {
            if (M2C_FIELD(M2C_FIELD(var_a2, void **, 0x24), s32 *, 0x18) != arg1) {
                var_a2 = M2C_FIELD(var_a2, void **, 0x1C);
block_10:
                if (var_a2 == NULL) {
                    goto block_11;
                }
                goto loop_2;
            }
            return var_a2;
        }
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return var_v0;
    }
block_11:
    var_v0 = NULL;
    return var_v0;
}
