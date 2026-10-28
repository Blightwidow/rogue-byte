#include "m2c_macros.h"

M2C_UNK snd_AutoVol(s32, M2C_UNK, f32, M2C_UNK);    /* extern */
M2C_UNK snd_StopSound(s32, M2C_UNK);                /* extern */

void StopSound__FP3AMBi(void *arg0) {
    f32 temp_f1;

    temp_f1 = M2C_FIELD(arg0, f32 *, 0x48);
    if (temp_f1 > 0.0f) {
        snd_AutoVol(M2C_FIELD(arg0, s32 *, 0x40), -4, temp_f1, 2);
        return;
    }
    snd_StopSound(M2C_FIELD(arg0, s32 *, 0x40), -4);
}
