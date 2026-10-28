#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002D26F8;
extern M2C_UNK D_002D2738;

void *func_00110D18(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x1C0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x1B0) = &D_002D26F8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D2738;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    return temp_v0;
}
