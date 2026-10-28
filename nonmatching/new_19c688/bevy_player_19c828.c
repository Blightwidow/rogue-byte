#include "m2c_macros.h"

M2C_UNK SetJmpBodyState(M2C_UNK, M2C_UNK);          /* extern */
M2C_UNK SetJmpState(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */

void bevy_player_19c828(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0x11) {
        SetJmpState(3, 0, 0);
        return;
    }
    SetJmpBodyState(4, 0);
}
