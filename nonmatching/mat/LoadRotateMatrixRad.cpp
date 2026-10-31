#include "m2c_macros.h"
extern "C" {

M2C_UNK CalculateSinCos__FfPfT1(void);      /* extern */
void LoadRotateMatrixSinCos(void *, s32, f32, f32); /* extern */
M2C_UNK memcpy(s32, void *, M2C_UNK);               /* extern */

s32 LoadRotateMatrixRad(s32 arg0) {
    unsigned char sp[0x50];
    s32 sp40;
    s32 sp44;

    M2C_ERROR(/* unknown instruction: por $s0, $zero, $a1 */);
    CalculateSinCos__FfPfT1();
    LoadRotateMatrixSinCos(sp, sp40, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_ERROR(/* unknown instruction: por $a3, $zero, $s0 */));
    memcpy(arg0, sp, 0x30);
    return arg0;
}
}
