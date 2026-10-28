#include "m2c_macros.h"

M2C_UNK BuildCrvExcludedRanges(s32, void *);        /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */

void EnsureCrvExcludedRanges(void *arg0) {
    char sp[0x400];
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x180) == 0) {
        temp_v0 = PvAllocSwClearImpl__Fi(sp, 0x9C, 0x10);
        M2C_FIELD(arg0, s32 *, 0x180) = temp_v0;
        BuildCrvExcludedRanges(temp_v0, arg0);
    }
}
