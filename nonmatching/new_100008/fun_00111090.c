#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002D1B20;
extern M2C_UNK D_002D1B60;

void *func_00111090(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x160);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x150) = &D_002D1B20;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D1B60;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    return temp_v0;
}
