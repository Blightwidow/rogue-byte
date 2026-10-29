#include "m2c_macros.h"
extern "C" {

M2C_UNK SetAmbSlotPan(s32, s32, s32);               /* extern */
M2C_UNK SetAmbSlotVolume(s32, s32, f32);            /* extern */
s32 func_001FE990(M2C_UNK *);                       /* extern */
extern M2C_UNK B_003DD040;

void func_001FF108(f32 fparg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s1;
    s32 temp_v0;

    temp_v0 = func_001FE990(&B_003DD040);
    temp_s1 = M2C_FIELD(&B_003DD040, s32 *, 0x228);
    SetAmbSlotVolume(temp_s1, temp_v0, fparg0);
    SetAmbSlotPan(temp_s1, temp_v0, arg3);
}
}
