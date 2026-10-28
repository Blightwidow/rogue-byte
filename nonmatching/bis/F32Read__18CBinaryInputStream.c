#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(M2C_UNK, void *, s32); /* extern */

f32 F32Read__18CBinaryInputStream(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    s32 temp_a3;
    void *temp_v0;

    temp_a3 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a3 < 4) {
        CBinaryInputStream_Read_thunk(4, sp, temp_a3);
        return sp0;
    }
    temp_v0 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a3 - 4);
    M2C_FIELD(arg0, void **, 4) = (void *) (temp_v0 + 4);
    return M2C_BITWISE(f32, (M2C_FIELD(temp_v0, u8 *, 0) + (M2C_FIELD(temp_v0, u8 *, 1) << 8) + (M2C_FIELD(temp_v0, u8 *, 2) << 0x10) + (M2C_FIELD(temp_v0, u8 *, 3) << 0x18)));
}
