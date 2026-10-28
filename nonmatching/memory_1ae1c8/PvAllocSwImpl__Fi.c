#include "m2c_macros.h"

M2C_UNK CheckForOutOfMemory__Fv(s32);               /* extern */
extern s32 g_2f6384;

s32 PvAllocSwImpl__Fi(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0);
    var_v0 = 0;
    if (temp_a0 != 0) {
        CheckForOutOfMemory__Fv(temp_a0);
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 4);
        var_v0 = (g_2f6384 - 1 + temp_a0_2) & -temp_a0_2;
        g_2f6384 = var_v0 + ((M2C_FIELD(arg0, s32 *, 0) + 0xF) & ~0xF);
    }
    return var_v0;
}
