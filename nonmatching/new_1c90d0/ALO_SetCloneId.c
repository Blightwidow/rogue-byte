#include "m2c_macros.h"

M2C_UNK LO_SetCloneId();                            /* extern */

void ALO_SetCloneId(void *arg0, s32 arg1) {
    void *var_s0;
    void *var_v0;

    LO_SetCloneId();
    var_s0 = M2C_FIELD(arg0, void **, 0x64);
    if (var_s0 != NULL) {
        var_v0 = M2C_FIELD(var_s0, void **, 0xC);
loop_2:
        M2C_FIELD(var_v0, M2C_UNK (**)(void *, s32, M2C_UNK), 0xCC)(var_s0 + M2C_FIELD(var_v0, s16 *, 0xC8), arg1, 0);
        var_s0 = M2C_FIELD(var_s0, void **, 0x24);
        if (var_s0 != NULL) {
            var_v0 = M2C_FIELD(var_s0, void **, 0xC);
            goto loop_2;
        }
    }
}
