#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK CGc_PopScreen();                            /* extern */
M2C_UNK ClearHandsOff(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK SetClockRate(M2C_UNK *, M2C_UNK, f32);  /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dded0;

void PauseMenu_Hide(s8 *arg0) {
    CGc_PopScreen();
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    SetClockRate(&g_2dded0, 0, 1.0f);
    ClearHandsOff(&B_003DD490, 0);
    bevy_camera_follow_activity(&B_002DEB30, 0x2C, 0);
}

}
