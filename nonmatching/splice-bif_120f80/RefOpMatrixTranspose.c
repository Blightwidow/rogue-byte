#include "m2c_macros.h"

M2C_UNK CRef_ConstructMatrix(void *, M2C_UNK *);    /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK TransposeMatrix4(M2C_UNK *, s32);           /* extern */

s32 RefOpMatrixTranspose(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp10;

    TransposeMatrix4(&sp10, M2C_FIELD(arg2, s32 *, 4));
    CRef_ConstructMatrix(sp, &sp10);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
