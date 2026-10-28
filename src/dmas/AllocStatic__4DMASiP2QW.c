#include "m2c_macros.h"

void AllocStatic__4DMASiP2QW(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = arg2;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg2 + (arg1 * 0x10));
}
