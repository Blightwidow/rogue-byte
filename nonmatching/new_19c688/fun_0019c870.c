#include "m2c_macros.h"

s32 func_0019C870(void *arg0, s32 *arg1) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (temp_v1 < 0xB) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC0);
    } else if (temp_v1 < 0xE) {
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x520);
    } else if (temp_v1 == 0x11) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC4);
    } else {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xC0);
    }
    *arg1 = 0;
    return var_v0;
}
