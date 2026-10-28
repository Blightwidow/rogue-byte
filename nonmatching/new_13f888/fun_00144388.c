#include "m2c_macros.h"

s32 FIgnoreSoIntersection();                        /* extern */
M2C_UNK func_001CC9A8(s32, s32, s32);               /* extern */
s32 func_00220498(s32, s32, s32);                   /* extern */

void func_00144388(s32 arg0, s32 arg1) {
    func_001CC9A8(arg0 + 0x900, arg1, func_00220498(arg0 + 0x11B0, arg1, FIgnoreSoIntersection()));
}
