#include "m2c_macros.h"

s32 FIgnoreSoIntersection(void *, void *);          /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

s32 FIgnoreLootIntersection(void *arg0, void *arg1) {
    s32 var_v0;

    if ((M2C_FIELD(arg0, s32 *, 0x184) != 5) || (var_v0 = 3, (FIsBasicDerivedFrom(*M2C_FIELD(arg1, s32 **, 0x14), 0x34) == 0))) {
        var_v0 = FIgnoreSoIntersection(arg0, arg1);
    }
    return var_v0;
}
