#include "m2c_macros.h"

s32 FFilterOxa(s32, void *);                        /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

s32 func_0021FB18(s32 arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (FIsBasicDerivedFrom(M2C_FIELD(arg1, s32 *, 4), 0x59) == 0) {
        var_v0 = FFilterOxa(arg0, arg1);
    }
    return var_v0;
}
