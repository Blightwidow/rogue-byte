#include "m2c_macros.h"

M2C_UNK ActivateCplcy();                            /* extern */

void bevy_camera_policy_activate(void *arg0, s32 arg1, void *arg2) {
    void *temp_a1;
    void *temp_v0;

    ActivateCplcy();
    M2C_FIELD(arg0, void **, 0x10) = arg2;
    temp_a1 = M2C_FIELD(arg2, void **, 0x14);
    temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0xC)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 8), temp_a1);
}
