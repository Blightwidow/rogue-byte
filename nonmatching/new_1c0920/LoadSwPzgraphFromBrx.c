#include "m2c_macros.h"

M2C_UNK LoadPzgraphFromBrx(s32, s32, s32);          /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */
s32 U32Read__18CBinaryInputStream(s32);             /* extern */

void LoadSwPzgraphFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = U32Read__18CBinaryInputStream(arg1);
    if (temp_v0 != 0) {
        temp_v0_2 = PvAllocSwClearImpl__Fi(sp, 0x30, 0x10);
        M2C_FIELD(arg0, s32 *, 0x45CC) = temp_v0_2;
        LoadPzgraphFromBrx(temp_v0_2, temp_v0, arg1);
    }
}
