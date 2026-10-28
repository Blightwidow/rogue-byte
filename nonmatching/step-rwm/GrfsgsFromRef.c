#include "m2c_macros.h"

M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 GrfsgsFromAsgs(s32, void *);                    /* extern */
M2C_UNK func_002013D8(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */

s32 GrfsgsFromRef(s32 arg0) {
    char sp[0x400];
    M2C_UNK sp40;
    s32 sp50;
    s32 temp_s0;

    func_002013D8(&sp40, arg0, 0x1010, 0x10);
    temp_s0 = GrfsgsFromAsgs(sp50, sp);
    CRef_Destruct(&sp40);
    return temp_s0;
}
