#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(s32 *, s32 *);      /* extern */
M2C_UNK LoadRotateMatrixSinCos(void *, s32, M2C_UNK, M2C_UNK, s128); /* extern */
M2C_UNK memcpy(s32, void *, M2C_UNK);               /* extern */

s32 LoadRotateMatrixRad(s32 arg0) {
    char sp[0x400];
    s32 sp40;
    s32 sp44;

    M2C_ERROR(/* unknown instruction: por $s0, $zero, $a1 */);
    CalculateSinCos__FfPfT1(&sp40, &sp44);
    LoadRotateMatrixSinCos(sp, sp40, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_ERROR(/* unknown instruction: por $a3, $zero, $s0 */), (s128) sp44);
    memcpy(arg0, sp, 0x30);
    return arg0;
}
