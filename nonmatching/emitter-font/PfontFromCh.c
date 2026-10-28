#include "m2c_macros.h"

extern M2C_UNK B_002DE9F0;
extern u8 D_002BE328;

s32 PfontFromCh(s32 arg0) {
    s32 temp_a0;
    s32 var_a1;

    temp_a0 = arg0 & 0xFF;
    var_a1 = 0;
    if (temp_a0 != D_002BE328) {
        var_a1 = 1;
loop_2:
        if (var_a1 < 2) {
            if (temp_a0 != (&D_002BE328)[var_a1]) {
                var_a1 += 1;
                goto loop_2;
            }
            goto block_6;
        }
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return 0;
    }
block_6:
    if (var_a1 >= 2) {
        return 0;
    }
    return *((var_a1 * 4) + &B_002DE9F0);
}
