#include "m2c_macros.h"

void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK func_002562A8(void *);                      /* extern */
extern M2C_UNK D_002D5120;

void *func_00112B30(void) {
    s32 var_s2;
    void *temp_v0;
    void *var_s0;

    var_s2 = 5;
    temp_v0 = __builtin_new(0x160);
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002D5120;
    var_s0 = temp_v0 + 0x60;
    do {
        var_s2 -= 1;
        func_002562A8(var_s0);
        var_s0 += 0x20;
    } while (var_s2 != -1);
    return temp_v0;
}
