#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK func_002562A8(s32);                         /* extern */
extern M2C_UNK D_002CFC20;

void *func_00113840(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x50);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CFC20;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    func_002562A8(temp_v0 + 0x30);
    return temp_v0;
}
