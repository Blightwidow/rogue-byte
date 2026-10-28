#include "m2c_macros.h"

s32 func_001B1B98(s32, s32);                        /* extern */

void ResolveSlotSoAsegs(s32 arg0) {
    s32 temp_a1;
    s32 var_s1;
    void *var_s0;

    var_s0 = arg0 + 0x17C;
    var_s1 = 5;
    do {
        temp_a1 = M2C_FIELD(var_s0, s32 *, 0);
        if (temp_a1 != -1) {
            M2C_FIELD(var_s0, s32 *, 4) = func_001B1B98(arg0, temp_a1);
            M2C_FIELD(var_s0, s32 *, 0) = -1;
        }
        var_s1 -= 1;
        var_s0 += 0xC;
    } while (var_s1 >= 0);
}
