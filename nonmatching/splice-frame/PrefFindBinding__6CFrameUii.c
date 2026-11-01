#include "m2c_macros.h"

void *PrefFindBinding__6CFrameUii(void *arg0, s32 arg1, s32 arg2) {
    s32 var_s1;
    void **var_s0;
    void *temp_a0;
    void *var_a1;
    void *var_v1;

    M2C_FIELD(arg0, s32 *, 0x20) = 1;
    var_v1 = M2C_FIELD(arg0, void **, 0x1C);
    var_a1 = NULL;
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, s32 *, 8) != arg1) {
            var_v1 = M2C_FIELD(var_v1, void **, 0x14);
            if (var_v1 == NULL) {
                goto block_6;
            }
            goto loop_1;
        }
        var_a1 = var_v1 + 0xC;
    } else {
block_6:
        if (arg2 != 0) {
            var_s1 = 0;
            if (M2C_FIELD(arg0, s32 *, 8) > 0) {
                var_s0 = arg0 + 0xC;
loop_9:
                temp_a0 = *var_s0;
                if ((M2C_FIELD(temp_a0, s32 *, 0x20) != 0) || (var_a1 = PrefFindBinding__6CFrameUii(temp_a0, arg1, arg2), (var_a1 == NULL))) {
                    var_s1 += 1;
                    var_s0 += 4;
                    if (var_s1 < M2C_FIELD(arg0, s32 *, 8)) {
                        goto loop_9;
                    }
                }
            }
        }
    }
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    return var_a1;
}
