#include "m2c_macros.h"

M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern s32 B_003D4A50;

s32 OnGameLoad__FP4GAME(void) {
    s32 temp_v0;

    memset(B_003D4A50 + 8, 0, 8);
    temp_v0 = B_003D4A50;
    B_003D4A50 += 0x10;
    return temp_v0;
}
