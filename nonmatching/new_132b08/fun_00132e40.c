#include "m2c_macros.h"

M2C_UNK CRef_ConstructBasic(M2C_UNK *, M2C_UNK);    /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK RefEnsureOption__FP5BASICiP4CRef(M2C_UNK *, s32, s32, M2C_UNK *); /* extern */

void func_00132E40(s32 arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp10;

    CRef_ConstructBasic(sp, 0);
    RefEnsureOption__FP5BASICiP4CRef(&sp10, arg0, arg1, sp);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
}
