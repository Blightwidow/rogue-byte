#include "m2c_macros.h"

s32 FIgnoreSoIntersection();                        /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 IMax(s32, M2C_UNK);                             /* extern */

s32 FIgnoreGadgetObjIntersection(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    var_s0 = FIgnoreSoIntersection();
    if ((temp_v1 == 0) || (var_v0 = var_s0, (temp_v1 == 4))) {
        if (FIsBasicDerivedFrom(arg1, 0x34) != 0) {
            var_s0 = IMax(var_s0, 1);
        }
        var_v0 = var_s0;
    }
    return var_v0;
}
