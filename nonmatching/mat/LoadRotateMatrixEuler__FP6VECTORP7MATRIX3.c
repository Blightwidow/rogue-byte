#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(f32 *, f32 *, M2C_UNK); /* extern */

void *LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp4;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 temp_f1;
    f32 temp_f3;

    CalculateSinCos__FfPfT1(sp, &sp4, M2C_ERROR(/* unknown instruction: por $s0, $zero, $a1 */));
    CalculateSinCos__FfPfT1(&sp8, &spC, M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */));
    CalculateSinCos__FfPfT1(&sp10, &sp14, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */));
    temp_f1 = sp0 * sp8;
    temp_f3 = sp4 * sp8;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) ((temp_f1 * sp10) + (sp4 * sp14));
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) ((temp_f1 * sp14) - (sp4 * sp10));
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) ((temp_f3 * sp14) + (sp0 * sp10));
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) ((temp_f3 * sp10) - (sp0 * sp14));
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (sp4 * spC);
    M2C_FIELD(arg0, f32 *, 8) = (f32) -sp8;
    M2C_FIELD(arg0, f32 *, 0) = (f32) (spC * sp14);
    M2C_FIELD(arg0, f32 *, 4) = (f32) (spC * sp10);
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (sp0 * spC);
    return arg0;
}
