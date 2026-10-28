#include "m2c_macros.h"

M2C_UNK JT_StartPose(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RetainAloSmKinds();                         /* extern */
M2C_UNK SetBinocState(void *, M2C_UNK);             /* extern */

void JT_RetainSmKinds(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    RetainAloSmKinds();
    if (arg2 != 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x12F4) + 1;
        M2C_FIELD(arg0, s32 *, 0x12F4) = temp_v0;
        if (temp_v0 == 1) {
            JT_StartPose(arg0, 0x60B, 9, 5);
            SetBinocState(arg0 + 0xF00, -1);
        }
    }
}
