#include "m2c_macros.h"

M2C_UNK snd_SetPlaybackMode(s32);                   /* extern */

void SetSndPlaybackMode(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x104) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x104) = arg1;
        snd_SetPlaybackMode(arg1);
    }
}
