#include "m2c_macros.h"

M2C_UNK LoadCrvFromBrx();                           /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */

void Obstacle_LoadFromBrx(void *arg0) {
    char sp[0x400];
    LoadCrvFromBrx();
    M2C_FIELD(arg0, s32 *, 0x1EC) = PvAllocSwClearImpl__Fi(sp, (M2C_FIELD(arg0, s32 *, 0xE8) * 0x10) - 0x10, 0x10);
}
