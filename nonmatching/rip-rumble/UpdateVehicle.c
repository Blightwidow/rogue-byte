#include "m2c_macros.h"

M2C_UNK ContinueAmb();                        /* extern */
s32 ConvertXfVec();            /* extern */
s32 FFloatsNear__Ffff();           /* extern */
s32 FVehicleGunHasAmmo();                     /* extern */
f32 GLimitLm__FP2LMf();                  /* extern */
f32 GSmooth__FfffP3SMPPf(); /* extern */
s128 PosLoWorld();                      /* extern */
f32 RadNormalize__Ff();                          /* extern */
f32 RadSmooth__FfffP3SMPPf(); /* extern */
M2C_UNK SetAmbPitch();                   /* extern */
M2C_UNK SetAmbVolume();                  /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID();       /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(); /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK UpdateVehicleAi();                    /* extern */
f32 atan2f();                      /* extern */
M2C_UNK func_0012D108();          /* extern */
M2C_UNK func_001D2150();                      /* extern */
M2C_UNK func_001F5078();                      /* extern */
extern M2C_UNK D_002C2098;
extern M2C_UNK D_002C20A8;
extern M2C_UNK D_FLT_002C2040;
extern M2C_UNK D_FLT_002C2050;
extern M2C_UNK D_FLT_002C2060;
extern M2C_UNK D_FLT_002C2070;
extern M2C_UNK D_FLT_002C2080;
extern M2C_UNK D_FLT_002C2090;
extern f32 D_FLT_002C20A4;
extern M2C_UNK g_2dded0;
extern f32 g_2dded4;

