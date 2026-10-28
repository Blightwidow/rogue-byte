#include "m2c_macros.h"

M2C_UNK CRef_ConstructVectorValue(void *, M2C_UNK); /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK DecomposeRotateMatrixEuler(s32);            /* extern */

s32 RefOpMatrixDecomposeToEuler(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    DecomposeRotateMatrixEuler(M2C_FIELD(arg2, s32 *, 4));
    CRef_ConstructVectorValue(sp, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
