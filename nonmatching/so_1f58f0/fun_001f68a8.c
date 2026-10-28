#include "m2c_macros.h"

void func_001F68A8(void *arg0, s32 arg1) {
    s32 var_a2;
    s32 var_t0;
    void *temp_a0;

    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_t0 = 0;
        do {
            var_a2 += 1;
            temp_a0 = var_t0 + M2C_FIELD(arg0, s32 *, 0xE4);
            M2C_FIELD(temp_a0, s64 *, 0x10) = (s64) ((M2C_FIELD(temp_a0, s64 *, 0x10) & ((((((0xFFFE << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((arg1 & 1) << 0x30));
            var_t0 += 0xB0;
        } while (var_a2 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
}
