#include "m2c_macros.h"

void bevy_splice_bif_transpose(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 *var_v0;
    f32 *var_v1;
    f32 temp_f0;
    s32 var_t0;
    s32 var_t0_2;

    var_t0 = 0;
    if (arg1 > 0) {
        do {
            if (arg1 > 0) {
                var_v0 = (var_t0 * 4) + arg3;
                var_t0_2 = arg1;
                var_v1 = (var_t0 * arg0 * 4) + arg2;
                do {
                    temp_f0 = *var_v1;
                    var_t0_2 -= 1;
                    var_v1 += 4;
                    *var_v0 = temp_f0;
                    var_v0 += arg0 * 4;
                } while (var_t0_2 != 0);
            }
            var_t0 += 1;
        } while (var_t0 < arg1);
    }
}
