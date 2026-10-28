#include "m2c_macros.h"

M2C_UNK TriggerRsmgEntry(s32, s32, s32, M2C_UNK);   /* extern */

void TriggerRsmg(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    s32 var_s1;

    if (arg1 > 0) {
        var_s1 = arg2;
        var_s0 = arg1;
        do {
            TriggerRsmgEntry(arg0, var_s1, arg3, M2C_ERROR(/* Read from unset register $t0 */));
            var_s0 -= 1;
            var_s1 += 0x10;
        } while (var_s0 != 0);
    }
}
