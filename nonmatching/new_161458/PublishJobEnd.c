#include "m2c_macros.h"

M2C_UNK SetTaskState(s32, M2C_UNK);                 /* extern */
M2C_UNK StopJobIfCurrent(void *);                   /* extern */
M2C_UNK TryAutosave(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E65E0;

void PublishJobEnd(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x78) == 0) {
        SetTaskState(M2C_FIELD(arg0, s32 *, 0x68), 3);
    }
    bevy_camera_follow_activity(&B_002DEB30, 0x20, arg0);
    StopJobIfCurrent(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x78) == 0) {
        TryAutosave(&B_002E65E0, 0);
    }
}
