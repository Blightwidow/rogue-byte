#include "m2c_macros.h"

M2C_UNK ActivateCplcy();                            /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
extern M2C_UNK B_002DDF40;

void bevy_classes_k30_cam_activate(void *arg0, s32 arg1, void *arg2) {
    f32 temp_f12;

    ActivateCplcy();
    M2C_FIELD(arg0, void **, 0x10) = arg2;
    temp_f12 = M2C_FIELD(arg2, f32 *, 0x130);
    if (temp_f12 != 0.0f) {
        SetCmFov(&B_002DDF40, temp_f12);
    }
}
