#include "m2c_macros.h"

M2C_UNK CPLCY_Destruct();                           /* extern */
extern M2C_UNK D_FLT_002C41A8;

void bevy_camera_follow_new(void *arg0) {
    CPLCY_Destruct();
    M2C_FIELD(&D_FLT_002C41A8, f32 *, 0) = -3.4028235e38f;
    M2C_FIELD(&D_FLT_002C41A8, f32 *, 4) = 3.4028235e38f;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}