void UpdateVehicle(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f2;
    f32 temp_v0_2;
    f32 temp_v1_4;
    f32 var_f13;
    f32 var_f20;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f4;
    s32 temp_a0_2;
    s32 temp_v1;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_v0;
    void **var_s2;
    void *temp_a0;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s0;
    void *var_s0_2;
    void *var_s2_2;

    var_s3 = 0;
    UpdateSo();
    temp_v0 = M2C_FIELD(arg0, void **, 0x60);
    M2C_FIELD(arg0, f32 *, 0x540) = atan2f(M2C_FIELD(temp_v0, s32 *, 0x44), M2C_FIELD(temp_v0, s32 *, 0x40));
    if (M2C_FIELD(arg0, s32 *, 0x4F8) > 0) {
        var_s2 = arg0 + 0x4FC;
        do {
            temp_s0 = *var_s2;
            if (FVehicleGunHasAmmo(temp_s0) == 0) {
                SetSmaGoal__FP3SMA3OID(M2C_FIELD(temp_s0, s32 *, 0x20), 0x65);
            }
            var_s3 += 1;
            var_s2 += 4;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x4F8));
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x180);
    switch (temp_v1) {                              /* irregular */
    case 3:
    case 0:
        M2C_FIELD(arg0, f32 *, 0x550) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x544) = (f32) M2C_FIELD(arg0, f32 *, 0x540);
        M2C_FIELD(arg0, f32 *, 0x554) = 0.0f;
        break;
    case 2:
        func_001D2150(arg0);
        break;
    case 1:
        UpdateVehicleAi(arg0);
        break;
    }
    temp_f0 = RadNormalize__Ff(M2C_FIELD(arg0, f32 *, 0x544) - M2C_FIELD(arg0, f32 *, 0x540));
    var_f3 = M2C_FIELD(&D_FLT_002C2040, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C2040, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C2040, f32 *, 8))));
    if (var_f3 < M2C_FIELD(&D_FLT_002C2050, f32 *, 0)) {
        var_f3 = M2C_FIELD(&D_FLT_002C2050, f32 *, 0);
    } else if (M2C_FIELD(&D_FLT_002C2050, f32 *, 4) < var_f3) {
        var_f3 = M2C_FIELD(&D_FLT_002C2050, f32 *, 4);
    }
    M2C_FIELD(arg0, f32 *, 0x548) = var_f3;
    temp_f0_2 = fabsf(RadNormalize__Ff(M2C_FIELD(arg0, f32 *, 0x544) - M2C_FIELD(arg0, f32 *, 0x540)));
    var_f3_2 = M2C_FIELD(&D_FLT_002C2060, f32 *, 0) + (temp_f0_2 * (M2C_FIELD(&D_FLT_002C2060, f32 *, 4) + (temp_f0_2 * M2C_FIELD(&D_FLT_002C2060, f32 *, 8))));
    if (var_f3_2 < M2C_FIELD(&D_FLT_002C2070, f32 *, 0)) {
        var_f3_2 = M2C_FIELD(&D_FLT_002C2070, f32 *, 0);
    } else if (M2C_FIELD(&D_FLT_002C2070, f32 *, 4) < var_f3_2) {
        var_f3_2 = M2C_FIELD(&D_FLT_002C2070, f32 *, 4);
    }
    M2C_FIELD(arg0, f32 *, 0x558) = var_f3_2;
    temp_f0_3 = fabsf(RadNormalize__Ff(M2C_FIELD(arg0, f32 *, 0x544) - M2C_FIELD(arg0, f32 *, 0x540)));
    var_f4 = M2C_FIELD(&D_FLT_002C2090, f32 *, 0);
    temp_f0_4 = M2C_FIELD(&D_FLT_002C2080, f32 *, 0) + (temp_f0_3 * (M2C_FIELD(&D_FLT_002C2080, f32 *, 4) + (temp_f0_3 * M2C_FIELD(&D_FLT_002C2080, f32 *, 8))));
    if (!(temp_f0_4 < var_f4)) {
        var_f4 = temp_f0_4;
        if (M2C_FIELD(&D_FLT_002C2090, f32 *, 4) < temp_f0_4) {
            var_f4 = M2C_FIELD(&D_FLT_002C2090, f32 *, 4);
        }
    }
    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, f32 *, 0x554) = (f32) ((var_f4 * M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f1 */) * M2C_FIELD(arg0, f32 *, 0x548)) / M2C_FIELD(arg0, f32 *, 0x4A0));
    if (M2C_FIELD(M2C_FIELD(temp_v1_2, void *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0xF8)), f32 *, 0x28) > 0.5f) {
        M2C_FIELD(arg0, f32 *, 0x5C0) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
    }
    var_s3_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x4A4) > 0) {
        var_s2_2 = arg0 + 0x4B4;
        var_s0 = arg0 + 0x4A8;
        do {
            var_s3_2 += 1;
            SetVectorCylind__FP6VECTORfff(M2C_FIELD(arg0, f32 *, 0x54C), 0x3F800000, 0);
            temp_f0_5 = GLimitLm__FP2LMf(var_s2_2, atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), ConvertXfVec(0, M2C_FIELD(M2C_FIELD(var_s0, void **, 4), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */))));
            var_s2_2 += 0x14;
            M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
            func_0012D108(M2C_FIELD(var_s0, s32 *, 8), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v1 */), M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */));
            var_s0 += 0x14;
        } while (var_s3_2 < M2C_FIELD(arg0, s32 *, 0x4A4));
    }
    var_s2_3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x190) > 0) {
        var_s0_2 = arg0 + 0x1A0;
        do {
            if (M2C_FIELD(arg0, f32 *, 0x550) != 0.0f) {
                var_f13 = M2C_FIELD(var_s0_2, f32 *, 0xC) * M2C_FIELD(arg0, f32 *, 0x548);
            } else {
                var_f13 = 0.0f;
            }
            var_s2_3 += 1;
            M2C_FIELD(var_s0_2, f32 *, 0x14) = RadSmooth__FfffP3SMPPf(&D_002C2098, 0, M2C_FIELD(var_s0_2, f32 *, 0x14), var_f13, M2C_FIELD(&g_2dded0, f32 *, 4));
            var_s0_2 += 0x60;
        } while (var_s2_3 < M2C_FIELD(arg0, s32 *, 0x190));
    }
    var_s3_3 = 0;
    temp_a1 = M2C_FIELD(arg0, void **, 0x5A4);
    temp_v1_3 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, void *, s128), 0x10C)(temp_a1 + M2C_FIELD(temp_v1_3, s16 *, 0x108), temp_a1, PosLoWorld(M2C_FIELD(arg0, void **, 0x5A4), PosLoWorld(arg0)));
    M2C_ERROR(/* unknown instruction: por $v1, $zero, $v0 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    if (M2C_FIELD(arg0, s32 *, 0x4F8) > 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        var_v0 = 0 * 4;
        do {
            temp_s0_2 = M2C_FIELD((arg0 + var_v0), void **, 0x4FC);
            if (M2C_FIELD(temp_s0_2, s32 *, 0x30) != 0) {
                if ((M2C_FIELD(arg0, f32 *, 0x550) != 0.0f) || (temp_v0_3 = temp_s0_2 + 0x50, (FVehicleGunHasAmmo(temp_s0_2) == 0))) {
                    M2C_FIELD(temp_s0_2, s32 *, 0xA0) = 0;
                    M2C_FIELD(temp_s0_2, f32 *, 0x78) = (f32) M2C_FIELD(temp_s0_2, f32 *, 0x48);
                    M2C_FIELD(temp_s0_2, f32 *, 0x74) = 0.0f;
                } else {
                    temp_f2 = M2C_FIELD(temp_s0_2, f32 *, 0x50) + (temp_v0_2 * (M2C_FIELD(temp_v0_3, f32 *, 4) + (temp_v0_2 * M2C_FIELD(temp_v0_3, f32 *, 8))));
                    if (temp_f2 < M2C_FIELD(temp_s0_2, f32 *, 0x60)) {

                    } else if (M2C_FIELD(temp_s0_2, f32 *, 0x64) < temp_f2) {

                    }
                    temp_a0 = M2C_FIELD(temp_s0_2, void **, 0x3C);
                    if (temp_a0 == NULL) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                    } else {
                        PosLoWorld(temp_a0);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    }
                    var_s2_4 = 0;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s4) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf3, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf1 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf5, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf4x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf3, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf3, $vf3, $vf3y */);
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf3, $vf0, $q */);
                    temp_a0_2 = M2C_ERROR(/* unknown instruction: pextuw $a0, $zero, $a0 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
                    temp_f0_6 = atan2f(temp_a0_2, temp_a0_2, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    temp_v1_4 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                    M2C_FIELD(temp_s0_2, f32 *, 0x74) = GLimitLm__FP2LMf(temp_s0_2 + 0x40, temp_f0_6);
                    M2C_FIELD(temp_s0_2, f32 *, 0x78) = GLimitLm__FP2LMf(temp_s0_2 + 0x48, temp_v1_4);
                    if (FFloatsNear__Ffff(M2C_FIELD(temp_s0_2, f32 *, 0x74), temp_f0_6, 0x3C23D70A) != 0) {
                        var_s2_4 = FFloatsNear__Ffff(M2C_FIELD(temp_s0_2, f32 *, 0x78), temp_v1_4, 0x3C23D70A) != 0;
                    }
                    M2C_FIELD(temp_s0_2, s32 *, 0xA0) = var_s2_4;
                    if (var_s2_4 == 0) {
                        M2C_FIELD(temp_s0_2, f32 *, 0x74) = 0.0f;
                        M2C_FIELD(temp_s0_2, f32 *, 0x78) = (f32) M2C_FIELD(temp_s0_2, f32 *, 0x48);
                    }
                }
                M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
                func_0012D108(M2C_FIELD(temp_s0_2, s32 *, 0x34), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */));
            }
            var_s3_3 += 1;
            var_v0 = var_s3_3 * 4;
        } while (var_s3_3 < M2C_FIELD(arg0, s32 *, 0x4F8));
    }
    if (M2C_FIELD(arg0, void **, 0x598) != NULL) {
        temp_f0_7 = GSmooth__FfffP3SMPPf(&D_002C20A8, 0, M2C_FIELD(arg0, f32 *, 0x5A0), M2C_FIELD(arg0, f32 *, 0x550) / D_FLT_002C20A4, g_2dded4);
        M2C_FIELD(arg0, f32 *, 0x5A0) = temp_f0_7;
        if (temp_f0_7 < 0.2f) {
            var_f20 = 0.2f;
        } else {
            var_f20 = temp_f0_7;
            if (temp_f0_7 > 1.0f) {
                var_f20 = 1.0f;
            }
        }
        SetAmbVolume(M2C_FIELD(arg0, void **, 0x598), var_f20);
        SetAmbPitch(M2C_FIELD(arg0, void **, 0x598), var_f20 * 0.2f);
        temp_a0_3 = M2C_FIELD(arg0, void **, 0x598);
        if (M2C_FIELD(temp_a0_3, s16 *, 0x4E) > 0) {
            ContinueAmb(temp_a0_3);
        }
    }
    if ((M2C_FIELD(arg0, f32 *, 0x550) != 0.0f) || (M2C_FIELD(arg0, f32 *, 0x554) != 0.0f)) {
        func_001F5078(arg0);
    }
}
