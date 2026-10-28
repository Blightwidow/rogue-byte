#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK D_002D04A0;

void *func_00113060(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0xB0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D04A0;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    memset(temp_v0 + 0x30, 0, 0x70);
    return temp_v0;
}
