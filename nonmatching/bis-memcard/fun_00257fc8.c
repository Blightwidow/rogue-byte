#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD2D0;
extern s32 B_002DD2D8;
extern s32 B_002DD2DC;
extern M2C_UNK B_00452170;
extern s32 g_2dd2d4;

void func_00257FC8(void) {
    B_002DD2D0 = 0;
    B_002DD2D8 = 0;
    B_002DD2DC = 0;
    g_2dd2d4 = 0;
    ResetSlotheap(&B_00452170, &B_002DD2DC, &g_2dd2d4);
}
