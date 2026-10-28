#include "m2c_macros.h"

s32 *func_002593B8(void *);                         /* extern */
M2C_UNK func_00259608(M2C_UNK);                     /* extern */
extern s32 B_002DE750;

s32 *func_002597C8(void *arg0, s32 arg1) {
    s32 *var_a0;

    if (arg1 == 1) {
        func_00259608(8);
        var_a0 = M2C_FIELD(arg0, s32 *, 0xE4) + 0xC0;
    } else {
        var_a0 = func_002593B8(arg0);
    }
    if (*var_a0 == 8) {
        return var_a0 + 0x30;
    }
    return &B_002DE750;
}
