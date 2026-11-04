#include "m2c_macros.h"

M2C_UNK ActivateCplcy();                            /* extern */
M2C_UNK DecomposeSphere(M2C_UNK, void *, void *, void *); /* extern */
s32 FIsBasicDerivedFrom(s32, s32);                  /* extern */
s32 FIsCidDerivedFrom(s32, s32);                    /* extern */
M2C_UNK FindCrvClosestPointAll(s32, s128, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK GetCmCpdefi__FP2CMP2SOfP6CPDEFI(M2C_UNK *, s32, void *); /* extern */
M2C_UNK GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(s32 *, void *, s128 *, void *); /* extern */
M2C_UNK SetResetFlag__FP2CM(void *);                /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(f32, f32, f32); /* extern */
M2C_UNK UpdateCptnClosestPoint(void *, void *);     /* extern */
M2C_UNK UpdateStepXfWorld__FP4STEP(s32 *);          /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DE220;
extern s32 D_002C4120;
extern f32 D_FLT_002C41DC;
extern f32 g_2dded0;

void ActivateCptn__FP4CPTNPv(void *arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    s128 sp50;
    M2C_UNK sp60;
    void *sp80;
    f32 temp_f0;
    f32 temp_f1;
    s32 *temp_s0;
    s32 *var_s2;
    s32 temp_a0;
    s32 var_s3;
    s32 var_s4;
    void *temp_s0_2;
    void *temp_t2;
    void *temp_v0;
    void *temp_v1;
    void *var_fp;
    void *var_s7;

    ActivateCplcy();
    M2C_FIELD(arg0, void **, 0x10) = arg2;
    if (arg2 == NULL) {
        var_fp = arg0 + 0x1C;
        M2C_FIELD(arg0, s32 **, 0x14) = &D_002C4120;
        var_s7 = arg0 + 0x20;
        sp80 = arg0 + 0x18;
    } else {
        var_s3 = 1;
        var_s2 = M2C_FIELD(arg2, s32 **, 0x114);
        sp80 = arg0 + 0x18;
        var_fp = arg0 + 0x1C;
        var_s7 = arg0 + 0x20;
        if (M2C_FIELD(arg2, s32 *, 0x110) > 1) {
            var_s4 = 0x90;
            do {
                temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x114) + var_s4;
                if (FIsBasicDerivedFrom(arg1, *temp_s0) != 0) {
                    var_s2 = (FIsCidDerivedFrom(*temp_s0, *var_s2) != 0) ? temp_s0 : var_s2;
                }
                var_s3 += 1;
                var_s4 += 0x90;
            } while (var_s3 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x110));
        }
        M2C_FIELD(arg0, s32 **, 0x14) = var_s2;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = 1;
    UpdateStepXfWorld__FP4STEP(M2C_FIELD(arg0, s32 **, 0x14));
    GetCmCpdefi__FP2CMP2SOfP6CPDEFI(&B_002DDF40, arg1, sp);
    GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(M2C_FIELD(arg0, s32 **, 0x14), sp, &sp50, NULL);
    temp_t2 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_t2 != NULL) {
        temp_a0 = M2C_FIELD(temp_t2, s32 *, 0x10C);
        if (temp_a0 != 0) {
            FindCrvClosestPointAll(temp_a0, sp50, 0, &sp60);
        } else if (M2C_FIELD(temp_t2, s32 *, 0x12C) != 0) {
            UpdateCptnClosestPoint(arg0, sp);
        }
        GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(M2C_FIELD(arg0, s32 **, 0x14), sp, &sp50, M2C_FIELD(arg0, void **, 0x10));
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    temp_s0_2 = &B_002DE220 - 0x2E0;
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, -0x250($v0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf3 */);
    DecomposeSphere(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), sp80, var_fp, var_s7);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x20) - M2C_FIELD(temp_s0_2, f32 *, 0x4C);
    M2C_FIELD(arg0, f32 *, 0x20) = temp_f0;
    SetVectorSphere__FP6VECTORfff(M2C_FIELD(arg0, f32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x1C), temp_f0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    temp_v1 = M2C_FIELD(arg0, void **, 0x10);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($s1) */);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x14), f32 *, 0x5C);
    if (temp_v1 != NULL) {
        if (M2C_FIELD(temp_v1, s32 *, 0x184) != 0) {
            SetResetFlag__FP2CM(temp_s0_2);
        }
    }
    M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) g_2dded0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, f32 *, 0x48) = (f32) (g_2dded0 - D_FLT_002C41DC);
    if (temp_v0 != NULL) {
        temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x188);
        if (temp_f1 != 0.0f) {
            M2C_FIELD(&B_002DDF40, f32 *, 0x24) = temp_f1;
        }
    }
}
