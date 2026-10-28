#include "m2c_macros.h"

M2C_UNK ConstructGuard(void *);                     /* extern */
void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002C8C18;

void *func_001119E8(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x1010);
    ConstructGuard(temp_v0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002C8C18;
    return temp_v0;
}
