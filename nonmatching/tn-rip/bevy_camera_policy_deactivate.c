#include "m2c_macros.h"

M2C_UNK DeactivateCplcy();                          /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
extern M2C_UNK B_002DDF40;

void bevy_camera_policy_deactivate(void *arg0, s32 arg1, void *arg2) {
    void *temp_a1;
    void *temp_v1;

    DeactivateCplcy();
    if (M2C_FIELD(arg2, s32 *, 0xC) != 0) {
        SetResetFlag__FP2CM(&B_002DDF40);
    }
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0x14);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x10), temp_a1);
    M2C_FIELD(arg0, void **, 0x10) = NULL;
}
