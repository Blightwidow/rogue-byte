#include "m2c_macros.h"

s32 CchParsePchzInt__FPcPi(u8 *arg0, s32 *arg1) {
    s32 temp_t0;
    s32 var_a0;
    s32 var_a3;
    u8 *var_a2;
    u8 temp_a0;

    var_a2 = arg0;
    var_a0 = 0;
    temp_t0 = ((*var_a2 ^ 0x2D) == 0) ? -1 : 1;
    var_a3 = 0;
    if (temp_t0 == -1) {
        var_a2 += 1;
        var_a3 = 1;
    }
    if ((u32) (*var_a2 - 0x30) < 0xAU) {
        do {
            var_a3 += 1;
            temp_a0 = *var_a2;
            var_a2 += 1;
            var_a0 = (var_a0 * 0xA) - 0x30 + temp_a0;
        } while ((u32) (*var_a2 - 0x30) < 0xAU);
    }
    *arg1 = var_a0 * temp_t0;
    return var_a3;
}
