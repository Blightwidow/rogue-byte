#include "m2c_macros.h"

void func_001F3900(void *arg0) {
    s32 var_a2;
    s32 var_t0;
    void *temp_a0;
    void *temp_a1;

    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_t0 = 0;
        do {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0xE4) + var_t0;
            if (!(M2C_FIELD(temp_a1, s64 *, 0x10) & (0x8000 << 0x23))) {
                temp_a0 = M2C_FIELD(temp_a1, void **, 0);
                M2C_FIELD(temp_a1, s128 *, 0x20) = (s128) M2C_FIELD(temp_a0, s128 *, 0x40);
                M2C_FIELD(temp_a1, s128 *, 0x30) = (s128) M2C_FIELD(temp_a0, s128 *, 0x50);
                M2C_FIELD(temp_a1, s128 *, 0x40) = (s128) M2C_FIELD(temp_a0, s128 *, 0x60);
                M2C_FIELD(temp_a1, s128 *, 0x50) = (s128) M2C_FIELD(temp_a0, s128 *, 0x70);
                M2C_FIELD(temp_a1, s32 *, 0xAC) = (s32) M2C_FIELD(temp_a0, s32 *, 0xA4);
            }
            var_a2 += 1;
            var_t0 += 0xB0;
        } while (var_a2 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
}
