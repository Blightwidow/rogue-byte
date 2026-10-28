#include "m2c_macros.h"

M2C_UNK JT_EndPose(void *);                         /* extern */
M2C_UNK ReleaseAloSmKinds();                        /* extern */

void JT_ReleaseSmKinds(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    ReleaseAloSmKinds();
    if (arg2 != 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x12F4) - 1;
        M2C_FIELD(arg0, s32 *, 0x12F4) = temp_v0;
        if (temp_v0 == 0) {
            JT_EndPose(arg0);
        }
    }
}
