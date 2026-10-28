#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */
M2C_UNK bevy_player_p6_182c70(s32);                 /* extern */

void AttachCyl_Init(s32 arg0) {
    InitXfm();
    bevy_player_p6_182c70(arg0 + 0xE0);
}
