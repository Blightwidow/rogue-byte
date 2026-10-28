#include "m2c_macros.h"

M2C_UNK ResortXfActList(s32, void *, M2C_UNK);      /* extern */

void func_00131B10(s32 arg0, s32 arg1, void *arg2) {
    void *var_v1;

    var_v1 = M2C_FIELD(arg2, void **, 0x90);
loop_1:
    if (var_v1 != NULL) {
        if (M2C_FIELD(var_v1, s32 *, 0) != 0) {
            var_v1 = M2C_FIELD(var_v1, void **, 0x10);
            goto loop_1;
        }
        if (M2C_FIELD(var_v1, s32 *, 0x24) != arg0) {
            var_v1 = M2C_FIELD(var_v1, void **, 0x10);
            goto loop_1;
        }
        M2C_FIELD(var_v1, s32 *, 0xC) = -1;
        ResortXfActList(arg1, arg2, -1);
    }
}
