#include "m2c_macros.h"

M2C_UNK BuildImageGifs__FiiiiiiP4GIFS(s32, M2C_UNK, M2C_UNK, s32); /* extern */

void BuildClutGifs__FP4CLUTiP4GIFS(void *arg0, s32 arg1, s32 arg2) {
    BuildImageGifs__FiiiiiiP4GIFS(arg1, 1, 0, ((u16) M2C_FIELD(arg0, u16 *, 8) >= 0x11U) ? 0x10 : 8);
}
