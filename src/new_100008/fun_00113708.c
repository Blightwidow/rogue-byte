#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK func_002562A8(void *);                      /* extern */
extern M2C_UNK D_002CFE20;

void *func_00113708(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0xD0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CFE20;
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    func_002562A8(temp_v0 + 0x40);
    func_002562A8(temp_v0 + 0x60);
    func_002562A8(temp_v0 + 0x80);
    return temp_v0;
}
