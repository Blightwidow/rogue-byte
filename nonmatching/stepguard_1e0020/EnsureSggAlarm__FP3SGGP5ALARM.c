#include "m2c_macros.h"

void EnsureSggAlarm__FP3SGGP5ALARM(void *arg0, s32 arg1) {
    s32 *var_v1;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;

    temp_a3 = M2C_FIELD(arg0, s32 *, 0x84);
    var_a2 = 0;
    if (temp_a3 > 0) {
        var_v1 = arg0 + 0x88;
loop_2:
        var_a2 += 1;
        if (*var_v1 != arg1) {
            var_v1 += 4;
            if (var_a2 >= temp_a3) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x84);
        if ((u32) temp_v1 < 8U) {
            M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x88) = arg1;
            M2C_FIELD(arg0, s32 *, 0x84) = (s32) (temp_v1 + 1);
        }
    }
}
