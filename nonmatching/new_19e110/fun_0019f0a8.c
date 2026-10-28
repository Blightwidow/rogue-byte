#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_0019F0A8(void) {
    char sp[0x400];
    s32 temp_v0;
    s32 var_s1;
    void **var_s0;
    void *temp_a1;
    void *temp_v0_2;

    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0);
    var_s1 = temp_v0;
    if (temp_v0 > 0) {
        var_s0 = sp;
        do {
            temp_a1 = *var_s0;
            var_s1 -= 1;
            var_s0 += 4;
            temp_v0_2 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x344)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x340), temp_a1);
        } while (var_s1 != 0);
    }
}
