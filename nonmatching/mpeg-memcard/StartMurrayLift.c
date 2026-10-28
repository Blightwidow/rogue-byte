#include "m2c_macros.h"

M2C_UNK SetMurrayState(M2C_UNK);                    /* extern */
M2C_UNK func_002046F0(void *, s32);                 /* extern */

void StartMurrayLift(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x13EC) != 0) {
        M2C_FIELD(arg0, void **, 0x13F0) = arg1;
        SetMurrayState(4);
        M2C_FIELD(arg0, s32 *, 0x144C) = 0;
        func_002046F0(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x13F0), s32 *, 0x180));
    }
}
