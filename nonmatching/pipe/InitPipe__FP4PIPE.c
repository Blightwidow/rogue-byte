#include "m2c_macros.h"

M2C_UNK InitCrv();                                  /* extern */
M2C_UNK bevy_player_p6_182c70(s32);                 /* extern */
extern s128 g_2a2da0;

void InitPipe__FP4PIPE(void *arg0) {
    InitCrv();
    bevy_player_p6_182c70(arg0 + 0x190);
    M2C_FIELD(arg0, s32 *, 0x1AC) = 1;
    M2C_FIELD(arg0, s128 *, 0x1C0) = (s128) g_2a2da0;
    M2C_FIELD(arg0, s32 *, 0x1D4) = 9;
    M2C_FIELD(arg0, s32 *, 0x1D0) = 8;
}
