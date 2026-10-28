#include "m2c_macros.h"

M2C_UNK snd_PauseSound(s32);                        /* extern */

void PauseAmbVoice(void *arg0) {
    snd_PauseSound(M2C_FIELD(arg0, s32 *, 0x40));
}
