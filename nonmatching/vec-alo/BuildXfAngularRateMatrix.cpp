#include "m2c_macros.h"
extern "C" {

M2C_UNK BuildXfSpinRateMatrix(void *, s32, M2C_UNK, s32); /* extern */
M2C_UNK ConvertDeulToW__FP6VECTORN20(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK memcpy(s32, void *, M2C_UNK);               /* extern */

s32 BuildXfAngularRateMatrix(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x40];
    ConvertDeulToW__FP6VECTORN20(M2C_ERROR(/* unknown instruction: por $a0, $zero, $a3 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $t0 */));
    BuildXfSpinRateMatrix(sp, arg1, M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */), arg2);
    memcpy(arg0, sp, 0x40);
    return arg0;
}
}
