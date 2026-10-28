#include "m2c_macros.h"

M2C_UNK PostBinocHudLoad(s32);                      /* extern */

void PostBinocLoad(s32 arg0) {
    PostBinocHudLoad(arg0 + 0x24);
}
