#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_RefCoerceF32(void *, s32);             /* extern */
s32 FCheckLm__FP2LMf(s32, f32);                     /* extern */

void *RefOpLmCheck(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = M2C_FIELD(arg2, s32 *, 4);
    CRef_RefCoerceF32(sp, arg2 + 8);
    temp_v0 = FCheckLm__FP2LMf(temp_s0, sp4) != 0;
    M2C_FIELD(arg0, s32 *, 0) = 0x17;
    M2C_FIELD(arg0, s32 *, 4) = temp_v0;
    CRef_Destruct(sp);
    return arg0;
}
