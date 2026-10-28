#include "m2c_macros.h"

void GoalStack_Update(void *arg0) {
    s32 var_s0;
    void **var_s1;
    void *temp_v0;
    void *var_a1;

    var_s0 = M2C_FIELD(arg0, s32 *, 4) - 1;
    if (var_s0 >= 0) {
        var_s1 = (var_s0 * 4) + 8 + arg0;
        var_a1 = *var_s1;
loop_2:
        var_s0 -= 1;
        var_s1 -= 4;
        temp_v0 = M2C_FIELD(var_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x54)(var_a1 + M2C_FIELD(temp_v0, s16 *, 0x50), var_a1);
        if (var_s0 >= 0) {
            var_a1 = *var_s1;
            goto loop_2;
        }
    }
}
