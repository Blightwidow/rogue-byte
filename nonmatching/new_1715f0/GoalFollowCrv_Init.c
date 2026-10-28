#include "m2c_macros.h"

M2C_UNK func_001EEF68();                            /* extern */
extern f32 D_FLT_002BE624;
extern f32 D_FLT_002BE628;
extern f32 D_FLT_002BE62C;

void GoalFollowCrv_Init(void *arg0) {
    func_001EEF68();
    M2C_FIELD(arg0, s32 *, 0xA0) = 1;
    M2C_FIELD(arg0, f32 *, 0x34) = -1.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) D_FLT_002BE62C;
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) D_FLT_002BE624;
    M2C_FIELD(arg0, f32 *, 0x6C) = (f32) D_FLT_002BE628;
    M2C_FIELD(arg0, s32 *, 0x4C) = -1;
    M2C_FIELD(arg0, f32 *, 0x48) = -1.0f;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
}
