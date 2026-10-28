#include "m2c_macros.h"

extern void *B_003E1590;

void *PshdframesFromOid(s32 arg0) {
    void *var_v0;
    void *var_v1;

    if (arg0 == -1) {
        goto block_5;
    }
    var_v1 = B_003E1590;
    var_v0 = NULL;
    if (var_v1 != NULL) {
loop_3:
        var_v0 = var_v1;
        if (M2C_FIELD(var_v1, s32 *, 0) != arg0) {
            var_v1 = M2C_FIELD(var_v1, void **, 0x18);
            if (var_v1 == NULL) {
block_5:
                var_v0 = NULL;
            } else {
                goto loop_3;
            }
        }
    }
    return var_v0;
}
