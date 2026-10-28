#include "m2c_macros.h"

M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK RefEnsureOption__FP5BASICiP4CRef(M2C_UNK *, s32, s32, M2C_UNK *, s32, f32); /* extern */

void EnsureOptionFloat(s32 arg0, s32 arg1, f32 fparg0) {
    char sp[0x400];
    M2C_UNK sp10;

    RefEnsureOption__FP5BASICiP4CRef(&sp10, arg0, arg1, sp, 0x16, fparg0);
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
}
