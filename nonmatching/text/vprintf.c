#include "m2c_macros.h"

s32 CchOstrmPrintf__FP5OSTRMPcT1(void *, s32, s32); /* extern */
M2C_UNK __5OSTRMi(void *, M2C_UNK);                 /* extern */
M2C_UNK func_0020D618(void *, M2C_UNK);             /* extern */

s32 vprintf(s32 arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_s0;

    __5OSTRMi(sp, -1);
    temp_s0 = CchOstrmPrintf__FP5OSTRMPcT1(sp, arg0, arg1);
    func_0020D618(sp, 2);
    return temp_s0;
}
