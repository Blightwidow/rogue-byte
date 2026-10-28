#include "m2c_macros.h"

M2C_UNK DecomposeCylind(s128, void *, void *, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 GetJmpLaunchVelocity(void *, u32);             /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK SetJmpBodyState(void *, M2C_UNK, s32);      /* extern */
M2C_UNK SetStepGravityRatio__FP4STEPf(void *, f32); /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(void *, f32, f32, M2C_UNK); /* extern */
M2C_UNK func_00140C88(void *, s32);                 /* extern */
extern f32 D_FLT_002BF730;
extern f32 D_FLT_002BF750;
extern f32 D_FLT_002BF754;
extern f32 D_FLT_002BF758;
extern M2C_UNK32 D_FLT_002BF75C;
extern f32 D_FLT_002BF760;
extern M2C_UNK32 D_FLT_002BF764;
extern f32 D_FLT_002BF768;
extern M2C_UNK32 D_FLT_002BF76C;
extern f32 g_2dded0;

void SetJmpState(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s128 sp0;
    M2C_UNK var_a1;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_a2_4;
    void *temp_a2_5;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;

    if (arg1 != 6) {
        M2C_FIELD(arg0, u32 *, 4) = arg1;
    }
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    temp_a2 = M2C_FIELD(arg0, void **, 0);
    temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 1, temp_a2);
    if (arg1 != 6) {
        M2C_FIELD(arg0, s32 *, 0x40) = 0;
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2dded0;
        M2C_FIELD(arg0, f32 *, 0x4C) = (f32) g_2dded0;
        M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
    }
    if (arg1 == 9) {
        temp_a0 = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(arg0, f32 *, 0x168) = (f32) M2C_FIELD(temp_a0, f32 *, 0x260);
        SetStepGravityRatio__FP4STEPf(temp_a0, D_FLT_002BF750);
    }
    sp0 = GetJmpLaunchVelocity(arg0, arg1);
    temp_a2_2 = M2C_FIELD(arg0, void **, 0);
    temp_v0_2 = M2C_FIELD(temp_a2_2, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(temp_a2_2 + M2C_FIELD(temp_v0_2, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), temp_a2_2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0x131C) = (f32) g_2dded0;
    if (arg1 != 6) {
        M2C_FIELD(arg0, f32 *, 0x18) = (f32) g_2dded0;
    }
    switch (arg1) {
    case 0:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
block_32:
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        break;
    case 11:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 3:
        temp_a0_2 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(M2C_FIELD(temp_a0_2, void **, 0x150), f32 *, 0x1C) < 0.2f) {
            M2C_FIELD(arg0, s32 *, 0x40) = 3;
            SetVectorCylind__FP6VECTORfff(temp_a0_2, M2C_FIELD(temp_a0_2, f32 *, 0x1A8), D_FLT_002BF754, 0);
            temp_a2_3 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            temp_v0_3 = M2C_FIELD(temp_a2_3, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(temp_a2_3 + M2C_FIELD(temp_v0_3, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), temp_a2_3);
        }
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x38) = 0.6f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        break;
    case 1:
    case 2:
    case 18:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        goto block_32;
    case 9:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        func_00140C88(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, s32 *, 0x16C));
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF758;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF75C;
        M2C_FIELD(arg0, s32 *, 0x174) = 1;
        break;
    case 7:
        SetJmpBodyState(arg0, 7, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        break;
    case 8:
        SetJmpBodyState(arg0, 5, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        DecomposeCylind(sp0, arg0 + 0xB0, arg0 + 0xB8, 0);
        M2C_FIELD(arg0, f32 *, 0xB4) = 1.0f;
        break;
    case 6:
        temp_v1 = M2C_FIELD(arg0, u32 *, 4);
        var_a1 = 2;
        if ((s32) temp_v1 < 0xF) {
            var_a1 = ((s32) temp_v1 >= 0xD) ? 3 : 2;
        }
        SetJmpBodyState(arg0, var_a1, arg3);
        break;
    case 14:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF764;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF760;
        temp_a0_3 = M2C_FIELD(arg0, void **, 0);
        if (M2C_FIELD(M2C_FIELD(temp_a0_3, void **, 0x150), f32 *, 0x1C) < 0.2f) {
            M2C_FIELD(arg0, s32 *, 0x40) = 3;
            SetVectorCylind__FP6VECTORfff(temp_a0_3, M2C_FIELD(M2C_FIELD(temp_a0_3, void **, 0x150), f32 *, 0x18), D_FLT_002BF730 * D_FLT_002BF760, 0);
            temp_a2_4 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($sp) */);
            temp_v0_4 = M2C_FIELD(temp_a2_4, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf4, $vf1 */);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(temp_a2_4 + M2C_FIELD(temp_v0_4, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */), temp_a2_4);
        }
        break;
    case 13:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF768;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF76C;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        break;
    case 10:
        M2C_FIELD(arg0, s32 *, 0x40) = -1;
        SetJmpBodyState(arg0, 0x15, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 0.0f;
        break;
    case 12:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x40) = 3;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        goto block_32;
    case 16:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 15:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 17:
        if (M2C_FIELD(arg0, s32 *, 0x1C) == -1) {
            temp_a2_5 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            temp_v0_5 = M2C_FIELD(temp_a2_5, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf4, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(temp_a2_5 + M2C_FIELD(temp_v0_5, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), temp_a2_5);
            M2C_FIELD(arg0, s32 *, 0x28) = 1;
        }
        SetJmpBodyState(arg0, 0x16, 0);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
        goto block_32;
    }
    if (arg1 != 6) {
        if (arg1 != 0x11) {
            M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
        }
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0), 0x35) != 0) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x18F0) = -1;
        }
        PosLoWorld(M2C_FIELD(arg0, void **, 0));
        M2C_FIELD(arg0, f32 *, 0x3C) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
    }
}
