#include "m2c_macros.h"

M2C_UNK CalculateSinCos__FfPfT1(f32 *, f32 *);      /* extern */

s32 SetVectorCylind__FP6VECTORfff(f32 fparg1, f32 fparg2) {
    f32 sp10;
    f32 sp14;

    CalculateSinCos__FfPfT1(&sp10, &sp14);
    M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
    M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
    return M2C_ERROR(/* unknown instruction: por $v0, $zero, $v1 */);
}
