#include "m2c_macros.h"

s32 FGoalAnimDone(s32);                             /* extern */
s32 func_001C1FA0(void *, void *, M2C_UNK);         /* extern */

s32 func_0017EAE8(void *arg0) {
    if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFE8) & 1)) {
        goto block_7;
    }
    if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
block_7:
        return func_001C1FA0(arg0 + 0x30, M2C_FIELD(arg0, void **, 0x10), 0x41C80000);
    }
    return 0;
}
