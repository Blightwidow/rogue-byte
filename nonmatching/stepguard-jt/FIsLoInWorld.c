#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, s32);                   /* extern */
extern M2C_UNK B_003DD4BC;

s32 FIsLoInWorld(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        var_v1 = FFindDlEntry(&B_003DD4BC, M2C_FIELD(arg0, s32 *, 0x14)) != 0;
    }
    return var_v1;
}
