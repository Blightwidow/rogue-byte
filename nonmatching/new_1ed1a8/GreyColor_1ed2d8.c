#include "m2c_macros.h"

M2C_UNK ConvertHsvToRgb__FP6VECTORT0(void *, s32, f32); /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
f32 PowF_245b58(f32 *, f32 *, M2C_UNK, f32, f32, f32); /* extern */
extern s32 B_003E12C8;
extern f32 D_FLT_002C3690;
extern f32 D_FLT_002C3694;
extern f32 D_FLT_002C3698;
extern M2C_UNK g_2bbb60;

void GreyColor_1ed2d8(s32 arg0) {
    char sp[0x400];
    f32 sp10;

    if (B_003E12C8 != 0) {
        sp10 = 0.3f;
        M2C_FIELD(&sp10, f32 *, 8) = 0.1f;
        M2C_FIELD(&sp10, f32 *, 4) = 0.6f;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
        ConvertHsvToRgb__FP6VECTORT0(sp, arg0, GLimitLm__FP2LMf(&g_2bbb60, PowF_245b58(&D_FLT_002C3694, &D_FLT_002C3690, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */), D_FLT_002C3698, D_FLT_002C3690, D_FLT_002C3694)));
    }
}
