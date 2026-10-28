#include "m2c_macros.h"

M2C_UNK func_002417F0(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK B_003DD2C0;
extern s32 g_2c3c5c;
extern s32 g_2de5a0;

void func_00201998(void) {
    s32 temp_v1;

    func_002417F0(g_2de5a0, 0, 0);
    temp_v1 = 1 - g_2c3c5c;
    g_2c3c5c = temp_v1;
    M2C_FIELD((&B_003DD2C0 + (temp_v1 * 0x50)), s32 *, 0x4C) = 2;
}
