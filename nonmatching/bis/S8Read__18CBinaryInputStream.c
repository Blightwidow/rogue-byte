#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(void *, M2C_UNK, void *); /* extern */

s8 S8Read__18CBinaryInputStream(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    s32 temp_a0;
    s8 *temp_v1;

    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a0 > 0) {
        temp_v1 = M2C_FIELD(arg0, s8 **, 4);
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a0 - 1);
        M2C_FIELD(arg0, s8 **, 4) = (s8 *) (temp_v1 + 1);
        return *temp_v1;
    }
    CBinaryInputStream_Read_thunk(arg0, 1, sp);
    return sp0;
}
