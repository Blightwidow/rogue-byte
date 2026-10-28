#include "m2c_macros.h"

M2C_UNK DeactivateCplcy(s32, s32, s32);             /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK func_0012E460(s32);                         /* extern */
extern M2C_UNK B_002DDF40;

void bevy_camera_looks_deactivate(s32 arg0, s32 arg1, s32 arg2) {
    func_0012E460(arg0 + 0x14);
    SetResetFlag__FP2CM(&B_002DDF40);
    DeactivateCplcy(arg0, arg1, arg2);
}
