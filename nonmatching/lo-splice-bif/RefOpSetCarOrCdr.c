#include "m2c_macros.h"

M2C_UNK PairHandle_Assign(s32, s32);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32, M2C_UNK);           /* extern */
M2C_UNK __as__4CRefRC4CRef(s32, void *);            /* extern */

s32 RefOpSetCarOrCdr(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg2, s32 *, 4);
    if (M2C_ERROR(/* Read from unset register $t0 */) == 0x23) {
        __as__4CRefRC4CRef(temp_a0 + 8, arg2 + 8);
    } else if (M2C_FIELD(arg2, s32 *, 8) != 0x1F) {
        PairHandle_Assign(temp_a0 + 0x10, 0);
    } else {
        PairHandle_Assign(temp_a0 + 0x10, M2C_FIELD(arg2, s32 *, 0xC));
    }
    SetTag__4CRef4TAGK(arg0, 0x24);
    return arg0;
}
