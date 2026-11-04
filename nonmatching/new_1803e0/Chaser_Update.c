#include "m2c_macros.h"

M2C_UNK Chaser_SetState(void *, s32);               /* extern */
s32 ConvertXfVec(M2C_UNK, s32, M2C_UNK);            /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FCheckLm__FP2LMf(void *, f32);                  /* extern */
M2C_UNK FFindPathzoneCrv(s32, s128, s128, s32);     /* extern */
M2C_UNK FindCrvClosestPointFromS(s32, s128, M2C_UNK, void *, f32); /* extern */
f32 GetSuck(M2C_UNK *);                             /* extern */
s128 LimitVectorLength__FP6VECTORfT0(s128, f32);    /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
f32 SMaxCrv(s32);                                   /* extern */
M2C_UNK UpdateSo();                                 /* extern */
f32 atan2f(f32, s32);                               /* extern */
s32 bevy_camera_follow_track_heading_weight(M2C_UNK, void *, s128); /* extern */
s32 func_0017F550(void *);                          /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BE820;
extern f32 D_FLT_002BE824;
extern M2C_UNK D_FLT_002BE830;
extern M2C_UNK D_FLT_002BE840;
extern M2C_UNK D_FLT_002BE850;
extern M2C_UNK D_FLT_002BE860;
extern s128 g_2a2da0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;

