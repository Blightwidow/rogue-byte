#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(s32, M2C_UNK, M2C_UNK, s32); /* extern */
s32 PloFindSwObject_thunk(M2C_UNK, M2C_UNK);        /* extern */

void *PloFindSpawn(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK var_s0_2;
    s32 *var_a0;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v1;
    void *temp_v1;
    void *var_s0;

    var_a3 = 0;
    var_s0_2 = 5;
    if (arg2 != -1) {
        var_a3 = PloFindSwObject_thunk(5, 0);
        var_s0_2 = (var_a3 != 0) ? 1 : 5;
    }
    var_s0 = NULL;
    temp_v0 = CploFindSwObjectsByClass(arg0, var_s0_2, 0x2A, var_a3);
    var_v1 = 0;
    if (temp_v0 > 0) {
        var_v0 = 0 * 4;
        do {
            temp_v1 = *(sp + var_v0);
            if (M2C_FIELD(temp_v1, s32 *, 0x18) != arg1) {
                temp_a2 = M2C_FIELD(temp_v1, s32 *, 0x16C);
                var_a1 = 0;
                if (temp_a2 > 0) {
                    var_a0 = temp_v1 + 0x170;
loop_7:
                    var_a1 += 1;
                    if (*var_a0 != arg1) {
                        var_a0 += 4;
                        if (var_a1 >= temp_a2) {

                        } else {
                            goto loop_7;
                        }
                    } else {
                        goto block_10;
                    }
                }
            } else {
block_10:
                var_s0 = temp_v1;
            }
            var_v1 += 1;
            var_v0 = var_v1 * 4;
        } while (var_v1 < temp_v0);
    }
    return var_s0;
}
