#include "m2c_macros.h"

M2C_UNK GoalHit_Activate(void *);                   /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
M2C_UNK func_00154038(s32, s32, M2C_UNK);           /* extern */
s32 func_001F78A0(s32);                             /* extern */
extern M2C_UNK B_002DEB30;

void func_001796D0(void *arg0) {
    s32 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x10) + ((func_001F78A0(M2C_FIELD(arg0, s32 *, 0x5C)) * 0x10) + 0xA70);
    M2C_FIELD(arg0, s32 **, 0x40) = temp_v1;
    if (*temp_v1 == -1) {
        M2C_FIELD(arg0, s32 **, 0x40) = NULL;
    }
    GoalHit_Activate(arg0);
    bevy_camera_follow_activity(&B_002DEB30, 0x15, M2C_FIELD(arg0, void **, 0x10));
    func_00154038(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF64), M2C_FIELD(arg0, s32 *, 0x50), 2);
}
