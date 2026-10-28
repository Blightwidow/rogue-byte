#include "m2c_macros.h"

s32 NewSema(M2C_UNK, M2C_UNK);                      /* extern */

void InitCritSect__FP8CRITSECT(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 8) = NewSema(1, 1);
}
