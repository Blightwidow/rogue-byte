#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(f32 *, f32 *, M2C_UNK); /* extern */

s32 ConvertDeulToW__FP6VECTORN20(void) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;

    M2C_ERROR(/* unknown instruction: por $s0, $zero, $a0 */);
    M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
    CalculateSinCos__FfPfT1(&sp10, &sp14, M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */));
    CalculateSinCos__FfPfT1(&sp18, &sp1C, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */));
    M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */);
    M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
}
