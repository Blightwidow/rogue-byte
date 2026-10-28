#include "m2c_macros.h"

s32 McSync(s32, s32, M2C_UNK, M2C_UNK);             /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
s32 sceMcFormat(s32, s32);                          /* extern */
extern M2C_UNK B_002E6550;

s32 FormatMemcard(void *arg0) {
    s32 temp_v0;

    temp_v0 = McSync(arg0 + 0xFD5C, sceMcFormat(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4)), 0x10, 0);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0xC) = 2;
        func_001ACC38(&B_002E6550, 3);
    } else {
        M2C_FIELD(arg0, s32 *, 0xC) = 3;
    }
    return temp_v0;
}
