#include "m2c_macros.h"

void Camobj_AddFocalUser(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x12C) = (s32) (M2C_FIELD(arg0, s32 *, 0x12C) + 1);
}
