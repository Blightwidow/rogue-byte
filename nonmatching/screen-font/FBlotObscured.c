#include "m2c_macros.h"

extern void *B_003E1060;

s32 FBlotObscured(void *arg0) {
    s32 var_v0;
    void *var_v1;

    var_v1 = B_003E1060;
    if (var_v1 != NULL) {
loop_2:
        var_v0 = 1;
        if (M2C_FIELD(arg0, s32 *, 0xA4) >= M2C_FIELD(var_v1, s32 *, 0xA4)) {
            var_v1 = M2C_FIELD(var_v1, void **, 0xB4);
            if (var_v1 == NULL) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_v0 = 0;
    }
    return var_v0;
}
