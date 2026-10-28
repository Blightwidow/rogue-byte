#include "m2c_macros.h"

s32 PcgtPointInCgQuick(s32);                        /* extern */

s32 FPosInPathzone(s32 arg0) {
    return PcgtPointInCgQuick(arg0 + 0xE0) != 0;
}
