#include "m2c_macros.h"

M2C_UNK InsertXfAct(s32, s32, s32);                 /* extern */
s32 PactNewForXf(M2C_UNK, s32, s32, s32);           /* extern */

s32 CreateXfActadj(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = PactNewForXf(5, arg0, arg1, arg2);
    InsertXfAct(arg0, arg1, temp_v0);
    return temp_v0;
}
