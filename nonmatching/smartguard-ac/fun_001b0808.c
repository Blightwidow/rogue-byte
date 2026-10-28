#include "m2c_macros.h"

M2C_UNK JobMenu_SetPage(M2C_UNK *, s32);            /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DA3C0;
extern s32 B_003E0F9C;

void func_001B0808(void) {
    bevy_camera_follow_activity(&B_002DEB30, 0x2B, 0);
    JobMenu_SetPage(&B_003DA3C0, B_003E0F9C != 0);
}
