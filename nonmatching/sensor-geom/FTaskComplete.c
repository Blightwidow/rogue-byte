#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, void *, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;

s32 FTaskComplete(void *arg0) {
    char sp[0x400];
    M2C_UNK sp4;
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x54);
    var_v0 = temp_v0 < 2;
    if (temp_v0 == -1) {
        if (M2C_FIELD(arg0, s32 *, 0xD8) != 0) {
            RefGetGameSaveValue(sp, arg0 + 0xD8, &B_003D4A60);
            CRef_Destruct(sp);
            return sp4;
        }
        var_v0 = M2C_FIELD(arg0, s32 *, 0x54) < 2;
        goto block_4;
    }
block_4:
    return var_v0 ^ 1;
}
