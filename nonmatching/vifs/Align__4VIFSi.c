#include "m2c_macros.h"

void Align__4VIFSi(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    u8 *var_a2;
    u32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xC);
    var_a2 = temp_v0;
    var_v0 = (u32) (temp_v0 & 0xC) >> 2;
    if (var_v0 != arg1) {
        do {
            temp_a0 = var_v0 + 1;
            *var_a2 = 0;
            var_v0 = temp_a0 - (((s32) ((temp_a0 > -1) ? temp_a0 : (var_v0 + 4)) >> 2) * 4);
            var_a2 += 4;
        } while (var_v0 != arg1);
    }
    M2C_FIELD(arg0, s32 *, 0xC) = var_a2;
}
