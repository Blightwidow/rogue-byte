#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK StartMurrayLift(s32, s32);                  /* extern */
M2C_UNK func_00184130();                            /* extern */

void LiftPt_OnGrab(s32 arg0, s32 arg1) {
    func_00184130();
    if (FIsBasicDerivedFrom(arg1, 0x36) != 0) {
        StartMurrayLift(arg1, arg0);
    }
}
