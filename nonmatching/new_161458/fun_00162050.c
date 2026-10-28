#include "m2c_macros.h"

M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 GrfOfStates(s32, void *);                       /* extern */
M2C_UNK func_002013D8(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */

s32 func_00162050(s32 arg0) {
    char sp[0x400];
    M2C_UNK sp20;
    s32 sp30;
    s32 temp_s0;

    func_002013D8(&sp20, arg0, 0x1050, 6);
    temp_s0 = GrfOfStates(sp30, sp);
    CRef_Destruct(&sp20);
    return temp_s0;
}
