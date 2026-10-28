#include "m2c_macros.h"

M2C_UNK func_00171CF8(s32, s32);                    /* extern */

void RunGuardScriptIfActor(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00171CF8(arg1, arg0);
    }
}
