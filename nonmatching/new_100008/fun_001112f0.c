#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002CB9F8;
extern M2C_UNK D_002D1EA8;

void *func_001112F0(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x1A0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x100) = &D_002D1EA8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CB9F8;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    return temp_v0;
}
