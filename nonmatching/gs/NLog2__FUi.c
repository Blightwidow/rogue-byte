#include "m2c_macros.h"

u32 NLog2__FUi(u32 arg0) {
    u32 var_a1;
    u32 var_v1;

    var_v1 = 0;
    if (arg0 > 1U) {
        var_a1 = 1 * 2;
loop_2:
        var_v1 += 1;
        if (var_a1 < arg0) {
            var_a1 *= 2;
            if (var_v1 < 0x1FU) {
                goto loop_2;
            }
        }
    }
    return var_v1;
}
