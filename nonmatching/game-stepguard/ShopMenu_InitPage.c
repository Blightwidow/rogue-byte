#include "m2c_macros.h"

extern f32 g_2ddf0c;

void ShopMenu_InitPage(void *arg0) {
    u32 var_a2;
    void *var_a1;

    var_a1 = arg0 + 0x50;
    var_a2 = 0;
    M2C_FIELD(arg0, s32 *, 0x264) = -1;
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2ddf0c;
    M2C_FIELD(arg0, s32 *, 0x25C) = -1;
    M2C_FIELD(arg0, s32 *, 0x40) = -1;
    M2C_FIELD(arg0, s32 *, 0x260) = -1;
    do {
        M2C_FIELD(var_a1, s32 *, -4) = -1;
        var_a2 += 1;
        M2C_FIELD(var_a1, s32 *, 0) = -1;
        var_a1 += 8;
    } while (var_a2 < 0x40U);
}
