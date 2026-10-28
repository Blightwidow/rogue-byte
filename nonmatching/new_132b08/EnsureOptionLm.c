#include "m2c_macros.h"

M2C_UNK CRef_ConstructLm(M2C_UNK *, s32);           /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK RefEnsureOption__FP5BASICiP4CRef(M2C_UNK *, s32, s32, M2C_UNK *); /* extern */

void EnsureOptionLm(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp10;

    CRef_ConstructLm(sp, arg2);
    RefEnsureOption__FP5BASICiP4CRef(&sp10, arg0, arg1, sp);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
}
