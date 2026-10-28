#include "m2c_macros.h"

M2C_UNK CRef_ConstructMatrix(void *, s32);          /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */

s32 RefOpMatrixDecomposeToRotate(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    CRef_ConstructMatrix(sp, M2C_FIELD(arg2, s32 *, 4));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
