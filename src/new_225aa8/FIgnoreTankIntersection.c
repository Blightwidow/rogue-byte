#include "m2c_macros.h"

s32 FIgnoreSoIntersection();                        /* extern */
s32 IMax(s32, M2C_UNK);                             /* extern */

s32 FIgnoreTankIntersection(void *arg0, void *arg1) {
    s32 var_a0;
    void *temp_a1;

    var_a0 = FIgnoreSoIntersection();
    temp_a1 = M2C_FIELD(arg0, void **, 0x1C0);
    if (temp_a1 != NULL) {
        if (M2C_FIELD(arg1, s32 *, 0x3C) == M2C_FIELD(temp_a1, s32 *, 0x3C)) {
            var_a0 = IMax(var_a0, 1);
        }
    }
    return var_a0;
}
