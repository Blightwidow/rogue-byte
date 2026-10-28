#include "m2c_macros.h"

extern s32 B_003DD018;

void AddToIdTableB_1ed560(s32 *arg0) {
    s32 **var_v0;
    s32 var_a0;

    var_a0 = (s32) *arg0 % 16381;
    var_v0 = (var_a0 * 4) + B_003DD018;
loop_2:
    if (*var_v0 != NULL) {
        var_a0 = (s32) (var_a0 + 1) % 16381;
        var_v0 = (var_a0 * 4) + B_003DD018;
        goto loop_2;
    }
    *var_v0 = arg0;
}
