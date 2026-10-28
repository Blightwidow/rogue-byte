#include "m2c_macros.h"

s32 PloNew(M2C_UNK, void *, M2C_UNK, M2C_UNK);      /* extern */

s32 func_0020A9C0(void *arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_a2;

    if (M2C_FIELD(arg0, s32 *, 0xED8) != 0) {
        var_a2 = M2C_FIELD(arg0, s32 *, 0xEDC);
    } else {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xEFC);
        var_a2 = PloNew(0x78, arg0, 0x2CC, -1);
        M2C_FIELD((arg0 + (temp_a0 * 4)), s32 *, 0xEDC) = var_a2;
        M2C_FIELD(arg0, s32 *, 0xEFC) = (s32) (temp_a0 + 1);
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xED8);
        M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0xEB8) = 0x2CC;
        M2C_FIELD(arg0, s32 *, 0xED8) = (s32) (temp_v1 + 1);
    }
    return var_a2;
}
