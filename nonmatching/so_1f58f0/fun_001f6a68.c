#include "m2c_macros.h"

void func_001F6A68(void *arg0) {
    s32 var_a2;
    s32 var_a3;
    void *temp_a1;
    void *temp_v1;

    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xB8) > 0) {
        var_a3 = 0;
        do {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0xC0) + var_a3;
            temp_a1 = M2C_FIELD(temp_v1, void **, 0x24);
            M2C_FIELD(temp_v1, s32 *, 0xC) = (s32) (M2C_FIELD(temp_v1, s32 *, 0xC) | 0x800);
            if (temp_a1 != NULL) {
                M2C_FIELD(temp_a1, s64 *, 0x10) = (s64) (M2C_FIELD(temp_a1, s64 *, 0x10) | (0x8000 << 0x23));
            }
            var_a2 += 1;
            var_a3 += 0x28;
        } while (var_a2 < M2C_FIELD(arg0, s32 *, 0xB8));
    }
}
