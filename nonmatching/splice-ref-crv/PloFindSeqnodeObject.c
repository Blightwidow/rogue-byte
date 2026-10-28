#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
s32 PloLeased(s32);                                 /* extern */
extern M2C_UNK B_003DD490;

s32 PloFindSeqnodeObject(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;

    if (arg1 == -1) {
        var_s0 = 0;
        goto block_5;
    }
    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, arg1, M2C_FIELD(arg0, s32 *, 0x18));
    var_v0 = temp_v0;
    if (temp_v0 != 0) {
        var_v0 = temp_v0;
        if (FIsBasicDerivedFrom(temp_v0, 6) != 0) {
            var_s0 = PloLeased(temp_v0);
block_5:
            var_v0 = var_s0;
        }
    }
    return var_v0;
}
