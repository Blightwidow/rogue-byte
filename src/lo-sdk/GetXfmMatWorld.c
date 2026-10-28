#include "m2c_macros.h"

M2C_UNK UpdateXfmMatWorld();                        /* extern */

s32 GetXfmMatWorld(s32 arg0) {
    UpdateXfmMatWorld();
    return arg0 + 0xA0;
}
