#include "m2c_macros.h"

M2C_UNK PostScriptMessage();                        /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_002DEB30;

void HandleLoSpliceEvent(s32 arg0, s32 arg1) {
    PostScriptMessage();
    switch (arg1) {                                 /* irregular */
    case 5:
        bevy_camera_follow_activity(&B_002DEB30, 0x1A, arg0);
        return;
    case 6:
        bevy_camera_follow_activity(&B_002DEB30, 0x1B, arg0);
        break;
    }
}
