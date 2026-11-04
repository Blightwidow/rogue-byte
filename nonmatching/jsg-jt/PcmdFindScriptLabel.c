#include "m2c_macros.h"

void *PcmdFindScriptLabel(void *arg0, s32 arg1) {
    void *var_a0;

    var_a0 = M2C_FIELD(arg0, void **, 0x50);
loop_1:
    if (var_a0 != NULL) {
        if (M2C_FIELD(var_a0, s32 *, 0) != 9) {
            var_a0 = M2C_FIELD(var_a0, void **, 0x18);
            goto loop_1;
        }
        if (M2C_FIELD(var_a0, s32 *, 4) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0x18);
            goto loop_1;
        }
    }
    return var_a0;
}
