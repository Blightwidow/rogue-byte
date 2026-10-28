#include "m2c_macros.h"

s32 CsgsMatchGrfsgs(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_v1;

    var_v1 = arg0 & arg1;
    if (var_v1 == arg0) {
        var_a0 = 0;
        if (var_v1 != 0) {
            do {
                var_v1 &= var_v1 - 1;
                var_a0 += 1;
            } while (var_v1 != 0);
        }
        return var_a0;
    }
    return 0;
}
