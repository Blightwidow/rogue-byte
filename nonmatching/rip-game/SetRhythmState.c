#include "m2c_macros.h"

M2C_UNK ClearHandsOff(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void SetRhythmState(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v0 != arg1) {
        if (temp_v0 == 1) {
            ClearHandsOff(&B_003DD490, 3);
        }
        M2C_FIELD(arg0, s32 *, 0x50) = arg1;
        M2C_FIELD(arg0, s32 *, 0x1C0) = 0;
        M2C_FIELD(arg0, f32 *, 0x54) = (f32) g_2dded0;
        if (arg1 == 1) {
            SetHandsOff(&B_003DD490, 3);
        }
    }
}
