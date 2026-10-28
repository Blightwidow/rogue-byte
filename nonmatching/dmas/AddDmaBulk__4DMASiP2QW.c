#include "m2c_macros.h"

M2C_UNK CopyAqw__FPvT0i(s32, s32, s32);             /* extern */

void AddDmaBulk__4DMASiP2QW(void *arg0, s32 arg1, s32 arg2) {
    CopyAqw__FPvT0i(M2C_FIELD(arg0, s32 *, 0xC), arg2, arg1);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + (arg1 * 0x10));
}
