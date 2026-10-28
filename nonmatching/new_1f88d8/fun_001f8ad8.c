#include "m2c_macros.h"

M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32);         /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *, s128, s128, s128, s128); /* extern */
M2C_UNK func_001F89E0(void *, s32, s32, M2C_UNK);   /* extern */

void func_001F8AD8(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp30;

    ConvertXfMat(&sp30, 0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0xA0));
    DecomposeRotateMatrixEuler(sp, sp30, sp30, sp40, sp50);
    func_001F89E0(arg0, arg1, arg2, M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */));
}
