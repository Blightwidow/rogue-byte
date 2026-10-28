#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct();         /* extern */
M2C_UNK CStackFrame_Destructor();    /* extern */
M2C_UNK Carry_Attach();               /* extern */
M2C_UNK ClearVjoyPresses();          /* extern */
s32 ClsgClipEdgeToObject(); /* extern */
s32 FAsegaGone();                           /* extern */
s32 FButtonPressedWithin(); /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
M2C_UNK FreeSwMqList__FP2SWP2MQ();    /* extern */
s32 GetJtPower();                        /* extern */
s32 GrfbtnJtGadget();        /* extern */
s32 GrfbtnVjoyPressedWithin(); /* extern */
M2C_UNK MarkSoContactsBspBsp(); /* extern */
M2C_UNK MarkSoContactsSphereBsp(); /* extern */
M2C_UNK PosLoWorld();                    /* extern */
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(); /* extern */
s32 PvAllocStackImpl__Fi();    /* extern */
M2C_UNK SetAttachSubstate();         /* extern */
M2C_UNK SetJmpState(); /* extern */
M2C_UNK StartBinoc(); /* extern */
s128 VecMaxOfVerts();                       /* extern */
s128 VecMinOfVerts();                       /* extern */
M2C_UNK bevy_camera_follow_push_out(); /* extern */
s32 func_001423A0();                          /* extern */
M2C_UNK func_001F38A8();                      /* extern */
extern s32 B_002DFBC4;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BF5B4;
extern f32 D_FLT_002BF5B8;
extern M2C_UNK FFilterOxa;
extern f32 g_2dded0;

void UpdateAttachInput(void *arg0) {
    char sp[0x400];
    M2C_UNK sp340;
    M2C_UNK sp370;
    M2C_UNK sp10;
    s32 sp310;
    s32 sp320;
    void **sp324;
    s32 sp328;
    s32 sp32C;
    s32 sp330;
    s32 sp334;
    s128 sp350;
    s128 sp360;
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    f32 *var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a3;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s5;
    s32 var_v0_2;
    void **var_a1_3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_a2_4;
    void *temp_a2_5;
    void *temp_a2_6;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s1;
    void *temp_s7;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v1;
    void *temp_v1_4;
    void *var_a3;
    void *var_v0;

    temp_s7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x150);
loop_1:
    temp_v0 = M2C_FIELD(arg0, s32 *, 8);
    sp334 = M2C_FIELD(arg0, s32 *, 0xC);
    switch (temp_v0) {                              /* switch 1 */
    case 1:                                         /* switch 1 */
        if (((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x10)) > 0.15f) && (var_a1 = 7, (FButtonPressedWithin(temp_s7, 0x40, 0x3E800000) != 0))) {
            var_a3 = M2C_FIELD(arg0, void **, 0x14);
block_68:
            SetJmpState(M2C_FIELD(arg0, void **, 0) + 0x2C0, var_a1, 0, var_a3);
        } else {
block_6:
            if (GrfbtnVjoyPressedWithin(temp_s7, 0x400, 0x3E19999A) != 0) {
                temp_a2 = M2C_FIELD(arg0, void **, 0);
                temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
                if (M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK, void *), 0x31C)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x318), 3, temp_a2) != 0) {
block_73:
                    ClearVjoyPresses(temp_s7, 0x400);
                    StartBinoc(M2C_FIELD(arg0, void **, 0) + 0xF00, 0, 0, 0);
                }
            }
        }
block_80:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xC);
        if ((temp_v1_2 == sp334) || (temp_v1_2 == -1)) {
            return;
        }
        goto loop_1;
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
        if (FButtonPressedWithin(temp_s7, 0x40, 0x3DCCCCCD) == 0) {
            goto block_6;
        }
block_67:
        var_a1 = 1;
        var_a3 = NULL;
        goto block_68;
        goto block_80;
    case 7:                                         /* switch 1 */
        temp_a2_2 = M2C_FIELD(arg0, void **, 0);
        temp_s0 = M2C_FIELD(arg0, void **, 0x14);
        temp_v0_2 = M2C_FIELD(temp_a2_2, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_2 + M2C_FIELD(temp_v0_2, s16 *, 0x2C0), 0, temp_a2_2);
        temp_v0_3 = M2C_FIELD(temp_s0, void **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x19C)(temp_s0 + M2C_FIELD(temp_v0_3, s16 *, 0x198), M2C_FIELD(arg0, void **, 0));
        goto block_80;
    case 8:                                         /* switch 1 */
        switch (sp334) {                            /* switch 2; irregular */
        case 7:                                     /* switch 2 */
            if (FAsegaGone(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030), sp334) != 0) {
                SetAttachSubstate(arg0, 9);
            }
            break;
        case 8:                                     /* switch 2 */
            if (FAsegaGone(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030), sp334) != 0) {
block_61:
                var_a1_2 = 0;
block_62:
                var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xC);
