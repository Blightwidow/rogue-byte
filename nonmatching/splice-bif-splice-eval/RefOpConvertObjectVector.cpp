#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_CopyConstruct();            /* extern */
M2C_UNK CRef_Destruct();                      /* extern */
void SetTag__4CRef4TAGK();        /* extern */
s128 bevy_camera_follow_track_heading_weight(); /* extern */

s32 RefOpConvertObjectVector(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x10];
    u8 *sp4;
    SetTag__4CRef4TAGK(sp, 0x1A);
    *sp4 = bevy_camera_follow_track_heading_weight(M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC), *M2C_FIELD(arg2, s128 **, 0x14));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
