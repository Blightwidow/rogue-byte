#include "m2c_macros.h"

s32 FIsBasicDerivedFrom();              /* extern */

s32 func_001709A8(s32 arg0) {
    if (FIsBasicDerivedFrom(0xD) != 0) {
        return 0;
    }
    return (FIsBasicDerivedFrom(arg0, 0xB) != 0) ? 1 : -1;
}
