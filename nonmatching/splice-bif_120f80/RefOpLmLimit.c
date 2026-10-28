#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CRef_RefCoerceF32(void *, s32);             /* extern */
f32 GLimitLm__FP2LMf(s32, f32);                     /* extern */

void *RefOpLmLimit(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg2, s32 *, 4);
    CRef_RefCoerceF32(sp, arg2 + 8);
    M2C_FIELD(arg0, f32 *, 4) = GLimitLm__FP2LMf(temp_s0, sp4);
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    CRef_Destruct(sp);
    return arg0;
}
