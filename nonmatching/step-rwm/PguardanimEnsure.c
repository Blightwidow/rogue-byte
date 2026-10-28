#include "m2c_macros.h"

void *PguardanimFind();                             /* extern */
M2C_UNK ResetAnimref(void *, void *);               /* extern */

void *PguardanimEnsure(void *arg0, s64 arg1) {
    s32 temp_v1;
    void *temp_v0;
    void *var_s0;

    var_s0 = PguardanimFind();
    if (var_s0 == NULL) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x4C0);
        temp_v0 = arg0 + ((temp_v1 << 5) + 0x4D0);
        M2C_FIELD(arg0, s32 *, 0x4C0) = (s32) (temp_v1 + 1);
        M2C_FIELD(temp_v0, s64 *, 0x10) = arg1;
        var_s0 = temp_v0;
    }
    ResetAnimref(var_s0, arg0);
    return var_s0;
}
