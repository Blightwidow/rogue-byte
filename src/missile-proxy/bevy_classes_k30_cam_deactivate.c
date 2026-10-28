#include "m2c_macros.h"

M2C_UNK DeactivateCplcy(void *, s32, void *);       /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
extern M2C_UNK B_002DDF40;

void bevy_classes_k30_cam_deactivate(void *arg0, s32 arg1, void *arg2) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == arg2) {
        if (M2C_FIELD(arg2, s32 *, 0x120) != 0) {
            SetResetFlag__FP2CM(&B_002DDF40);
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    DeactivateCplcy(arg0, arg1, arg2);
}
