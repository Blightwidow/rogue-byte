#include "m2c_macros.h"

M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, s128 *, s128); /* extern */
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, M2C_UNK, f32); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK MatMulMatTransMat(s128 *, void *, void *);  /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
M2C_UNK SetCmPosMat(M2C_UNK *, void *);             /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, M2C_UNK);  /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BDAB0;
extern M2C_UNK D_002BDAC0;
extern f32 g_2dded4;

void UpdateCpattach(void **arg0) {
    char sp[0x400];
    M2C_UNK spC0;
    M2C_UNK spD0;
    M2C_UNK unksp1C;
    M2C_UNK unksp2C;
    M2C_UNK unksp3C;
    M2C_UNK unkspC;
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    M2C_UNK spE0;
    f32 sp140;
    f32 temp_v0_2;
    void *temp_a1;
    void *temp_s1;
    void *temp_v0;
    void *temp_v1;

    UpdateCplcy();
    temp_s1 = *arg0;
    temp_a1 = M2C_FIELD(temp_s1, void **, 0x1D0);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, void *(**)(void *, void *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1);
    sp0 = M2C_FIELD(temp_v0, s128 *, 0);
    sp10 = M2C_FIELD(temp_v0, s128 *, 0x10);
    sp20 = M2C_FIELD(temp_v0, s128 *, 0x20);
    sp30 = M2C_FIELD(temp_v0, s128 *, 0x30);
    if ((M2C_FIELD(&B_002DDF40, s32 *, 0x300) == 0) && (M2C_FIELD(temp_s1, s32 *, 0x1D4) != 0)) {
        MatMulMatTransMat(&spB0, sp, &B_002DDF40 + 0x60);
        sp40 = spB0;
        sp50 = spC0;
        sp60 = spD0;
        DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp40, &sp140, &spA0, spB0);
        if (sp140 < 0.0001f) {
            sp70 = sp0;
            sp80 = sp10;
            sp90 = sp20;
        } else {
            LoadRotateMatrixRad(&spE0, spA0, GSmooth__FfffP3SMPPf(&D_002BDAB0, 0, sp140, 0, g_2dded4));
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xf0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x100($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf2, $vf5z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf6z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x110($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x120($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xc0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x130($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xd0($sp) */);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($v0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf1, $vf4 */);
        if (!(temp_v0_2 < 0.0001f)) {
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x150($sp) */);
            GSmooth__FfffP3SMPPf(&D_002BDAC0, 0, temp_v0_2, 0, g_2dded4);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x150($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf1x */);
        }
        __as__6VECTORG9VU_VECTOR(&sp30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
        sp0 = sp70;
        sp10 = sp80;
        sp20 = sp90;
        unksp3C = 1.0f;
        unksp2C = 0;
        unksp1C = 0;
        unkspC = 0;
    }
    SetCmPosMat(&B_002DDF40, sp);
    if (M2C_FIELD(&B_002DDF40, f32 *, 0x24) == M2C_FIELD(&B_002DDF40, f32 *, 0x20)) {
        SetCmFov(&B_002DDF40, M2C_FIELD(temp_s1, f32 *, 0x1BC));
        return;
    }
    M2C_FIELD(&B_002DDF40, f32 *, 0x24) = (f32) M2C_FIELD(temp_s1, f32 *, 0x1BC);
}
