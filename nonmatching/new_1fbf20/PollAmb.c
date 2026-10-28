#include "m2c_macros.h"

M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK snd_SoundIsStillPlaying_CB(s32, M2C_UNK *, void *); /* extern */
extern M2C_UNK OnAmbVoicePolled;

void PollAmb(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, u16 *, 0x50) & 0x400) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        snd_SoundIsStillPlaying_CB(M2C_FIELD(arg0, s32 *, 0x40), &OnAmbVoicePolled, arg0);
        SetAmbGrf(arg0, 0x400, 0);
    }
}
