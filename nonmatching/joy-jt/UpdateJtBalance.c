#include "m2c_macros.h"

M2C_UNK EvaluateCrvFromU(void *, s128 *, M2C_UNK *, f32); /* extern */
s32 FLookatInList(s32);                             /* extern */
f32 GModPositive__Fff(f32, f32);                    /* extern */
f32 GSmoothA__FffffP4SMPAPf(M2C_UNK *, void *, f32, f32, f32, f32); /* extern */
M2C_UNK GetPathPosFromS(void *, M2C_UNK, M2C_UNK *, f32); /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv(void *);                                /* extern */
f32 SProjectVector__FP6VECTORT0(M2C_UNK, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK SetActadjOffset(s32, s128);                 /* extern */
M2C_UNK VelocityXfAtPos(s32, M2C_UNK, s128);        /* extern */
s32 bevy_player_p15_binoc_active(void *);           /* extern */
extern M2C_UNK D_002BF320;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;
extern f32 g_2bf2d0;
extern f32 g_2bf2d4;
extern f32 g_2bf2d8;
extern f32 g_2bf2dc;
extern M2C_UNK g_2bf310;
extern M2C_UNK g_2bf330;
extern f32 g_2dded4;

void UpdateJtBalance(void *arg0) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp44;
    M2C_UNK sp60;
    s128 sp10;
    M2C_UNK sp20;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    s128 sp50;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f5;
    f32 temp_v0;
    f32 var_f1;
    f32 var_f20;
    f32 var_f5;
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    void *temp_s2;
    void *temp_v0_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *var_s3;

    var_s3 = NULL;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x19E4);
    if ((temp_a0 != 0) && (FLookatInList(temp_a0) != 0)) {
        if (bevy_player_p15_binoc_active(arg0) == 0) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x18C8);
            switch (temp_v1) {                      /* irregular */
            case 7:
                if (M2C_FIELD(arg0, s32 *, 0x4CC) == 0) {
                    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x4C8);
                    if (temp_v1_2 != 3) {
                        if (temp_v1_2 == 4) {
                            var_s3 = M2C_FIELD(arg0, void **, 0x4D4);
                            sp10 = PosLoWorld(var_s3);
                        }
                        goto block_33;
                    }
                    temp_s2 = M2C_FIELD(arg0, void **, 0x4D4);
                    var_s3 = temp_s2;
                    EvaluateCrvFromU(temp_s2, &sp10, &sp20, M2C_FIELD(arg0, f32 *, 0x4DC));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
                    if (M2C_FIELD(var_s3, s32 *, 0x1BC) != 0) {
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
                        M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x108));
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                        var_f20 = M2C_FIELD(arg0, f32 *, 0x4E0) + (M2C_ERROR(/* unknown instruction: qmfc2.ni $s0, $vf1 */) * g_2bf2d0);
                        temp_f21 = SMaxCrv(var_s3);
                        if (M2C_FIELD(var_s3, s32 *, 0xE4) != 0) {
                            var_f20 = GModPositive__Fff(var_f20, temp_f21);
                        } else {
                            temp_f0 = SMinCrv(var_s3);
                            if (var_f20 < temp_f0) {
                                var_f20 = temp_f0;
                            } else if (temp_f21 < var_f20) {
                                var_f20 = temp_f21;
                            }
                        }
                        GetPathPosFromS(temp_s2, 0, &sp20, var_f20);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf5, $q */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
                        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                        if (M2C_FIELD(arg0, s32 *, 0x7D4) != 0) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf5 */);
                            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf5, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
                            temp_f0_2 = SProjectVector__FP6VECTORT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), 0, sp) / g_2bf2d4;
                            var_f1 = -1.0f;
                            if (!(temp_f0_2 < -1.0f)) {
                                var_f1 = temp_f0_2;
                                if (temp_f0_2 > 1.0f) {
                                    var_f1 = 1.0f;
                                }
                            }
                            if (M2C_FIELD(arg0, s32 *, 0x4E4) != 0) {
                                var_f1 = -var_f1;
                            }
                            temp_f4 = M2C_ERROR(/* unknown instruction: max.s $f4, $f0, $f2 */);
                            M2C_FIELD(arg0, f32 *, 0x7D8) = GSmoothA__FffffP4SMPAPf(&D_002BF320, arg0 + 0x7DC, M2C_FIELD(arg0, f32 *, 0x7D8), M2C_FIELD(arg0, f32 *, 0x7DC), var_f1 * (2.0f - fabsf(var_f1)), g_2dded4);
                            temp_f1 = M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f2 */);
                            M2C_FIELD(arg0, f32 *, 0x7B0) = temp_f4;
                            M2C_FIELD(arg0, f32 *, 0x7C8) = temp_f1;
                            M2C_FIELD(arg0, f32 *, 0x7BC) = (f32) ((1.0f - temp_f4) - temp_f1);
                            ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0x7D4));
                        }
                        goto block_34;
                    }
                    goto block_33;
                }
            default:
