#include "m2c_macros.h"

M2C_UNK LeaveCritSect__FP8CRITSECT(M2C_UNK *, s32, s32 *, s32 *); /* extern */
extern M2C_UNK B_002F6390;
extern M2C_UNK B_002F63A0;
extern s32 g_2f6388;
extern s32 g_2f639c;

void FreeStackImpl__Fv(void) {
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = g_2f639c - 1;
    temp_v1 = *((g_2f639c * 4) + &B_002F63A0);
    g_2f639c = temp_a1;
    g_2f6388 = temp_v1;
    LeaveCritSect__FP8CRITSECT(&B_002F6390, temp_a1, &g_2f639c, &g_2f6388);
}
