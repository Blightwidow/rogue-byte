#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK ContinueAmb(void *);                        /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, f32, f32, f32); /* extern */
M2C_UNK PauseAmb(void *, f32);                      /* extern */
M2C_UNK PosCplookAnchor(void *);                    /* extern */
M2C_UNK PosCplookEye(void *);                       /* extern */
f32 RadNormalize__Ff(M2C_UNK *, f32);               /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, M2C_UNK *); /* extern */
M2C_UNK SetAmbPitch(void *, f32);                   /* extern */
M2C_UNK SetAmbVolume(void *, f32);                  /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
M2C_UNK SetCmLookAt(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BBB68;
extern M2C_UNK D_002BD9A0;
extern M2C_UNK D_FLT_002BD980;
extern f32 D_FLT_002BD990;
extern f32 D_FLT_002BD994;
extern f32 D_FLT_002BD998;
extern f32 D_FLT_002BD99C;
extern M2C_UNK D_FLT_002BD9B0;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2dded0;

void UpdateCplook(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    f32 sp10;
    f32 sp14;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f12;
    f32 var_f20;
    f32 var_f5;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;
    void *temp_s0_2;

    UpdateCplcy();
    temp_f5 = M2C_FIELD(arg0, f32 *, 0x20);
    temp_f3 = M2C_FIELD(arg2, f32 *, 0x1074);
    temp_f0 = (M2C_FIELD(&D_FLT_002BD980, f32 *, 0) + (temp_f5 * (M2C_FIELD(&D_FLT_002BD980, f32 *, 4) + (temp_f5 * M2C_FIELD(&D_FLT_002BD980, f32 *, 8))))) * temp_f3 * fabsf(temp_f3);
    M2C_FIELD(arg0, f32 *, 0x24) = temp_f0;
    var_f5 = temp_f5 + (temp_f0 * M2C_FIELD(&g_2dded0, f32 *, 4));
    if (var_f5 < 0.0f) {
        var_f5 = 0.0f;
    } else if (var_f5 > 1.0f) {
        var_f5 = 1.0f;
    }
    temp_f12 = M2C_FIELD(arg0, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x20) = var_f5;
    if ((temp_f12 != 0.0f) && (var_f5 > 0.0f) && (var_f5 < 1.0f)) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x34);
        SetAmbPitch(temp_s0, GLimitLm__FP2LMf(&D_002BBB68, fabsf(temp_f12)));
        temp_s0_2 = M2C_FIELD(arg0, void **, 0x34);
        SetAmbVolume(temp_s0_2, GLimitLm__FP2LMf(&g_2bbb60, (fabsf(M2C_FIELD(arg0, f32 *, 0x24)) * 0.5f) + 0.5f));
        temp_a0 = M2C_FIELD(arg0, void **, 0x34);
        if (M2C_FIELD(temp_a0, s16 *, 0x4E) > 0) {
            ContinueAmb(temp_a0);
        }
    } else {
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x34);
        if (M2C_FIELD(temp_a0_2, s16 *, 0x4E) <= 0) {
            PauseAmb(temp_a0_2, temp_f12);
        }
    }
    temp_f0_2 = 1.0f - M2C_FIELD(arg0, f32 *, 0x20);
    SetCmFov(&B_002DDF40, ((1.0f - temp_f0_2) * M2C_FIELD(arg0, f32 *, 0x2C)) + (temp_f0_2 * M2C_FIELD(arg0, f32 *, 0x30)));
    temp_f3_2 = M2C_FIELD(arg2, f32 *, 0x1040);
    temp_f2 = M2C_FIELD(arg2, f32 *, 0x103C);
    var_f20 = -fabsf(temp_f3_2) * temp_f3_2 * D_FLT_002BD994;
    temp_f22 = -fabsf(temp_f2) * temp_f2 * D_FLT_002BD990;
    RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B4C), &B_003D4A60);
    CRef_Destruct(sp);
    if (sp4 != 0) {
        var_f20 = -var_f20;
    }
    temp_f22_2 = M2C_FIELD(arg0, f32 *, 0x18) + GLimitAbs__Fff(temp_f22 - M2C_FIELD(arg0, f32 *, 0x18), D_FLT_002BD998 * M2C_FIELD(&g_2dded0, f32 *, 4));
    temp_f21 = M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f;
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x1C) + GLimitAbs__Fff(var_f20 - M2C_FIELD(arg0, f32 *, 0x1C), D_FLT_002BD99C * M2C_FIELD(&g_2dded0, f32 *, 4));
    GSmooth__FfffP3SMPPf(&D_002BD9A0, &sp10, M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(arg0, f32 *, 0x3C), temp_f21);
    GSmooth__FfffP3SMPPf(&D_002BD9A0, &sp14, M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(arg0, f32 *, 0x40), temp_f21);
    var_f0 = sp10;
    if (!(temp_f22_2 < var_f0)) {
        var_f0 = temp_f22_2;
        if (sp14 < temp_f22_2) {
            var_f0 = sp14;
        }
    }
    M2C_FIELD(arg0, f32 *, 0x18) = var_f0;
    GSmooth__FfffP3SMPPf(&D_002BD9A0, &sp10, M2C_FIELD(arg0, f32 *, 0x14), M2C_FIELD(arg0, f32 *, 0x44), temp_f21);
    GSmooth__FfffP3SMPPf(&D_002BD9A0, &sp14, M2C_FIELD(arg0, f32 *, 0x14), M2C_FIELD(arg0, f32 *, 0x48), temp_f21);
    if (temp_f20 < sp10) {
        var_f12 = sp10;
    } else {
        var_f12 = temp_f20;
        if (sp14 < temp_f20) {
            var_f12 = sp14;
        }
    }
    M2C_FIELD(arg0, f32 *, 0x1C) = var_f12;
    temp_f1 = ((1.0f - M2C_FIELD(&B_002DDF40, f32 *, 0x20)) * M2C_FIELD(&D_FLT_002BD9B0, f32 *, 0)) + (M2C_FIELD(&B_002DDF40, f32 *, 0x20) * M2C_FIELD(&D_FLT_002BD9B0, f32 *, 4));
    temp_f12_2 = M2C_FIELD(arg0, f32 *, 0x10) + (temp_f1 * M2C_FIELD(arg0, f32 *, 0x18) * M2C_FIELD(&g_2dded0, f32 *, 4));
    M2C_FIELD(arg0, f32 *, 0x10) = temp_f12_2;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x14) + (temp_f1 * var_f12 * M2C_FIELD(&g_2dded0, f32 *, 4)));
    if ((M2C_FIELD(arg0, f32 *, 0x40) - M2C_FIELD(arg0, f32 *, 0x3C)) >= 6.2831855f) {
        M2C_FIELD(arg0, f32 *, 0x10) = RadNormalize__Ff(&g_2dded0, temp_f12_2);
    }
    PosCplookEye(arg0);
    M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
    PosCplookAnchor(arg0);
    SetCmLookAt(&B_002DDF40, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), 0, 0);
    M2C_FIELD(&B_003DD490, f32 *, 0x4750) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
}
