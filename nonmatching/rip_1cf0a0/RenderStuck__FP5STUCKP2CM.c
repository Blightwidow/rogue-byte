#include "m2c_macros.h"

M2C_UNK ConvertXfMat(s128 *, s32, M2C_UNK, void *); /* extern */
M2C_UNK ConvertXfPos(s32, M2C_UNK, s128);           /* extern */
M2C_UNK FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(void *, M2C_UNK, void *, s128, s128, s128, s128); /* extern */

void RenderStuck__FP5STUCKP2CM(void *arg0) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp30;

    ConvertXfPos(M2C_FIELD(arg0, s32 *, 0xF0), 0, M2C_FIELD(arg0, s128 *, 0x70));
    M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */);
    ConvertXfMat(&sp30, M2C_FIELD(arg0, s32 *, 0xF0), 0, arg0 + 0x40);
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s1 */), sp, sp30, sp30, sp40, sp50);
}
