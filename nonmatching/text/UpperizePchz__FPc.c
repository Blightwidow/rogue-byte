#include "m2c_macros.h"

extern M2C_UNK RO_002AA6A1;

void UpperizePchz__FPc(u8 *arg0) {
    u8 *var_a2;
    u8 temp_a0;

    var_a2 = arg0;
    if (*var_a2 != 0) {
        do {
            temp_a0 = *var_a2;
            *var_a2 = !(*(temp_a0 + &RO_002AA6A1) & 2) ? temp_a0 : (temp_a0 - 0x20);
            var_a2 += 1;
        } while (*var_a2 != 0);
    }
}
