#include "m2c_macros.h"

M2C_UNK BindGlobset(s32);                           /* extern */
M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK UpdateAloXfWorld(s32);                      /* extern */

void PostSoLoad(s32 arg0) {
    PostLoLoad();
    UpdateAloXfWorld(arg0);
    BindGlobset(arg0 + 0x80);
}
