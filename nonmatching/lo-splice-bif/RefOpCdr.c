#include "m2c_macros.h"

M2C_UNK CRef_ConstructPair(s32, s32);               /* extern */
M2C_UNK SetTag__4CRef4TAGK(M2C_UNK);                /* extern */

s32 RefOpCdr(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_a1;

    temp_a1 = M2C_FIELD(M2C_FIELD(arg2, void **, 4), s32 *, 0x10);
    if (temp_a1 == 0) {
        SetTag__4CRef4TAGK(0);
    } else {
        CRef_ConstructPair(arg0, temp_a1);
    }
    return arg0;
}
