#include "m2c_macros.h"

M2C_UNK ConvertAloMat(s128 *, M2C_UNK, void *, s32); /* extern */
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s128 *); /* extern */
M2C_UNK ConvertXfPos(M2C_UNK, s32, s128);           /* extern */
M2C_UNK ConvertXfVec(M2C_UNK, s32, s128);           /* extern */
M2C_UNK DecomposeRotateMatrixEuler(s128 *, s128);   /* extern */
M2C_UNK DtSolveJumpLaunch(s128, s128, f32, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s128 *, s128, s128); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK PredictAsegEffect(s32, void *, s32, s32, f32, M2C_UNK); /* extern */
M2C_UNK SetAsegaSpeed(void *, f32);                 /* extern */
M2C_UNK SetSoNoXpsAll(void *, M2C_UNK);             /* extern */
f32 TFindAsegLabel__FP4ASEG3OID(s32, M2C_UNK);      /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, s128 *, M2C_UNK *); /* extern */
s32 func_0012DC18(void *, void *, M2C_UNK, M2C_UNK); /* extern */
s32 func_0012DE58(void *, void *, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_0012E460(s32);                         /* extern */
M2C_UNK func_001A58D0(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_001CCA40(void *, void *, s128, s128);    /* extern */
extern s128 D_002C1EE0;
extern f32 g_2c1ef0;
extern f32 g_2dded0;

void func_001CCC88(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp150;
    M2C_UNK sp160;
    M2C_UNK sp170;
    M2C_UNK sp1E0;
    M2C_UNK sp1F0;
    M2C_UNK unksp8C;
    M2C_UNK sp40;
    s128 sp80;
    f32 sp9C;
    f32 spAC;
    M2C_UNK spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 spF0;
    s128 sp100;
    s128 sp110;
    s128 sp120;
    s128 sp130;
    s128 sp140;
    M2C_UNK sp180;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK (*temp_a2_2)(void *, M2C_UNK, M2C_UNK);
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    s128 *var_v0;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    void *temp_a0;
    void *temp_a1;
    void *temp_a2;
    void *temp_s0_2;
    void *temp_s2;
    void *temp_s7;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;

    func_0012E460(arg0 + 0x94);
    func_0012E460(arg0 + 0x98);
    func_0012E460(arg0 + 0x9C);
    temp_s7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x1030);
    temp_s0 = M2C_FIELD(temp_s7, s32 *, 0x14);
    temp_f20 = TFindAsegLabel__FP4ASEG3OID(temp_s0, 0x1C7);
    temp_a2 = M2C_FIELD(arg0, void **, 0x34);
    temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
    temp_f22 = (temp_f20 - M2C_FIELD(temp_s7, f32 *, 0x1C)) / M2C_FIELD(temp_s7, f32 *, 0x40);
    temp_a1 = M2C_FIELD(arg0, void **, 0);
    PredictAsegEffect(temp_s0, temp_a1, M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK *, void *), 0x104)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x100), sp, temp_a2), M2C_FIELD(temp_a1, s32 *, 0x60), temp_f20, 0);
    temp_s0_2 = M2C_FIELD(arg0, void **, 0);
    temp_s2 = temp_s0_2 + 0x1B0;
    PosLoWorld(temp_s0_2);
    __as__6VECTORG9VU_VECTOR(&spB0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    sp80 = M2C_FIELD(temp_s0_2, s128 *, 0x1B0);
    M2C_FIELD(&sp80, s128 *, 0x10) = (s128) M2C_FIELD(temp_s2, s128 *, 0x10);
    M2C_FIELD(&sp80, s128 *, 0x20) = (s128) M2C_FIELD(temp_s2, s128 *, 0x20);
    unksp8C = 0.0f;
    spAC = 0.0f;
    sp9C = 0.0f;
    M2C_FIELD(&sp80, f32 *, 0x3C) = 1.0f;
    __ml__FRC7MATRIX4T0(&sp140, &sp80, &sp40);
    __ml__FRC7MATRIX4T0(&sp100, &sp140, sp);
    spC0 = sp100;
    spD0 = sp110;
    spE0 = sp120;
    spF0 = sp130;
    temp_v0 = func_001CCA40(M2C_FIELD(arg0, void **, 0), arg1, sp130, sp100);
    if (temp_v0 != NULL) {
        temp_v1_2 = M2C_FIELD(temp_v0, void **, 0xC);
        ConvertAloMat(&sp140, 0, arg1, M2C_FIELD(temp_v1_2, s32 (**)(void *, void *), 0xFC)(temp_v0 + M2C_FIELD(temp_v1_2, s16 *, 0xF8), temp_v0));
        sp110 = sp150;
        sp120 = sp160;
        sp130 = sp170;
        sp100 = sp140;
        InvertMatrix4Affine(&sp180, &sp100, sp150, sp140);
        __ml__FRC7MATRIX4T0(&sp140, &spC0, &sp180);
        spC0 = sp140;
        spD0 = sp150;
        spE0 = sp160;
        spF0 = sp170;
    }
    func_001A58D0(arg1, 0, 0xF);
    temp_v0_2 = M2C_FIELD(arg1, s32 *, 0xE8);
    var_v0 = temp_v0_2 + 0x80;
    if (temp_v0_2 == 0) {
        var_v0 = &D_002C1EE0;
    }
    sp1C0 = *var_v0;
    sp1D0 = spF0;
    PosLoWorld(arg1);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1d0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1e0($sp) */);
    DtSolveJumpLaunch(sp1E0, sp1C0, g_2c1ef0, -g_2c1ef0, 0x3F800000, 0xBF800000);
    temp_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f22, $f0 */);
    SetAsegaSpeed(temp_s7, temp_f22 / temp_f0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x1c0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x1e0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    temp_v0_3 = M2C_FIELD(arg1, void **, 0xC);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf4, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1e0($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf5, $vf1x */);
    temp_a2_2 = M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x11C);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x100($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1f0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x100($sp) */);
    temp_a2_2(arg1 + M2C_FIELD(temp_v0_3, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), temp_a2_2);
    temp_f20_2 = g_2dded0 + temp_f0;
    ConvertXfPos(0, M2C_FIELD(M2C_FIELD(arg1, void **, 0x58), s32 *, 0xA0), spF0);
    M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
    ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg1, void **, 0x58), s32 *, 0xA0), sp1F0);
    M2C_ERROR(/* unknown instruction: por $t0, $zero, $v0 */);
    M2C_FIELD(arg0, s32 *, 0x94) = func_0012DE58(arg1, M2C_FIELD(arg1, void **, 0x58), 5, M2C_ERROR(/* unknown instruction: por $a3, $zero, $s0 */), temp_f20_2);
    ConvertXfMat(&sp130, 0, M2C_FIELD(M2C_FIELD(arg1, void **, 0x5C), s32 *, 0xA0), &spC0);
    sp100 = sp130;
    sp120 = sp150;
    sp110 = sp140;
    DecomposeRotateMatrixEuler(&sp100, sp130);
    M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
    temp_v0_4 = func_0012DC18(arg1, M2C_FIELD(arg1, void **, 0x5C), 5, 9);
    M2C_FIELD(arg0, s32 *, 0x9C) = temp_v0_4;
    temp_a0 = M2C_FIELD(arg1, void **, 0x5C);
    if (M2C_FIELD(temp_a0, s32 *, 0x90) == temp_v0_4) {
        M2C_FIELD(temp_a0, f32 *, 0xA8) = temp_f20_2;
    }
    SetSoNoXpsAll(arg1, 1);
}
