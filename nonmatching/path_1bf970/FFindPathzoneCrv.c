#include "m2c_macros.h"

s32 CposFindPath__FP2CGP6VECTORT1iT1(s32, M2C_UNK); /* extern */
M2C_UNK MeasureCrv(void *);                         /* extern */

s32 FFindPathzoneCrv(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = CposFindPath__FP2CGP6VECTORT1iT1(arg0 + 0xE0, 0x10);
    var_v0 = 0;
    if (temp_v0 >= 2) {
        M2C_FIELD(arg3, s32 *, 0xE8) = temp_v0;
        MeasureCrv(arg3);
        var_v0 = 1;
    }
    return var_v0;
}
