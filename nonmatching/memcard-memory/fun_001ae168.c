#include "m2c_macros.h"

M2C_UNK InitCritSect__FP8CRITSECT(M2C_UNK *, s32 *, s32 *, s32 *); /* extern */
extern s32 B_002F638C;
extern M2C_UNK B_002F6390;
extern M2C_UNK D_0047220F;
extern s32 g_2f6380;
extern s32 g_2f6384;
extern s32 g_2f6388;
extern s32 g_2f639c;

void func_001AE168(void) {
    s32 temp_v0;

    temp_v0 = (s32) &D_0047220F & ~0xF;
    g_2f6380 = temp_v0;
    g_2f6388 = 0x02000000;
    g_2f639c = -1;
    g_2f6384 = temp_v0;
    B_002F638C = 0x02000000;
    InitCritSect__FP8CRITSECT(&B_002F6390, &g_2f639c, &g_2f6380, &g_2f6388);
}
