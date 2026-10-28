#include "m2c_macros.h"

s32 FFilterHitTestDefault(s32, void *);             /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

s32 func_0020CFC0(s32 arg0, void *arg1) {
    s32 var_v0;

    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x21)) || (var_v0 = 1, (FIsBasicDerivedFrom(M2C_FIELD(arg1, s32 *, 4), 0x59) == 0))) {
        var_v0 = FFilterHitTestDefault(arg0, arg1);
    }
    return var_v0;
}
