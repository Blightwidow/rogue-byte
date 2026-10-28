#include "m2c_macros.h"

M2C_UNK bevy_classes_k30_cam_150ef0();              /* extern */

void bevy_classes_k30_cam_set(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
        bevy_classes_k30_cam_150ef0();
    }
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}
