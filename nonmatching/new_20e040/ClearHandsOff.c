#include "m2c_macros.h"

M2C_UNK DecrementSwBinocCount(void *);              /* extern */
M2C_UNK DecrementSwShowCount(void *);               /* extern */
M2C_UNK RemoveGrfusr__Fi(M2C_UNK);                  /* extern */
M2C_UNK func_00187E08(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002DFC00;

void ClearHandsOff(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3D78) - 1;
    M2C_FIELD(arg0, s32 *, 0x3D78) = temp_v0;
    if (temp_v0 == 0) {
        RemoveGrfusr__Fi(2);
        func_00187E08(&B_002DFC00, 8);
    }
    var_v0 = arg1 & 2;
    if (arg1 & 1) {
        DecrementSwShowCount(arg0);
        var_v0 = arg1 & 2;
    }
    if (var_v0 != 0) {
        DecrementSwBinocCount(arg0);
    }
}
