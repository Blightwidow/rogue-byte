#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

s32 FFilterDprizeObjects(s32 arg0, void *arg1) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = 0;
    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x21))) {
        temp_s0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, void **, 4), void **, 0xEC), s32 *, 0x60);
        var_v0 = 0;
        if (FIsBasicDerivedFrom(temp_s0, 0x32) == 0) {
            var_v0 = 0;
            if (FIsBasicDerivedFrom(temp_s0, 0x4F) == 0) {
                var_v0 = 1;
            }
        }
    }
    return var_v0;
}
