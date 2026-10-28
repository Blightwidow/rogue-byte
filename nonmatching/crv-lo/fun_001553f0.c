#include "m2c_macros.h"

M2C_UNK LoadStepFromBrx(void *, s32);               /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */

void func_001553F0(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_FIELD(arg0, s32 *, 0x1014) = PvAllocSwClearImpl__Fi(sp, 0x480, 0x10);
    LoadStepFromBrx(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x1018) = 0x7FFFFFFF;
}
