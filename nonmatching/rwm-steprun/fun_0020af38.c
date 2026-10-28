#include "m2c_macros.h"

M2C_UNK ResetAnimref(s32, s32);                     /* extern */

void func_0020AF38(void *arg0, s32 arg1, s32 arg2) {
    ResetAnimref(arg0 + 0xB0, M2C_FIELD(arg0, s32 *, 0xAC));
    M2C_FIELD(arg0, s32 *, 0xBC) = arg2;
    M2C_FIELD(arg0, s32 *, 0xB4) = arg1;
}
