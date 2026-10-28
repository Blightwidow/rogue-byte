#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK B_003DD490;

void *func_001CCA40(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_v0;
    s32 var_a2;
    void **var_a1;
    void *temp_v1;
    void *var_v0;

    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 0x401, 0x14, arg1);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_a1 = sp;
loop_2:
        temp_v1 = *var_a1;
        var_v0 = temp_v1;
        if (!(M2C_FIELD(temp_v1, s32 *, 0xE0) & M2C_FIELD(arg0, s32 *, 0x1000))) {
            var_a2 += 1;
            var_a1 += 4;
            if (var_a2 >= temp_v0) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_v0 = NULL;
    }
    return var_v0;
}
