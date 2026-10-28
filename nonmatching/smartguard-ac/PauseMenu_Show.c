#include "m2c_macros.h"

M2C_UNK CGc_PushScreen();                           /* extern */
M2C_UNK SetClockRate(M2C_UNK *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dded0;

void PauseMenu_Show(void) {
    CGc_PushScreen();
    SetClockRate(&g_2dded0, 0, 0);
    SetHandsOff(&B_003DD490, 0);
    bevy_camera_follow_activity(&B_002DEB30, 0x28, 0);
}
