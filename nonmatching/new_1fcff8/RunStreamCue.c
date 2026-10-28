#include "m2c_macros.h"

M2C_UNK SetAloEyesClosed(s32, void *, M2C_UNK, s32); /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID(s32, s32, void *, M2C_UNK); /* extern */

void RunStreamCue(void *arg0, void *arg1) {
    s16 temp_v1;
    s32 temp_a0;
    s32 temp_a1;

    temp_v1 = M2C_FIELD(arg1, s16 *, 2);
    if ((temp_v1 != -1) && (temp_a0 = M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x22C), (temp_a0 != 0))) {
        if (temp_v1 != 3) {
            temp_a1 = M2C_FIELD(arg1, s32 *, 4);
            if (temp_a1 != -1) {
                SetSmaGoal__FP3SMA3OID(temp_a0, temp_a1, arg0, -1);
            }
        } else {
            SetAloEyesClosed(M2C_FIELD(arg0, s32 *, 0x238), arg0, -1, M2C_FIELD(arg1, s32 *, 4));
        }
    }
}
