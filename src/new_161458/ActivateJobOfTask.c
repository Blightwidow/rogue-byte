#include "m2c_macros.h"

M2C_UNK DropJtLoot(s32);                            /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FIsCurrentJob();                                /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK SetCurrentJob(s32);                         /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;

void ActivateJobOfTask(s32 arg0) {
    s32 temp_v0;

    if (FIsCurrentJob() == 0) {
        bevy_camera_follow_activity(&B_002DEB30, 0x1C, arg0);
        temp_v0 = PpoSwFocusBase(&B_003DD490);
        if ((temp_v0 != 0) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0)) {
            DropJtLoot(temp_v0);
        }
        SetCurrentJob(arg0);
    }
}
