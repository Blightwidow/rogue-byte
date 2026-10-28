#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void *func_002280D0(void) {
    char sp[0x400];
    s32 temp_v0;
    s32 var_a1;
    void **var_a0;
    void *temp_v1;
    void *var_s0;

    var_s0 = NULL;
    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x1A, 0);
    if (temp_v0 > 0) {
        var_a1 = temp_v0;
        var_a0 = sp;
        do {
            temp_v1 = *var_a0;
            var_a1 -= 1;
            var_a0 += 4;
            var_s0 = (M2C_FIELD(temp_v1, s32 *, 0x130) != 0) ? temp_v1 : var_s0;
        } while (var_a1 != 0);
    }
    return var_s0;
}
