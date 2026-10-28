#include "m2c_macros.h"

extern M2C_UNK D_002BAAE8;

s32 FIsBasicDerivedFrom(void *arg0, s32 arg1) {
    s16 temp_a1;
    s32 temp_a1_2;
    s32 var_v1;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_a1 = M2C_FIELD(temp_v1, s16 *, 0x30);
    temp_a1_2 = M2C_FIELD(M2C_FIELD(temp_v1, void *(**)(void *, s16), 0x34)(arg0 + temp_a1, temp_a1), s32 *, 4);
    var_v1 = 0;
    if (temp_a1_2 >= arg1) {
        var_v1 = temp_a1_2 < M2C_FIELD(((arg1 * 0x14) + &D_002BAAE8), s32 *, 8);
    }
    return var_v1;
}
