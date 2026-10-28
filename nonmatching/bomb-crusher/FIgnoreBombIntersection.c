#include "m2c_macros.h"

s32 FIgnoreSoIntersection();                        /* extern */
s32 IMax(s32, M2C_UNK, void *, s32);                /* extern */

s32 FIgnoreBombIntersection(void *arg0, void *arg1) {
    s32 var_a3;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x200);
    var_a3 = FIgnoreSoIntersection();
    if (*M2C_FIELD(arg1, s32 **, 0x14) == *M2C_FIELD(temp_a2, s32 **, 0x14)) {
        var_a3 = IMax(var_a3, 1, temp_a2, var_a3);
    }
    return var_a3;
}
