#include "m2c_macros.h"

M2C_UNK BuildAllDrawEnvGifs();                      /* extern */
M2C_UNK FlushSaaUnpacks();                          /* extern */
M2C_UNK SendDmaSyncGsFinish__FP10sceDmaChanP2QW(s32, s32); /* extern */
extern s32 g_2de594;
extern s32 g_2de598;

void RenderFrame__FP3FRMi(void *arg0, s32 arg1) {
    FlushSaaUnpacks();
    BuildAllDrawEnvGifs();
    SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de594, M2C_FIELD(arg0, s32 *, 0x24));
    if (arg1 != 0) {
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, M2C_FIELD(arg0, s32 *, 4));
    }
}
