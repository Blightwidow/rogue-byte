#include "m2c_macros.h"

M2C_UNK PauseMenu_SetState(M2C_UNK);                /* extern */

void func_001AF490(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1E8) == 7) {
        PauseMenu_SetState(3);
        M2C_FIELD(arg0, s32 *, 0x1EC) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - 1);
    }
}
