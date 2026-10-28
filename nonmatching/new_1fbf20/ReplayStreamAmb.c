#include "m2c_macros.h"

M2C_UNK func_001FB0C0(void *);                      /* extern */

void ReplayStreamAmb(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(arg0, s32 *, 0x40) == 0) && ((M2C_FIELD(arg0, u16 *, 0x52) != 0) || (var_v1 = 0 ^ 1, ((M2C_FIELD(arg0, u16 *, 0x50) & 1) != 0)))) {
        var_v1 = 1 ^ 1;
    }
    if (var_v1 != 0) {
        func_001FB0C0(arg0);
        M2C_FIELD(arg0, s64 *, 0x68) = 0;
        M2C_FIELD(arg0, s32 *, 0x3BC) = 0xF;
    }
}
