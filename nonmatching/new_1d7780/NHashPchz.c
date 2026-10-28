#include "m2c_macros.h"

extern M2C_UNK RO_002AA6A1;

s32 NHashPchz(u8 *arg0) {
    s32 var_v1;
    u8 *var_t0;
    u8 temp_a1;

    var_t0 = arg0;
    var_v1 = 0;
    if (*var_t0 != 0) {
        do {
            temp_a1 = *var_t0;
            var_t0 += 1;
            var_v1 = (var_v1 * 0x21) + (!(*(temp_a1 + &RO_002AA6A1) & 2) ? temp_a1 : (temp_a1 - 0x20));
        } while (*var_t0 != 0);
    }
    return var_v1;
}
