#include "m2c_macros.h"

M2C_UNK StartBootQueue(M2C_UNK *);                  /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001A2C20(M2C_UNK);                     /* extern */
M2C_UNK func_001A2DA0(s32);                         /* extern */
s32 sceScfGetLanguage();                            /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E1E88;

void func_001613A8(void) {
    func_001A2C20(0);
    func_001A2DA0(sceScfGetLanguage());
    bevy_camera_follow_activity(&B_002DEB30, 0, 0);
    StartBootQueue(&B_002E1E88);
}
