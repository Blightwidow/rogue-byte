#include "m2c_macros.h"

M2C_UNK HandleLoMessage(s32, s32, void *);          /* extern */
M2C_UNK SetJumperState(M2C_UNK);                    /* extern */

void HandleJumperMessage(s32 arg0, s32 arg1, void *arg2) {
    if ((arg1 == 9) && (M2C_FIELD(arg2, s32 *, 8) == 0x22)) {
        SetJumperState(1);
    }
    HandleLoMessage(arg0, arg1, arg2);
}
