#include "m2c_macros.h"

M2C_UNK snd_ContinueSound(s32);                     /* extern */

void ContinueAmbVoice(void *arg0) {
    snd_ContinueSound(M2C_FIELD(arg0, s32 *, 0x40));
}
