#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */

void PostBombLoad(void *arg0) {
    char sp[0x400];
    PostSoLoad();
    if (M2C_FIELD(arg0, s32 *, 0x1F4) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1FC) = PvAllocSwImpl__Fi(sp, 0xC0, 0x10);
    }
}
