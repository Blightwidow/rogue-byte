#include "m2c_macros.h"

s32 PpoSwFocus(void *arg0) {
    s32 var_v0;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x3F00);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x3EFC);
    }
    return var_v0;
}
