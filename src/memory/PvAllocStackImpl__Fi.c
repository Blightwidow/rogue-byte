#include "m2c_macros.h"

M2C_UNK CheckForOutOfMemory__Fv(s32);               /* extern */
extern s32 g_2f6388;

s32 PvAllocStackImpl__Fi(void *arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0);
    var_v0 = 0;
    if (temp_a0 != 0) {
        CheckForOutOfMemory__Fv(temp_a0);
        var_v0 = (g_2f6388 - ((M2C_FIELD(arg0, s32 *, 0) + 0xF) & ~0xF)) & -M2C_FIELD(arg0, s32 *, 4);
        g_2f6388 = var_v0;
    }
    return var_v0;
}
