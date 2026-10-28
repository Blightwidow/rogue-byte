#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK RebuildLight(s32);                          /* extern */

void PostLightLoad(s32 arg0) {
    PostLoLoad();
    RebuildLight(arg0);
}
