#include "m2c_macros.h"

s32 CheckCardStatus();                              /* extern */
s32 CreateSaveDirectory(void *);                    /* extern */
s32 WriteSaveSlot(void *, s32);                     /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002E6550;

s32 func_001ABB60(void *arg0) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = CheckCardStatus();
    if ((var_s0 == 0) && (var_s0 = CreateSaveDirectory(arg0), (var_s0 == 0))) {
        var_s0 = WriteSaveSlot(arg0, M2C_FIELD(arg0, s32 *, 0xFD50));
        var_v0 = var_s0;
        if (var_s0 != 0) {
            goto block_4;
        }
    } else {
block_4:
        func_001ACC38(&B_002E6550, 3);
        var_v0 = var_s0;
    }
    return var_v0;
}
