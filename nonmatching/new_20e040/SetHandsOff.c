#include "m2c_macros.h"

M2C_UNK AddGrfusr__Fi(M2C_UNK);                     /* extern */
M2C_UNK IncrementSwBinocCount(void *);              /* extern */
M2C_UNK IncrementSwShowCount(void *);               /* extern */

void SetHandsOff(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3D78) + 1;
    M2C_FIELD(arg0, s32 *, 0x3D78) = temp_v0;
    if (temp_v0 == 1) {
        AddGrfusr__Fi(2);
    }
    var_v0 = arg1 & 2;
    if (arg1 & 1) {
        IncrementSwShowCount(arg0);
        var_v0 = arg1 & 2;
    }
    if (var_v0 != 0) {
        IncrementSwBinocCount(arg0);
    }
}
