#include "m2c_macros.h"

M2C_UNK InitSo();                                   /* extern */
M2C_UNK SetAloInteract(void *, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK bevy_player_p6_182c70(s32);                 /* extern */

void InitHbsk__FP4HBSK(void *arg0) {
    InitSo();
    bevy_player_p6_182c70(arg0 + 0x150);
    M2C_FIELD(arg0, s32 *, 0x17C) = 0;
    M2C_FIELD(arg0, f32 *, 0x158) = 300.0f;
    M2C_FIELD(arg0, s32 *, 0x18C) = 1;
    SetAloInteract(arg0, 0x03FFFFFF, 8);
    SetAloInteract(arg0, 0x03188001, 0);
}
