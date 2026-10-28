#include "m2c_macros.h"

M2C_UNK CMovieText_Draw(M2C_UNK *, void *, M2C_UNK, f32, f32, f32, f32); /* extern */
M2C_UNK CTextBox_SetHorizontalJust(void *, M2C_UNK); /* extern */
M2C_UNK CTextBox_SetPos(void *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CTextBox_SetSize(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CTextBox_SetTextColor(void *, s32 *);       /* extern */
M2C_UNK CTextBox_SetVerticalJust(void *, M2C_UNK);  /* extern */
s32 FDrawBlotMovie(s32);                            /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK func_00215AC0(M2C_UNK *, s32, f32);         /* extern */
extern M2C_UNK B_003DD490;
extern s32 D_002C3268;
extern f32 D_FLT_002C3264;

void GadgetMenu_DrawSlotLabels(void *arg0) {
    char sp[0x400];
    s32 sp20;
    M2C_UNK sp30;
    s32 *var_a0_2;
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    void *temp_s1;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x24);
    if ((temp_a0 != 0) && (FDrawBlotMovie(temp_a0) != 0)) {
        temp_v0 = PpoSwFocusBase(&B_003DD490);
        if ((temp_v0 != 0) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0)) {
            var_a0 = 0;
            if (M2C_FIELD(arg0, s32 *, 0x4C) > 0) {
                do {
                    var_a1 = 0;
                    temp_s1 = M2C_FIELD(arg0, s32 *, 0x50) + (var_a0 << 5);
                    var_s0 = &D_002C3268;
                    var_a0_2 = temp_v0 + 0x1180;
loop_7:
                    if (M2C_FIELD(temp_s1, s32 *, 0) != *var_a0_2) {
                        var_a1 += 1;
                        var_s0 += 4;
                        var_a0_2 += 0xC;
                        if (var_a1 < 3) {
                            goto loop_7;
                        }
                    } else {
                        CTextBox_SetPos(sp, var_a1, 0, 0);
                        CTextBox_SetSize(sp, 0x44200000, 0x43F66667);
                        sp20 = 0xFF808080;
                        CTextBox_SetTextColor(sp, &sp20);
                        CTextBox_SetHorizontalJust(sp, 0);
                        CTextBox_SetVerticalJust(sp, 0);
                        func_00215AC0(&sp30, *var_s0, D_FLT_002C3264);
                        CMovieText_Draw(&sp30, sp, 0x13, M2C_FIELD(temp_s1, f32 *, 0x14), M2C_FIELD(temp_s1, f32 *, 0x18), 32.0f, 32.0f);
                    }
                    var_a0 += 1;
                } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x4C));
            }
        }
    }
}
