#include "m2c_macros.h"

M2C_UNK HookupPzgraph(s32);                         /* extern */
s32 PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */
M2C_UNK SetupDefaultPathzone(s32);                  /* extern */

void func_001C10C8(void *arg0) {
    char sp[0x400];
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x45CC) == 0) {
        temp_v0 = PloNew(0x11, 0, 0x2CA, -1);
        M2C_FIELD(arg0, s32 *, 0x45C8) = temp_v0;
        SetupDefaultPathzone(temp_v0);
        M2C_FIELD(arg0, s32 *, 0x45CC) = PvAllocSwClearImpl__Fi(sp, 0x30, 0x10);
    }
    HookupPzgraph(M2C_FIELD(arg0, s32 *, 0x45CC));
}
