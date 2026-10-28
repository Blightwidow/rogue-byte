#include "m2c_macros.h"

M2C_UNK __4CRef(s32);                               /* extern */
void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002D2090;
extern M2C_UNK D_002D20D0;
extern M2C_UNK D_002D9978;

void *func_00112100(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x1A0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D9978;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    __4CRef(temp_v0 + 0x80);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D20D0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x170) = &D_002D2090;
    return temp_v0;
}
