#include "m2c_macros.h"

M2C_UNK CAry_Reserve(s32);                          /* extern */
M2C_UNK memcpy(s32, s32, s32);                      /* extern */

void func_00116E30(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    CAry_Reserve(M2C_FIELD(arg0, s32 *, 4) + arg2);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0xC);
    memcpy(M2C_FIELD(arg0, s32 *, 0) + (temp_v0 * M2C_FIELD(arg0, s32 *, 4)), arg1, temp_v0 * arg2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + arg2);
}