block_63:
                M2C_FIELD(var_v0, M2C_UNK (**)(s32, M2C_UNK, void *), 0x2C4)(M2C_FIELD(arg0, void **, 0) + M2C_FIELD(var_v0, s16 *, 0x2C0), var_a1_2, M2C_FIELD(arg0, void **, 0));
            }
            break;
        default:                                    /* switch 2 */
            CStackFrame_Construct(sp, sp334);
            var_s2 = 0;
            PosLoWorld(M2C_FIELD(arg0, void **, 0));
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf4, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf4, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x340($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x390($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x310($sp) */);
            bevy_camera_follow_push_out(&B_003DD490, sp340, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), &FFilterOxa);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x390($sp) */);
            if (sp320 > 0) {
loop_21:
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x390($sp) */);
                temp_v0_4 = ClsgClipEdgeToObject(sp324[var_s2], M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), sp340, 8);
                var_a0 = 0;
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x390($sp) */);
                if (temp_v0_4 > 0) {
                    var_v1 = &sp10 + 0x40;
loop_23:
                    var_a0 += 1;
                    if (*var_v1 == 0.0f) {
                        var_v1 += 0x60;
                        if (var_a0 >= temp_v0_4) {
                            goto block_25;
                        }
                        goto loop_23;
                    }
                } else {
block_25:
                    var_s2 += 1;
                    if (var_s2 >= sp320) {
                        goto block_26;
                    }
                    goto loop_21;
                }
            } else {
block_26:
                var_s5 = 0;
                temp_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x268);
                temp_s0_2 = temp_s1 + 0x90;
                func_001F38A8(temp_s1);
                sp350 = VecMinOfVerts(M2C_FIELD(temp_s1, s32 *, 0x90), M2C_FIELD(temp_s0_2, s32 *, 4));
                sp360 = VecMaxOfVerts(M2C_FIELD(temp_s1, s32 *, 0x90), M2C_FIELD(temp_s0_2, s32 *, 4));
                bevy_camera_follow_push_out(&B_003DD490, sp350, sp360, &FFilterOxa);
                if (sp320 > 0) {
                    var_a1_3 = sp324;
                    var_s2_2 = sp320;
                    do {
                        temp_v0_5 = *var_a1_3;
                        var_s2_2 -= 1;
                        var_a1_3 += 4;
                        temp_v1_3 = M2C_FIELD(temp_v0_5, s32 *, 0x6C);
                        var_s5 = (temp_v1_3 >= var_s5) ? temp_v1_3 : var_s5;
                    } while (var_s2_2 != 0);
                }
                temp_s5 = (var_s5 > 0x1554) ? 0x1555 : var_s5;
                var_s2_3 = 0;
                sp310 = temp_s5 * 0xC;
                M2C_FIELD(&sp310, s32 *, 4) = 0x10;
                temp_s6 = PvAllocStackImpl__Fi(&sp310, 0x10, &sp310);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x350($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x360($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x310($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x370($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x350($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x370($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (sp320 > 0) {
loop_31:
                    temp_s0_3 = sp324[var_s2_3];
                    sp328 = 0;
                    if (M2C_FIELD(temp_s0_3, s64 *, 0x10) & (0x8000 << 0x22)) {
                        MarkSoContactsSphereBsp(&B_003DD490, temp_s0_3, temp_s1, 0);
                    } else {
                        sp32C = temp_s5;
                        sp330 = temp_s6;
                        if (PruneBsp__FP3BSPP6VECTORfPP3BSP(M2C_FIELD(temp_s0_3, s32 *, 0x74), 0x7FFFFFFF, sp370, &sp32C, M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */)) == 2) {
                            temp_a3 = (sp330 - temp_s6) * 0xAAAAAAAB;
                            sp330 -= 0xC;
                            MarkSoContactsBspBsp(&B_003DD490, temp_s1, temp_s0_3, temp_a3 >> 2);
                        }
                    }
                    if (sp328 == 0) {
                        var_s2_3 += 1;
                        if (var_s2_3 >= sp320) {
                            goto block_39;
                        }
                        goto loop_31;
                    }
                    FreeSwMqList__FP2SWP2MQ(&B_003DD490, sp328);
                } else {
block_39:
                    SetAttachSubstate(arg0, 8);
                }
            }
            CStackFrame_Destructor(sp, 2);
            break;
        }
        goto block_80;
    case 9:                                         /* switch 1 */
        PosLoWorld(M2C_FIELD(arg0, void **, 0x14), sp334);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x380($sp) */);
        PosLoWorld(M2C_FIELD(arg0, void **, 0x474));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x380($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        var_v0_2 = 1;
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < D_FLT_002BF5B4)) {
            var_v0_2 = 0;
        }
        if (var_v0_2 != 0) {
            Carry_Attach(arg0 + 0x440, M2C_FIELD(arg0, void **, 0x14));
            goto block_61;
        }
        goto block_80;
    case 10:                                        /* switch 1 */
        temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030);
        if ((temp_a0 != 0) && (FAsegaGone(temp_a0, sp334) == 0)) {
            if ((D_FLT_002BF5B8 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 4))) && ((temp_a2_3 = M2C_FIELD(arg0, void **, 0), temp_v0_6 = M2C_FIELD(temp_a2_3, void **, 0x150), (M2C_FIELD(temp_v0_6, f32 *, 0x1C) > 0.0f)) || (M2C_FIELD(temp_v0_6, s32 *, 0x30) & 0xD0))) {
                temp_v0_7 = M2C_FIELD(temp_a2_3, void **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_3 + M2C_FIELD(temp_v0_7, s16 *, 0x2C0), 0, temp_a2_3);
                return;
            }
            goto block_80;
        }
        goto block_61;
    case 11:                                        /* switch 1 */
    case 12:                                        /* switch 1 */
        temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030);
        if (temp_a0_2 != 0) {
            if (FAsegaGone(temp_a0_2, sp334) != 0) {
                goto block_61;
            }
        } else {
            goto block_61;
        }
        goto block_80;
    case 5:                                         /* switch 1 */
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x14), 0xB) != 0) {
            var_a1_2 = 8;
            if (func_001423A0(M2C_FIELD(arg0, void **, 0)) != 0) {
                M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xF5C) = (void *) M2C_FIELD(arg0, void **, 0x14);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0), f32 *, 0xF60) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
                goto block_62;
            }
        }
        goto block_80;
    case 2:                                         /* switch 1 */
        if (GetJtPower(M2C_FIELD(arg0, void **, 0), sp334) > 0) {
            temp_a2_4 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_a2_4, s32 *, 0x10EC) == 4) {
                var_v0 = M2C_FIELD(temp_a2_4, void **, 0xC);
                var_a1_2 = 0;
                goto block_63;
            }
            if (!(B_002DFBC4 & 1) && !(M2C_FIELD(temp_s7, s32 *, 0x30) & GrfbtnJtGadget(temp_a2_4, 0x28, temp_a2_4))) {
                goto block_61;
            }
        } else {
            goto block_61;
        }
        goto block_80;
    default:                                        /* switch 1 */
        if (FButtonPressedWithin(temp_s7, 0x40, 0x3DCCCCCD) == 0) {
            if (GrfbtnVjoyPressedWithin(temp_s7, 0x400, 0x3E19999A) != 0) {
                temp_a2_5 = M2C_FIELD(arg0, void **, 0);
                temp_v1_4 = M2C_FIELD(temp_a2_5, void **, 0xC);
                if ((M2C_FIELD(temp_v1_4, s32 (**)(void *, M2C_UNK, void *), 0x31C)(temp_a2_5 + M2C_FIELD(temp_v1_4, s16 *, 0x318), 3, temp_a2_5) != 0) && ((temp_v1_5 = M2C_FIELD(arg0, s32 *, 8), (temp_v1_5 == 0)) || (temp_v1_5 == 0xD))) {
                    goto block_73;
                }
            }
            if ((M2C_FIELD(arg0, s32 *, 0x500) == 0) && !(B_002DFBC4 & 1) && !(M2C_FIELD(temp_s7, s32 *, 0x30) & 0x20)) {
                temp_a2_6 = M2C_FIELD(arg0, void **, 0);
                temp_v0_8 = M2C_FIELD(temp_a2_6, void **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_6 + M2C_FIELD(temp_v0_8, s16 *, 0x2C0), 0, temp_a2_6);
            }
        } else {
            goto block_67;
        }
        goto block_80;
    }
}
