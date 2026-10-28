#include "m2c_macros.h"

M2C_UNK PlayRootSpriteLabel(s32);                   /* extern */
M2C_UNK SetBlotModal(void *, M2C_UNK);              /* extern */

void PlayBlotLabel(void *arg0, s32 arg1) {
    void *temp_v0;

    PlayRootSpriteLabel(M2C_FIELD(arg0, s32 *, 0x84));
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0xAC)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xA8), 1);
    if (M2C_FIELD(arg0, s32 *, 0xAC) != 0) {
        SetBlotModal(arg0, 0);
    }
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
}
