#include "m2c_macros.h"

s32 MakeCloneId(s32 arg0, s32 arg1) {
    return (arg0 << 0x10) | (arg1 & 0xFFFF);
}
