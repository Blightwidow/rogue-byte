#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CalculateDmat4(s32, s32, s32);              /* extern */
M2C_UNK SetTag__4CRef4TAGK(void *, M2C_UNK);        /* extern */

s32 RefOpMatrixCalculateDmat(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    SetTag__4CRef4TAGK(sp, 0x1B);
    CalculateDmat4(M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC), sp4);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
