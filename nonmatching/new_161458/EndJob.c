#include "m2c_macros.h"

M2C_UNK LeaveTaskIfCurrent(void *);                 /* extern */
M2C_UNK ResetJob();                                 /* extern */
M2C_UNK SetTaskState(s32, M2C_UNK);                 /* extern */
M2C_UNK StopJobIfCurrent(void *);                   /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
extern M2C_UNK B_002DEB30;
extern void *B_003E0FA0;

void EndJob(void *arg0) {
    ResetJob();
    SetTaskState(M2C_FIELD(arg0, s32 *, 0x64), 1);
    if ((B_003E0FA0 != NULL) && (M2C_FIELD(B_003E0FA0, s32 *, 0x7C) == arg0)) {
        LeaveTaskIfCurrent(B_003E0FA0);
    }
    bevy_camera_follow_activity(&B_002DEB30, 0x1F, arg0);
    StopJobIfCurrent(arg0);
}
