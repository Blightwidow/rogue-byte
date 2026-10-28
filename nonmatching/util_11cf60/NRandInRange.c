#include "m2c_macros.h"

s32 NRandRaw();                                     /* extern */

s32 NRandInRange(s32 arg0, s32 arg1) {
    return arg0 + (NRandRaw() % (s32) (arg1 - (arg0 - 1)));
}
