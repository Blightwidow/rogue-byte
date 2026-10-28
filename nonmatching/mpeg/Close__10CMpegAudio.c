#include "m2c_macros.h"

M2C_UNK snd_CloseMovieSound();                      /* extern */
M2C_UNK snd_ContinueAllSoundsInGroup(M2C_UNK);      /* extern */
M2C_UNK snd_SetMasterVolume(M2C_UNK, s32);          /* extern */

void Close__10CMpegAudio(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    snd_CloseMovieSound();
    snd_SetMasterVolume(2, M2C_FIELD(arg0, s32 *, 0xA0));
    snd_SetMasterVolume(0x10, M2C_FIELD(arg0, s32 *, 0xA4));
    snd_ContinueAllSoundsInGroup(0xFFFFFFFF);
}
