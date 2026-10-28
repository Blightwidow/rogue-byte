#include "m2c_macros.h"

M2C_UNK InitCrv();                                  /* extern */
M2C_UNK bevy_player_p6_182c70(s32);                 /* extern */

void func_001CB908(void *arg0) {
    InitCrv();
    bevy_player_p6_182c70(arg0 + 0x190);
    M2C_FIELD(arg0, f32 *, 0x1C4) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x1C0) = 1000.0f;
}
