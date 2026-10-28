#include "m2c_macros.h"

extern void *B_003E159C;

void *PsaaFromOid(s32 arg0) {
    void *var_v0;
    void *var_v1;

    if (arg0 == -1) {
        goto block_9;
    }
    var_v1 = B_003E159C;
loop_5:
    var_v0 = NULL;
    if (var_v1 != NULL) {
        if (M2C_FIELD(var_v1, s32 *, 0x30) == 0) {
            var_v0 = var_v1;
            if (M2C_FIELD(var_v1, s32 *, 0x14) != arg0) {
                var_v1 = M2C_FIELD(var_v1, void **, 0x40);
                goto loop_5;
            }
        } else {
block_9:
            var_v0 = NULL;
        }
    }
    return var_v0;
}
