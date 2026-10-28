#include "m2c_macros.h"

M2C_UNK ContinueAmb();                        /* extern */
s128 DecomposeRotateMatrixEuler();            /* extern */
M2C_UNK DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(); /* extern */
f32 GLimitLm__FP2LMf();               /* extern */
f32 GSmooth__FfffP3SMPPf(); /* extern */
M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(); /* extern */
M2C_UNK PauseAmb();                      /* extern */
s128 PosSmooth(); /* extern */
f32 RadSmooth__FfffP3SMPPf(); /* extern */
M2C_UNK SetAmbPitch();                   /* extern */
M2C_UNK SetAmbVolume();                  /* extern */
M2C_UNK SetCmFov();                   /* extern */
M2C_UNK SetCmLookAt(); /* extern */
M2C_UNK SetCmPosMat();             /* extern */
M2C_UNK SmoothMatrix(); /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();  /* extern */
M2C_UNK bevy_classes_k30_cam_150780();        /* extern */
M2C_UNK bevy_classes_k30_cam_1507f8();        /* extern */
extern M2C_UNK B_002DDF40;
extern f32 B_FLT_003E1BE0;
extern M2C_UNK D_002BBB68;
extern M2C_UNK D_002BD9B8;
extern M2C_UNK D_002BD9C8;
extern M2C_UNK D_002BD9D8;
extern M2C_UNK D_002BD9E8;
extern M2C_UNK D_002BD9F8;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2dded0;

void bevy_classes_k30_cam_update(void *arg0) {
    char sp[0x400];
    M2C_UNK sp70;
    M2C_UNK sp80;
    M2C_UNK spA0;
    M2C_UNK spB0;
    M2C_UNK unkspCC;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp90;
    s128 spC0;
    s32 spDC;
    s32 spEC;
    M2C_UNK spF0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f1;
    f32 var_f12;
    f32 var_f2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;
    void *temp_s0_2;

    UpdateCplcy();
    if (M2C_FIELD(&g_2dded0, f32 *, 4) != 0.0f) {
        temp_f13 = M2C_FIELD(arg0, f32 *, 0x18);
        if (temp_f13 >= 0.0f) {
            temp_f0 = GSmooth__FfffP3SMPPf(&D_002BD9B8, 0, M2C_FIELD(arg0, f32 *, 0xAC), temp_f13, M2C_FIELD(&g_2dded0, f32 *, 4));
            var_f2 = 0.0f;
            if (!(temp_f0 < 0.0f)) {
                var_f2 = temp_f0;
                if (temp_f0 > 1.0f) {
                    var_f2 = 1.0f;
                }
            }
            temp_f0_2 = var_f2 - M2C_FIELD(arg0, f32 *, 0xAC);
            M2C_FIELD(arg0, f32 *, 0xAC) = var_f2;
            M2C_FIELD(arg0, f32 *, 0xB0) = (f32) (temp_f0_2 / M2C_FIELD(&g_2dded0, f32 *, 4));
        }
        temp_f12 = M2C_FIELD(arg0, f32 *, 0xB0);
        if (temp_f12 == 0.0f) {
            temp_a0 = M2C_FIELD(arg0, void **, 0xC0);
            if (M2C_FIELD(temp_a0, s16 *, 0x4E) <= 0) {
                PauseAmb(temp_a0, temp_f12);
            }
        } else {
            temp_s0 = M2C_FIELD(arg0, void **, 0xC0);
            SetAmbPitch(temp_s0, GLimitLm__FP2LMf(&D_002BBB68, fabsf(temp_f12)));
            temp_s0_2 = M2C_FIELD(arg0, void **, 0xC0);
            SetAmbVolume(temp_s0_2, GLimitLm__FP2LMf(&g_2bbb60, (fabsf(M2C_FIELD(arg0, f32 *, 0xB0)) * 0.5f) + 0.5f));
            temp_a0_2 = M2C_FIELD(arg0, void **, 0xC0);
            if (M2C_FIELD(temp_a0_2, s16 *, 0x4E) > 0) {
                ContinueAmb(temp_a0_2);
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
            M2C_FIELD(arg0, s128 *, 0x50) = PosSmooth(M2C_FIELD(arg0, s128 *, 0x50), M2C_FIELD(arg0, s128 *, 0x80), &D_002BD9C8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp90, M2C_FIELD(arg0, s128 *, 0x60));
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp90, M2C_FIELD(arg0, s128 *, 0x90), sp90, sp90, spA0, spB0);
            sp50 = spB0;
            sp40 = spA0;
            sp30 = sp90;
            SmoothMatrix(sp, &sp30, &D_002BD9D8, &sp60, M2C_FIELD(&g_2dded0, f32 *, 4));
            M2C_FIELD(arg0, s128 *, 0x60) = DecomposeRotateMatrixEuler(&sp60);
            M2C_FIELD(arg0, f32 *, 0x70) = RadSmooth__FfffP3SMPPf(&D_002BD9E8, 0, M2C_FIELD(arg0, f32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xA0), M2C_FIELD(&g_2dded0, f32 *, 4));
            __as__6VECTORG9VU_VECTOR(&spF0, M2C_FIELD(arg0, s128 *, 0x50));
            spC0 = sp60;
            M2C_FIELD(&spC0, s128 *, 0x10) = sp70;
            M2C_FIELD(&spC0, s128 *, 0x20) = sp80;
            spEC = 0;
            spDC = 0;
            unkspCC = 0;
            M2C_FIELD(&spC0, f32 *, 0x3C) = 1.0f;
            SetCmPosMat(&B_002DDF40, &spC0);
            SetCmFov(&B_002DDF40, M2C_FIELD(arg0, f32 *, 0x70));
            DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&spC0, arg0 + 0xA4, arg0 + 0xA8);
            temp_f0_3 = M2C_FIELD(arg0, f32 *, 0xB8);
            temp_f1 = M2C_FIELD(arg0, f32 *, 0xBC);
            if (temp_f0_3 == temp_f1) {
                var_f12 = 0.0f;
            } else {
                var_f12 = (M2C_FIELD(arg0, f32 *, 0x70) - temp_f0_3) / (temp_f1 - temp_f0_3);
            }
            M2C_FIELD(arg0, f32 *, 0xAC) = GLimitLm__FP2LMf(&g_2bbb60, var_f12);
        } else {
            temp_f0_4 = 1.0f - M2C_FIELD(arg0, f32 *, 0xAC);
            SetCmFov(&B_002DDF40, ((1.0f - temp_f0_4) * M2C_FIELD(arg0, f32 *, 0xB8)) + (temp_f0_4 * M2C_FIELD(arg0, f32 *, 0xBC)));
            bevy_classes_k30_cam_1507f8(arg0);
            M2C_FIELD(arg0, s128 *, 0x30) = PosSmooth(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &D_002BD9F8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            bevy_classes_k30_cam_150780(arg0);
            M2C_FIELD(arg0, s128 *, 0x20) = PosSmooth(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &D_002BD9F8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            SetCmLookAt(&B_002DDF40, M2C_FIELD(arg0, s128 *, 0x30), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), 0, 0);
        }
        B_FLT_003E1BE0 = M2C_FIELD(&g_2dded0, f32 *, 0);
    }
}