void Chaser_Update(void *arg0) {
    char sp[0x400];
    M2C_UNK sp180;
    M2C_UNK sp20;
    M2C_UNK unksp24;
    M2C_UNK sp10;
    s128 sp30;
    s32 sp38;
    void *sp40;
    s128 sp150;
    s128 sp160;
    s128 sp170;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_v0_2;
    f32 temp_v1_5;
    f32 temp_v1_6;
    f32 var_f2;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f6;
    s32 temp_v0_5;
    s32 var_a0;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_v1;
    u32 temp_v1_2;
    void **var_s2_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_s2;

    UpdateSo();
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x1C0);
    if ((temp_v1 == 2) || (temp_v1 == 4)) {
        if (func_0017F550(arg0) != 0) {
            Chaser_SetState(arg0, 0);
        }
    }
    if ((M2C_FIELD(arg0, u32 *, 0x1C0) != 0) && (M2C_FIELD(arg0, u32 *, 0x1C0) != 4)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x1D4);
        if (temp_v0 != NULL) {
            if (!(((u64) M2C_FIELD(temp_v0, u64 *, 0x28) >> 0x3C) & 1)) {
                goto block_10;
            }
        } else {
block_10:
            Chaser_SetState(arg0, 0);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x1CC) == 0) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x1D4);
        if ((temp_a0 != NULL) && (((u64) M2C_FIELD(temp_a0, u64 *, 0x28) >> 0x3C) & 1)) {
            temp_s0 = arg0 + ((M2C_FIELD(arg0, u32 *, 0x1C0) * 0x28) + 0x270);
            PosLoWorld(temp_a0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($sp) */);
            PosLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
            temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            temp_f20 = RadNormalize__Ff(atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), bevy_camera_follow_track_heading_weight(0, arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */))));
            if (M2C_FIELD(temp_s0, s32 *, 0) == 0) {
                var_v0 = M2C_FIELD(temp_s0, s32 *, 4);
            } else {
                var_v0 = FCheckLm__FP2LMf(temp_s0 + 0x10, temp_v0_2);
            }
            var_s3 = 4;
            if (var_v0 != 0) {
                if ((M2C_FIELD(temp_s0, s32 *, 4) != 0) && (FCheckLm__FP2LMf(temp_s0 + 0x20, temp_f20) == 0)) {
                    var_s3 = 4;
                    goto block_21;
                }
            } else {
block_21:
                var_s2 = arg0 + 0x310;
loop_23:
                if (var_s3 > 0) {
                    if (M2C_FIELD(var_s2, s32 *, 0) == 0) {
                        var_v0_2 = M2C_FIELD(var_s2, s32 *, 4);
                    } else {
                        var_v0_2 = FCheckLm__FP2LMf(var_s2 + 8, temp_v0_2);
                    }
                    if (var_v0_2 == 0) {
                        var_s2 -= 0x28;
                        goto block_22;
                    }
                    if (M2C_FIELD(var_s2, s32 *, 4) != 0) {
                        if (FCheckLm__FP2LMf(var_s2 + 0x18, temp_f20) == 0) {
                            var_s2 -= 0x28;
block_22:
                            var_s3 -= 1;
                            goto loop_23;
                        }
                    }
                }
                Chaser_SetState(arg0, var_s3);
            }
        }
    }
    temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x1C0);
    switch (temp_v1_2) {
    case 1:
    case 2:
        if (M2C_FIELD(arg0, s32 *, 0x1C8) == 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0x5C);
            sp150 = PosLoWorld(M2C_FIELD(arg0, void **, 0x1D4));
            PosLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x150($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            temp_f0 = RadNormalize__Ff(atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */))));
            temp_v0_3 = arg0 + 0x360;
            temp_f4 = M2C_FIELD(arg0, f32 *, 0x370);
            var_f3 = M2C_FIELD(arg0, f32 *, 0x360) + (temp_f0 * (M2C_FIELD(temp_v0_3, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v0_3, f32 *, 8))));
            temp_f5 = M2C_FIELD(arg0, f32 *, 0x374);
            if (var_f3 < temp_f4) {
                var_f3 = temp_f4;
            } else if (temp_f5 < var_f3) {
                var_f3 = temp_f5;
            }
            M2C_FIELD(arg0, f32 *, 0x204) = var_f3;
        default:
        case 0:
        case 4:
        }
        break;
    case 3:
        sp160 = PosLoWorld(M2C_FIELD(arg0, void **, 0x1D4));
        sp170 = PosLoWorld(arg0);
        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x160($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1f0($s1) */);
        var_a0 = 0;
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if ((D_FLT_002BE820 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) || (M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x170($sp) */), M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1e0($s1) */), M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */), M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */), M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */), M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */), M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */), M2C_ERROR(/* unknown instruction: vwaitq */), M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */), (D_FLT_002BE820 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */))) || (D_FLT_002BE824 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x200)))) {
            var_a0 = 1;
        }
        if (var_a0 != 0) {
            FFindPathzoneCrv(M2C_FIELD(arg0, s32 *, 0x1D0), sp170, sp160, M2C_FIELD(arg0, s32 *, 0x1D8));
            M2C_FIELD(arg0, f32 *, 0x1DC) = 0.0f;
            M2C_FIELD(arg0, s128 *, 0x1F0) = sp160;
            M2C_FIELD(arg0, s128 *, 0x1E0) = sp170;
            M2C_FIELD(arg0, f32 *, 0x200) = (f32) g_2dded0;
        }
        FindCrvClosestPointFromS(M2C_FIELD(arg0, s32 *, 0x1D8), sp170, 0, sp, M2C_FIELD(arg0, f32 *, 0x1DC));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf3x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x170($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        } else {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf4, $q */);
        }
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        temp_f20_2 = SMaxCrv(M2C_FIELD(arg0, s32 *, 0x1D8)) - M2C_FIELD(arg0, f32 *, 0x1DC);
        temp_f21 = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), bevy_camera_follow_track_heading_weight(0, arg0, sp20));
        temp_v1_4 = arg0 + 0x340;
        temp_f7 = GetSuck(&B_002DE578);
        temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x340) + (temp_f20_2 * (M2C_FIELD(temp_v1_4, f32 *, 4) + (temp_f20_2 * M2C_FIELD(temp_v1_4, f32 *, 8))));
        if (temp_f0_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f6 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f6 = temp_f0_2;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_2) {
                var_f6 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_v0_4 = arg0 + 0x350;
        var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        temp_f0_3 = M2C_FIELD(arg0, f32 *, 0x350) + (temp_f21 * (M2C_FIELD(temp_v0_4, f32 *, 4) + (temp_f21 * M2C_FIELD(temp_v0_4, f32 *, 8))));
        if (!(temp_f0_3 < var_f3_2)) {
            var_f3_2 = temp_f0_3;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_3) {
                var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        temp_f0_4 = M2C_FIELD(&D_FLT_002BE830, f32 *, 0) + (temp_f7 * (M2C_FIELD(&D_FLT_002BE830, f32 *, 4) + (temp_f7 * M2C_FIELD(&D_FLT_002BE830, f32 *, 8))));
        if (temp_f0_4 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
            var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
        } else {
            var_f2 = temp_f0_4;
            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f0_4) {
                var_f2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
            }
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        temp_f20_3 = var_f6 * var_f3_2 * var_f2 * M2C_FIELD(arg0, f32 *, 0x338);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x180($sp) */);
        temp_v0_5 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x49, 0);
        if (temp_v0_5 > 0) {
            var_s2_2 = &sp40;
            var_s0 = temp_v0_5;
            do {
                temp_a0_2 = *var_s2_2;
                if ((temp_a0_2 != arg0) && (M2C_FIELD(temp_a0_2, s32 *, 0xEC) != M2C_FIELD(arg0, s32 *, 0xEC))) {
                    PosLoWorld(temp_a0_2);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x170($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
                    sp38 = 0;
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0001f) {
                        sp30 = g_2a2da0;
                    } else {
                        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
                    }
                    temp_v1_5 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
                    temp_f0_5 = M2C_FIELD(&D_FLT_002BE840, f32 *, 0) + (temp_v1_5 * (M2C_FIELD(&D_FLT_002BE840, f32 *, 4) + (temp_v1_5 * M2C_FIELD(&D_FLT_002BE840, f32 *, 8))));
                    if (temp_f0_5 < M2C_FIELD(&D_FLT_002BE850, f32 *, 0)) {

                    } else if (M2C_FIELD(&D_FLT_002BE850, f32 *, 4) < temp_f0_5) {

                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                    temp_v1_6 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
                    temp_f3 = M2C_FIELD(&D_FLT_002BE860, f32 *, 0) + (temp_v1_6 * (M2C_FIELD(&D_FLT_002BE860, f32 *, 4) + (temp_v1_6 * M2C_FIELD(&D_FLT_002BE860, f32 *, 8))));
                    if (temp_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {

                    } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3) {

                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x180($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x140($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x180($sp) */);
                }
                var_s0 -= 1;
                var_s2_2 += 4;
            } while (var_s0 != 0);
        }
        M2C_FIELD(arg0, s128 *, 0x210) = LimitVectorLength__FP6VECTORfT0(sp180, temp_f20_3);
        M2C_FIELD(arg0, f32 *, 0x204) = atan2f(unksp24, (s32) sp20);
        break;
    }
}
