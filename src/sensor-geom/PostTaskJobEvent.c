#include "m2c_macros.h"

M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_002DEB30;

void PostTaskJobEvent(void *arg0) {
    bevy_camera_follow_activity(&B_002DEB30, 0x1E, M2C_FIELD(arg0, s32 *, 0x7C));
}
