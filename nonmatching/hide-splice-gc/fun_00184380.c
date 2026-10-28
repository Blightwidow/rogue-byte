#include "m2c_macros.h"

s32 func_001A6AF8(void *, s32, void *);             /* extern */

s32 func_00184380(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (M2C_FIELD(arg1, s32 *, 0xF4) == M2C_FIELD(arg0, s32 *, 0x19C)) {
        var_v0 = func_001A6AF8(arg1, M2C_FIELD(arg0, s32 *, 0x180), arg1);
    }
    return var_v0;
}
