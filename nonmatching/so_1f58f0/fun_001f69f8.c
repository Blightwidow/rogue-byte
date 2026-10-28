#include "m2c_macros.h"

void func_001F69F8(void *arg0, s32 arg1) {
    s32 var_a3;
    s32 var_t0;
    void *temp_a2;
    void *temp_v1;

    var_a3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xB8) > 0) {
        var_t0 = 0;
        do {
            temp_a2 = M2C_FIELD(arg0, s32 *, 0xC0) + var_t0;
            if (M2C_FIELD(temp_a2, s32 *, 0) == arg1) {
                temp_v1 = M2C_FIELD(temp_a2, void **, 0x24);
                M2C_FIELD(temp_a2, s32 *, 0xC) = (s32) (M2C_FIELD(temp_a2, s32 *, 0xC) | 0x800);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s64 *, 0x10) = (s64) (M2C_FIELD(temp_v1, s64 *, 0x10) | (0x8000 << 0x23));
                }
            }
            var_a3 += 1;
            var_t0 += 0x28;
        } while (var_a3 < M2C_FIELD(arg0, s32 *, 0xB8));
    }
}
