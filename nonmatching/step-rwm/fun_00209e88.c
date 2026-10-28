#include "m2c_macros.h"

s32 FIsGuardInSgs();                    /* extern */
M2C_UNK func_0017A8C8();                /* extern */
s32 func_00205458();                    /* extern */

void func_00209E88(s32 arg0) {
    if ((FIsGuardInSgs(0x16) != 0) || (FIsGuardInSgs(arg0, 0x12) != 0)) {
        func_0017A8C8(func_00205458(arg0, 0xB0), 1);
    }
}
