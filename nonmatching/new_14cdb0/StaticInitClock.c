#include "m2c_macros.h"

M2C_UNK InitClock(M2C_UNK *);                       /* extern */
s64 TickReadCount(M2C_UNK *, s64);                  /* extern */
extern M2C_UNK g_2dded0;

void StaticInitClock(void) {
    f32 *var_s0;
    s64 temp_v0;
    u32 var_v1;

    temp_v0 = M2C_ERROR(/* mfc0 Count */);
    M2C_FIELD(&g_2dded0, s64 *, 0x50) = temp_v0;
    M2C_FIELD(&g_2dded0, s64 *, 0x48) = TickReadCount(&g_2dded0, temp_v0);
    var_v1 = 0;
    var_s0 = &g_2dded0 + 0x18;
    do {
        *var_s0 = 1.0f;
        var_v1 += 1;
        var_s0 += 4;
    } while (var_v1 < 9U);
    M2C_FIELD(&g_2dded0, f32 *, 0xC) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 8) = 1.0f;
    InitClock(&g_2dded0);
}
