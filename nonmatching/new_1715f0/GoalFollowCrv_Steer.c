#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(s128, M2C_UNK, M2C_UNK, s128 *); /* extern */
M2C_UNK FindCrvClosestPointFromS(void *, M2C_UNK, M2C_UNK *, void *, f32); /* extern */
M2C_UNK GetPathPosFromS(void *, s128 *, s128 *, f32); /* extern */
s32 GoalFollowCrv_FAtEnd(void *, M2C_UNK *, f32);   /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 SMaxCrv(void *);                                /* extern */
f32 SWrapCrv(void *, f32);                          /* extern */
s32 func_001C0B50(void *, M2C_UNK, s128 *);         /* extern */
extern M2C_UNK B_003DD020;
extern f32 D_FLT_002BE634;
extern M2C_UNK D_FLT_002BE640;
extern M2C_UNK D_FLT_002BE650;
extern f32 D_FLT_002BE660;
extern f32 D_FLT_002BE668;
extern f32 D_FLT_002BE670;
extern M2C_UNK D_FLT_002BE680;
extern f32 D_FLT_002BE690;
extern s128 g_2a2da0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;

void GoalFollowCrv_Steer(void *arg0) {
    char sp[0x400];
    M2C_UNK spB0;
    M2C_UNK unksp48;
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp60;
    s128 sp90;
    void *spA0;
    f32 temp_a2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f4;
    f32 temp_v1_3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f20;
    f32 var_f3;
    f32 var_f3_2;
    s32 var_s4;
    u32 temp_a0;
    u32 temp_v1;
    void *temp_a0_2;
    void *temp_s0;
    void *temp_s3;
    void *temp_v0;
    void *temp_v1_2;
    void *var_s2;
    void *var_v1;

    sp90 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    var_v1 = NULL;
    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8);
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, void **, 0xDC);
    }
    spA0 = NULL;
    if (var_v1 != NULL) {
        spA0 = M2C_FIELD(var_v1, void **, 0x10);
    }
    var_s4 = M2C_FIELD(arg0, s32 *, 0x38);
    if (var_s4 != 0) {
        var_f12 = M2C_FIELD(arg0, f32 *, 0x34) - D_FLT_002BE634;
    } else {
        var_f12 = M2C_FIELD(arg0, f32 *, 0x34) + D_FLT_002BE634;
    }
    FindCrvClosestPointFromS(M2C_FIELD(arg0, void **, 0x30), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */), &B_003DD020, sp, SWrapCrv(M2C_FIELD(arg0, void **, 0x30), var_f12));
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x4C);
    if ((temp_v1 == 1) || (temp_v1 == 4)) {
        var_s4 = M2C_FIELD(arg0, s32 *, 0x58) != 2;
        if (var_s4 != 0) {
            var_f12_2 = M2C_FIELD(arg0, f32 *, 0x5C) - D_FLT_002BE634;
        } else {
            var_f12_2 = M2C_FIELD(arg0, f32 *, 0x5C) + D_FLT_002BE634;
        }
        FindCrvClosestPointFromS(M2C_FIELD(arg0, void **, 0x54), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */), &B_003DD020, sp, SWrapCrv(M2C_FIELD(arg0, void **, 0x54), var_f12_2));
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f)) {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_a2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */);
    M2C_FIELD(arg0, f32 *, 0x70) = temp_a2;
    var_f3 = M2C_FIELD(&D_FLT_002BE640, f32 *, 0) + (temp_a2 * (M2C_FIELD(&D_FLT_002BE640, f32 *, 4) + (temp_a2 * M2C_FIELD(&D_FLT_002BE640, f32 *, 8))));
    if (var_f3 < M2C_FIELD(&D_FLT_002BE650, f32 *, 0)) {
        var_f3 = M2C_FIELD(&D_FLT_002BE650, f32 *, 0);
    } else if (M2C_FIELD(&D_FLT_002BE650, f32 *, 4) < var_f3) {
        var_f3 = M2C_FIELD(&D_FLT_002BE650, f32 *, 4);
    }
    var_f20 = var_f3;
    if (var_s4 != 0) {
        var_f20 = -var_f20;
    }
    if (GoalFollowCrv_FAtEnd(arg0, &D_FLT_002BE640, temp_a2) != 0) {
        sp30 = g_2a2da0;
        sp20 = sp90;
    } else {
        temp_a0 = M2C_FIELD(arg0, u32 *, 0x4C);
        switch (temp_a0) {
        case 0:
        case 2:
        case 3:
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x30);
            if (temp_a0_2 != M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x294)) {
                if (M2C_FIELD(temp_a0_2, s32 *, 0xE4) == 0) {
                    temp_f21 = -M2C_FIELD(arg0, f32 *, 0x34);
                    temp_f0 = SMaxCrv(temp_a0_2) - M2C_FIELD(arg0, f32 *, 0x34);
                    if (var_f20 < temp_f21) {
                        var_f12_3 = temp_f21;
                    } else {
                        var_f12_3 = var_f20;
                        if (temp_f0 < var_f20) {
                            var_f12_3 = temp_f0;
                        }
                    }
                    if (var_f20 != var_f12_3) {

                    }
                    var_f0 = M2C_FIELD(arg0, f32 *, 0x34) + var_f12_3;
                } else {
                    var_f0 = SWrapCrv(temp_a0_2, M2C_FIELD(arg0, f32 *, 0x34) + var_f20);
                }
                GetPathPosFromS(M2C_FIELD(arg0, void **, 0x30), &sp20, &sp30, var_f0);
            } else {
                temp_f21_2 = -M2C_FIELD(arg0, f32 *, 0x34);
                temp_f1 = SMaxCrv(temp_a0_2) - M2C_FIELD(arg0, f32 *, 0x34);
                if (var_f20 < temp_f21_2) {
                    var_f0_2 = temp_f21_2;
                } else {
                    var_f0_2 = var_f20;
                    if (temp_f1 < var_f20) {
                        var_f0_2 = temp_f1;
                    }
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                if (var_f20 != var_f0_2) {

                }
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf3 */);
block_48:
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
            }
            break;
        case 1:
        case 4:
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            goto block_48;
        }
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    if (var_s4 != 0) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    if (M2C_FIELD(arg0, s32 *, 0xA0) != 0) {
        M2C_FIELD(arg0, s128 *, 0x90) = (s128) M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
        M2C_FIELD(arg0, s128 *, 0x80) = sp20;
        M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf8, $vf1, $vf4x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        var_s2 = M2C_FIELD(spA0, void **, 0x118);
        temp_s3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8), void **, 0xDC);
        if (var_s2 != NULL) {
            do {
                if ((M2C_FIELD(var_s2, f32 *, 8) != 0.0f) && (M2C_FIELD(var_s2, f32 *, 0xC) != 0.0f)) {
                    temp_s0 = M2C_FIELD(var_s2, void **, 0);
                    if (temp_s0 != M2C_FIELD(arg0, void **, 0x10)) {
                        M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0xf0($sp) */);
                        sp40 = PosLoWorld(temp_s0);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xf0($sp) */);
                        unksp48 += M2C_FIELD(var_s2, f32 *, 4);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
                        if (!(D_FLT_002BE660 < fabsf(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)))) {
                            temp_v1_2 = M2C_FIELD(temp_s0, void **, 0xC);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0xe0($sp) */);
                            M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(temp_s0 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s4) */);
                            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf6x */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0xe0($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($s1) */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf7, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf5, $vf1z */);
                            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf1x */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf7, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf4, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf5, $vf3z */);
                            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf3x */);
                            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf5, $vf7 */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf3 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xc0($sp) */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0xe0($sp) */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x60($sp) */);
                            ClosestPointOnSegment(g_2a2dd0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), &sp60);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xc0($sp) */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0xe0($sp) */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf8, 0xf0($sp) */);
                            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0001f) {
                                sp60 = g_2a2da0;
                            } else {
                                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                                M2C_ERROR(/* unknown instruction: vwaitq */);
                                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
                            }
                            M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */);
                            temp_f4 = M2C_ERROR(/* unknown instruction: max.s $f4, $f20, $f1 */);
                            if (temp_f4 < D_FLT_002BE668) {
                                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
                                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf8 */);
                                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf8, $vf2, $vf1x */);
                            }
                            if (temp_f4 < D_FLT_002BE670) {
                                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
                                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                M2C_ERROR(/* unknown instruction: vwaitq */);
                                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
                                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                                } else {
                                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                                    M2C_ERROR(/* unknown instruction: vwaitq */);
                                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf7, $q */);
                                }
                                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1b0($v0) */);
                                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf1 */);
                                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                temp_v1_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                                var_f3_2 = M2C_FIELD(&D_FLT_002BE680, f32 *, 0) + (temp_v1_3 * (M2C_FIELD(&D_FLT_002BE680, f32 *, 4) + (temp_v1_3 * M2C_FIELD(&D_FLT_002BE680, f32 *, 8))));
                                if (var_f3_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                                    var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                                } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < var_f3_2) {
                                    var_f3_2 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                                }
                                if (((1.0f - (temp_f4 / D_FLT_002BE670)) * var_f3_2) != 0.0f) {
                                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s4) */);
                                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                                    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
                                    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf1, $vf2 */);
                                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
                                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
                                    if (M2C_FIELD(arg0, void **, 0x30) != M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x294)) {
                                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
                                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0f) {

                                        }
                                    }
                                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s4) */);
                                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
                                    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
                                    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
                                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
                                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
                                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf8 */);
                                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf8, $vf1, $vf3x */);
                                }
                            }
                        }
                    }
                }
                var_s2 = M2C_FIELD(var_s2, void **, 0x60);
            } while (var_s2 != NULL);
        }
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf8, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf8, $vf8, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($s1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($s1) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf6, $vf8, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf3x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf5, $vf8, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0xd0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xd0($sp) */);
        if (func_001C0B50(spA0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */), &sp40) != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf5 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf3, $vf0, $q */);
            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf3 */) < 0.0001f) {
                sp60 = g_2a2da0;
            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x60($sp) */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            if (D_FLT_002BE690 < M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */)) {
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf6, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0f) {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf6 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xb0($sp) */);
                }
            }
        }
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x80($s1) */);
    M2C_FIELD(arg0, s128 *, 0x90) = spB0;
}
