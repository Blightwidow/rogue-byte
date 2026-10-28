#include "m2c_macros.h"

M2C_UNK Reset__10CByteQueue(void *);                /* extern */
M2C_UNK Reset__15CQueueOutputIop(void *);           /* extern */
M2C_UNK snd_ResetMovieSound();                      /* extern */

void Reset__10CMpegAudio(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        snd_ResetMovieSound();
        M2C_FIELD(arg0, s32 *, 0) = 1;
        M2C_FIELD(arg0, s32 *, 4) = -1;
        Reset__10CByteQueue(arg0 + 0x30);
        Reset__10CByteQueue(arg0 + 0x50);
        Reset__15CQueueOutputIop(arg0 + 0x70);
    }
}