block_33:
                if (var_s3 != NULL) {
block_34:
                    temp_v1_4 = M2C_FIELD(var_s3, void **, 0xC);
                    VelocityXfAtPos(M2C_FIELD(temp_v1_4, s32 (**)(void *, M2C_UNK), 0x104)(var_s3 + M2C_FIELD(temp_v1_4, s16 *, 0x100), 0), 0, sp10);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf7, $vf3, $vf4 */);
                    M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf8, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf1, $vf4 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf2, $vf4 */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf7, $vf7y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf8, $vf7z */);
                    M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf6, $vf6x */);
                    M2C_ERROR(/* unknown instruction: vmaddz.y $vf3, $vf8, $vf6z */);
                    M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf5, $vf5x */);
                    M2C_ERROR(/* unknown instruction: vmaddy.z $vf3, $vf8, $vf5y */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf3, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    if (temp_v0 > 0.0001f) {
                        var_f5 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                        temp_f0_3 = M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f3 */);
                        temp_f4_2 = M2C_FIELD(&g_2bf310, f32 *, 0) + (temp_f0_3 * (M2C_FIELD(&g_2bf310, f32 *, 4) + (temp_f0_3 * M2C_FIELD(&g_2bf310, f32 *, 8))));
                        if (!(temp_f4_2 < var_f5)) {
                            var_f5 = temp_f4_2;
                            if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f4_2) {
                                var_f5 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                            }
                        }
                        M2C_ERROR(/* unknown instruction: c1 0xc4 */);
                        sp30 = (sp40 * g_2bf2d8 * var_f5) / temp_v0;
                        sp34 = (sp44 * g_2bf2d8 * var_f5) / temp_v0;
                        sp38 = g_2bf2dc * g_2bf2d8;
                    } else {
                        sp38 = 0.0f;
                        sp34 = 0.0f;
                        sp30 = 0.0f;
                    }
                    temp_f4_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x19F0), f32 *, 0x28);
                    temp_f3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x19F4), f32 *, 0x28);
                    temp_f0_4 = M2C_FIELD(&g_2bf330, f32 *, 0) + (temp_f4_3 * (M2C_FIELD(&g_2bf330, f32 *, 4) + (temp_f4_3 * M2C_FIELD(&g_2bf330, f32 *, 8))));
                    temp_f5 = M2C_FIELD(&g_2bf330, f32 *, 0) + (temp_f3 * (M2C_FIELD(&g_2bf330, f32 *, 4) + (temp_f3 * M2C_FIELD(&g_2bf330, f32 *, 8))));
                    if ((sp38 < temp_f0_4) && (sp38 < temp_f5)) {

                    } else if (temp_f0_4 < temp_f5) {

                    }
                    M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
                    sp50 = M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
                    SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19E4), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
                    if (M2C_FIELD(arg0, s32 *, 0x18D8) == -1) {
                        SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19EC), sp60);
                        SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19E8), sp60);
                    } else {
                        SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19EC), g_2a2dd0);
                        SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19E8), g_2a2dd0);
                    }
                }
                break;
            case 0:
                temp_v0_2 = M2C_FIELD(arg0, void **, 0x208);
                if (temp_v0_2 != NULL) {
                    var_s3 = M2C_FIELD(temp_v0_2, void **, 0x4C);
                }
                goto block_33;
            }
        } else {
            SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19E4), g_2a2dd0);
            SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19E8), g_2a2dd0);
            SetActadjOffset(M2C_FIELD(arg0, s32 *, 0x19EC), g_2a2dd0);
        }
    }
}
