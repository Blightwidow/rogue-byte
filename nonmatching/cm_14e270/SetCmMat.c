#include "m2c_macros.h"

M2C_UNK SetCmPosMat(void *, s128, s128, s128, s32, s128, s32, s128, s32, s128); /* extern */

void SetCmMat(void *arg0, void *arg1) {
    char sp[0x400];
    s128 temp_a2;
    s128 temp_a3;

    temp_a2 = M2C_FIELD(arg1, s128 *, 0);
    temp_a3 = M2C_FIELD(arg0, s128 *, 0x90);
    SetCmPosMat(sp, temp_a2, temp_a3, temp_a2, 0, M2C_FIELD(arg1, s128 *, 0x10), 0, M2C_FIELD(arg1, s128 *, 0x20), 0, temp_a3);
}
