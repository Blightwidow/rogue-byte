#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(void *, M2C_UNK, void *, void *); /* extern */

u16 U16Read__18CBinaryInputStream(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    s32 temp_a0;
    void *temp_v1;

    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a0 < 2) {
        CBinaryInputStream_Read_thunk(arg0, 2, sp, arg0);
        return sp0;
    }
    temp_v1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a0 - 2);
    M2C_FIELD(arg0, void **, 4) = (void *) (temp_v1 + 2);
    return M2C_FIELD(temp_v1, u8 *, 0) | (M2C_FIELD(temp_v1, u8 *, 1) << 8);
}
