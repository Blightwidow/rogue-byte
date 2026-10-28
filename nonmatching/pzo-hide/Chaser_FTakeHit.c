#include "m2c_macros.h"

M2C_UNK Chaser_SetState(void *, M2C_UNK);           /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
s32 func_0017F1D0(void *);                          /* extern */
extern M2C_UNK B_002DEB30;

s32 Chaser_FTakeHit(void *arg0) {
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1C0) != 4) {
        if (func_0017F1D0(arg0) != 0) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x184);
            if (temp_v0 >= 0) {
                if (temp_v0 <= 0) {
                    bevy_camera_follow_activity(&B_002DEB30, 0x18, arg0);
                }
                Chaser_SetState(arg0, 4);
            }
            var_v0 = 1;
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        }
        return 0;
    }
    return var_v0;
}
