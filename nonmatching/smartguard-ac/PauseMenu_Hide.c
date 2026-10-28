#include "m2c_macros.h"

M2C_UNK CGc_PopScreen();                            /* extern */
M2C_UNK ClearHandsOff(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK SetClockRate(M2C_UNK *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dded0;

void PauseMenu_Hide(void *arg0) {
    CGc_PopScreen();
    SetClockRate(&g_2dded0, 0, 0x3F800000);
    ClearHandsOff(&B_003DD490, 0);
    bevy_camera_follow_activity(&B_002DEB30, 0x2C, 0);
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
}
