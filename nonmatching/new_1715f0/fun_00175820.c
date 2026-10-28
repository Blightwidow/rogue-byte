#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */

s32 func_00175820(void *arg0, void *arg1) {
    s32 var_v0;
    void *temp_a0;

    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x21))) {
        temp_a0 = M2C_FIELD(arg1, void **, 4);
        if (!(M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xEC), s64 *, 0x70) & 4)) {
            if ((M2C_FIELD(arg0, s32 *, 0x74) == 0) || (var_v0 = 0, (FIsBasicDerivedFrom(temp_a0, 0x62) == 0))) {
                var_v0 = FIsBasicDerivedFrom(M2C_FIELD(arg1, void **, 4), 0x33) == 0;
            }
            return var_v0;
        }
        goto block_4;
    }
block_4:
    return 0;
}
