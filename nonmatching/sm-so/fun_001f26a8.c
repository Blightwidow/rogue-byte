#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK func_001F2500();                            /* extern */

void func_001F26A8(void *arg0) {
    void *var_a0;
    void *var_s0;

    func_001F2500();
    var_s0 = M2C_FIELD(arg0, void **, 0x64);
    if (var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
        var_a0 = var_s0;
loop_2:
        if (FIsBasicDerivedFrom(var_a0, 0x30) != 0) {
            func_001F26A8(var_s0);
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0x24);
        if (var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
            var_a0 = var_s0;
            goto loop_2;
        }
    }
}
