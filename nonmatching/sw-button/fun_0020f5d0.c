#include "m2c_macros.h"

s32 S32Read__18CBinaryInputStream(s32);             /* extern */
extern s32 B_003E1C30;
extern s32 B_003E1C54;
extern s32 B_003E1C58;

void func_0020F5D0(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_v0;

    temp_s2 = S32Read__18CBinaryInputStream(arg1);
    temp_v0 = S32Read__18CBinaryInputStream(arg1);
    B_003E1C30 = temp_s2;
    B_003E1C54 = ((temp_v0 ^ B_003E1C58) != 0) ? 1 : arg0;
    B_003E1C58 = temp_v0;
}
