#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
extern M2C_UNK D_002CB5D8;

void *func_001110D8(void) {
    s32 var_v0;
    void *temp_v0;

    temp_v0 = __builtin_new(0x460);
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CB5D8;
    var_v0 = 0x1E;
    do {
        var_v0 -= 1;
    } while (var_v0 != -1);
    return temp_v0;
}
