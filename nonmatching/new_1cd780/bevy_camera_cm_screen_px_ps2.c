#include "m2c_macros.h"

M2C_UNK CMovieText_Draw(void *, f32 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CMovieText_GetExtents(void *, f32 *, f32 *); /* extern */
M2C_UNK CTextBox_SetHorizontalJust(f32 *, M2C_UNK); /* extern */
M2C_UNK CTextBox_SetPos(f32 *, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK CTextBox_SetSize(f32 *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK CTextBox_SetTextColor(f32 *, s32 *);        /* extern */
M2C_UNK CTextBox_SetVerticalJust(f32 *, M2C_UNK);   /* extern */
M2C_UNK ConvertCmWorldToScreen(M2C_UNK *, M2C_UNK); /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK func_00215AC0(void *, s32, f32);            /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002C1F28;
extern s32 D_002C1F30;
extern s32 D_002C1F34;
extern f32 D_FLT_002C1F20;

void bevy_camera_cm_screen_px_ps2(f32 fparg0, s32 arg1, s32 arg2, void *arg3) {
    char sp[0x400];
    f32 spA0;
    f32 spA4;
    f32 spA8;
    f32 spAC;
    M2C_UNK spB0;
    s32 spC0;
    f32 spD0;
    f32 spD4;
    M2C_UNK temp_a3;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_v0;

    ConvertCmWorldToScreen(&B_002DDF40, M2C_ERROR(/* unknown instruction: por $a1, $zero, $a0 */));
    temp_v0 = M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */);
    if (!(temp_v0 < M2C_FIELD(&B_002DDF40, f32 *, 0x4C))) {
        func_00215AC0(sp, arg1, GLimitLm__FP2LMf(&D_002C1F28, fparg0 * (D_FLT_002C1F20 / (M2C_FIELD(&B_002DDF40, f32 *, 0x40) * temp_v0))));
        CTextBox_SetPos(&spA0, 0, 0);
        CTextBox_SetSize(&spA0, 0x44200000, 0x43F66667);
        spC0 = 0xFF808080;
        CTextBox_SetTextColor(&spA0, &spC0);
        CTextBox_SetHorizontalJust(&spA0, 0);
        CTextBox_SetVerticalJust(&spA0, 0);
        CMovieText_GetExtents(sp, &spD0, &spD4);
        temp_f7 = (f32) (D_002C1F34 * 2);
        temp_f5 = (f32) D_002C1F30;
        spA8 = spD0 + (f32) (D_002C1F30 * 2);
        spAC = spD4 + temp_f7;
        spA0 = (((((M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */) * 0.5f) + 0.5f) * 640.0f) - (spD0 * 0.5f)) - temp_f5) + temp_f5;
        spA4 = ((((0.5f - (M2C_ERROR(/* unknown instruction: prot3w $v1, $s1 */) * 0.5f)) * 492.80002f) - spD4) - temp_f7) + (f32) D_002C1F34;
        spC0 = M2C_UNALIGNED32(M2C_FIELD(arg3, M2C_UNK *, 0));
        temp_a3 = M2C_UNALIGNED32(spC0);
        spB0 = temp_a3;
        CMovieText_Draw(sp, &spA0, 6, temp_a3);
    }
}
