#include "m2c_macros.h"

s32 GrficFromAlo(void *, s32);                      /* extern */

void *PaloFindWkrAbsorber(void *arg0, s32 arg1) {
    void *var_a0;
    void *var_s0;
    void *var_v0;

    var_s0 = arg0;
    if (var_s0 != NULL) {
        var_a0 = var_s0;
loop_2:
        var_v0 = var_s0;
        if (GrficFromAlo(var_a0, arg1) == 0) {
            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
            var_a0 = var_s0;
            if (var_s0 == NULL) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_v0 = NULL;
    }
    return var_v0;
}
