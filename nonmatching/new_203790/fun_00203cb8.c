#include "m2c_macros.h"

s32 PpartFindAlo();                                 /* extern */
M2C_UNK func_00203D00(s32, s32, s32);               /* extern */

void func_00203CB8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = PpartFindAlo();
    if (temp_v0 != 0) {
        func_00203D00(arg0, temp_v0, arg2);
    }
}
