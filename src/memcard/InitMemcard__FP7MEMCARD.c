#include "m2c_macros.h"

s32 NewSema(M2C_UNK, M2C_UNK);                      /* extern */

void InitMemcard__FP7MEMCARD(void *arg0) {
    s32 temp_v0;

    temp_v0 = NewSema(1, 1);
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x20;
}
