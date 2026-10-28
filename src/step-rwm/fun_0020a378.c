#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 func_0020A298(s32, s32, s32);                   /* extern */
extern s32 B_002DD648;

s32 func_0020A378(s32 arg0, s32 arg1, s32 arg2) {
    if ((FIsBasicDerivedFrom(arg1, 0x36) != 0) && (FIsBasicDerivedFrom(arg0, 0x3A) == 0) && (FIsBasicDerivedFrom(arg0, 0x3D) == 0) && (arg0 != B_002DD648)) {
        return 1;
    }
    return func_0020A298(arg0, arg1, arg2);
}
