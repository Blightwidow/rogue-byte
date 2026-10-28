#include "m2c_macros.h"

M2C_UNK ConstructGuard(void *);                     /* extern */
void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002D4820;

void *func_00111868(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x10A0);
    ConstructGuard(temp_v0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D4820;
    return temp_v0;
}
