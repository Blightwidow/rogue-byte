#include "m2c_macros.h"

M2C_UNK EnterCritSect__FP8CRITSECT(M2C_UNK *);      /* extern */
extern M2C_UNK B_002F6390;
extern M2C_UNK B_002F63A0;
extern s32 g_2f6388;
extern s32 g_2f639c;

void InitStackImpl__Fv(void) {
    s32 temp_v1;

    EnterCritSect__FP8CRITSECT(&B_002F6390);
    temp_v1 = g_2f639c + 1;
    g_2f639c = temp_v1;
    *((temp_v1 * 4) + &B_002F63A0) = g_2f6388;
}
