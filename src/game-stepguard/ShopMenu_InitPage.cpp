#include "types.h"
extern "C" {
extern f32 g_2ddf0c;
void ShopMenu_InitPage(s8 *arg0) {
    u32 var_a2;
    s8 *var_a1;

    *(s32 *)(arg0 + 0x40) = -1;
    var_a1 = arg0 + 0x50;
    var_a2 = 0;
    *(f32 *)(arg0 + 0x44) = (f32) g_2ddf0c;
    *(s32 *)(arg0 + 0x25C) = -1;
    *(s32 *)(arg0 + 0x260) = -1;
    *(s32 *)(arg0 + 0x264) = -1;
    do {
        *(s32 *)(var_a1 - 4) = -1;
        var_a2 += 1;
        *(s32 *)(var_a1) = -1;
        var_a1 += 8;
    } while (var_a2 < 0x40U);
}
}
