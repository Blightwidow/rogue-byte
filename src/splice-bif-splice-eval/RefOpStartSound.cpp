#include "m2c_macros.h"

M2C_UNK CRef_ConstructBasic(s32, s32);              /* extern */
s32 NewEmitter(s32);                                /* extern */
M2C_UNK SetEmitterUnpositioned(s32, s32);           /* extern */

s32 RefOpStartSound(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = M2C_FIELD(arg2, s32 *, 0xC);
    temp_v0 = NewEmitter(M2C_FIELD(arg2, s32 *, 4));
    SetEmitterUnpositioned(temp_v0, temp_s1);
    CRef_ConstructBasic(arg0, temp_v0);
    return arg0;
}
