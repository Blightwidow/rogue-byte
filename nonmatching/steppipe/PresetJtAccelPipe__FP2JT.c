#include "m2c_macros.h"

M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(); /* extern */
M2C_UNK EvaluateBezierMat(); /* extern */
M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(); /* extern */
M2C_UNK MatMulMatTransMat();     /* extern */
s32 PmatLoWorld();                 /* extern */
extern s128 g_2a2dd0;
extern M2C_UNK g_2dded0;

void PresetJtAccelPipe__FP2JT(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK spB0;
    M2C_UNK spC0;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    M2C_UNK sp90;
    s128 spA0;
    f32 spD0;
    f32 temp_f21;
    s32 temp_s1;
    s32 temp_v1;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v1_2;
    void *temp_v1_3;

    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x18) == 0, sp, M2C_FIELD(arg0, f32 *, 0x10));
    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_v1 == 0) || (temp_v1 == 4)) {
        temp_f21 = M2C_FIELD(&g_2dded0, f32 *, 4);
        temp_a1 = M2C_FIELD(arg0, void **, 0);
        temp_s1 = PmatLoWorld(M2C_FIELD(arg0, void **, 0), &g_2dded0);
        temp_v1_2 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, void *), 0x114)(temp_a1 + M2C_FIELD(temp_v1_2, s16 *, 0x110), temp_a1);
        EvaluateBezierMat(temp_s1, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), sp, g_2a2dd0, M2C_ERROR(/* unknown instruction: max.s $f20, $f21, $f20 */), temp_f21, 0x3F800000);
    } else {
        sp30 = sp0;
        sp40 = sp10;
        sp50 = sp20;
    }
    MatMulMatTransMat(&spA0, PmatLoWorld(M2C_FIELD(arg0, void **, 0)), &sp30);
    sp70 = spB0;
    sp80 = spC0;
    sp60 = spA0;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&sp60, &spD0, &sp90, spA0);
    temp_a1_2 = M2C_FIELD(arg0, void **, 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
    temp_v1_3 = M2C_FIELD(temp_a1_2, void **, 0xC);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xa0($sp) */);
    M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK), 0x124)(temp_a1_2 + M2C_FIELD(temp_v1_3, s16 *, 0x120), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
}
