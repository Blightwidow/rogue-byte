#include "m2c_macros.h"

void bevy_camera_cm_14e148(void *arg0, void *arg1) {
    if (arg1 != M2C_FIELD(arg0, void **, 0x10)) {
        M2C_FIELD(arg0, void **, 0x10) = arg1;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0xE0);
    }
}
