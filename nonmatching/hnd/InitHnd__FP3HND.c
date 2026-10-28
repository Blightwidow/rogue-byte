#include "m2c_macros.h"

M2C_UNK InitTarget();                               /* extern */
M2C_UNK bevy_player_p6_182c70(s32);                 /* extern */

void InitHnd__FP3HND(void *arg0) {
    InitTarget();
    bevy_player_p6_182c70(arg0 + 0x100);
    M2C_FIELD(arg0, s32 *, 0xE8) = 1;
    M2C_FIELD(arg0, s32 *, 0x130) = 9;
    M2C_FIELD(arg0, s32 *, 0x12C) = 8;
}
