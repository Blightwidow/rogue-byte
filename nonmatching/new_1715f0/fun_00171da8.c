#include "m2c_macros.h"

void *func_00205458(M2C_UNK);                       /* extern */

s32 func_00171DA8(s32 arg0, s32 arg1) {
    s32 var_a1;
    void *temp_v0;

    temp_v0 = func_00205458(0x9C);
    var_a1 = 0;
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x30) == 5)) {
        var_a1 = M2C_FIELD(temp_v0, s32 *, 0x40) == arg1;
    }
    return var_a1;
}
