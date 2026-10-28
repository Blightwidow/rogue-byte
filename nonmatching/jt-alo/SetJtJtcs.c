#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(void *, void *, M2C_UNK, void *, f32, f32); /* extern */
M2C_UNK Carry_SetState(void *, M2C_UNK);            /* extern */
M2C_UNK ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(void *, void *, void *); /* extern */
s128 ConvertAloPos(M2C_UNK, void *, s128);          /* extern */
s32 IsmsFindSmOptional__FP2SM3OID(s32, M2C_UNK);    /* extern */
s32 NewEmitter(s32);                                /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK SeekSma(s32, M2C_UNK);                      /* extern */
M2C_UNK SetAmbPos(s32, M2C_UNK);                    /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK func_00131A90(void *, f32);                 /* extern */
M2C_UNK func_001F2AD0(void *, s32);                 /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */
extern s32 B_002E1E44;
extern s32 B_002E1E48;
extern M2C_UNK D_002BF448;
extern f32 D_FLT_002BF430;
extern f32 D_FLT_002BF434;
extern f32 D_FLT_002BF438;
extern f32 D_FLT_002BF43C;
extern f32 D_FLT_002BF440;
extern f32 g_2dded0;

void SetJtJtcs(void *arg0, s32 arg1) {
    M2C_UNK sp4;
    s128 sp20;
    f32 *var_v1;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1_2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *var_s0_2;

    var_s2 = arg1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x18D8);
    if (temp_a0 != var_s2) {
        var_s4 = 0;
        if ((var_s2 != -1) && (temp_a0 != -1)) {
            var_s4 = var_s2 == *((temp_a0 * 4) + &D_002BF448);
        }
        if (var_s4 == 0) {
            func_001F2AD0(arg0, M2C_FIELD(arg0, s32 *, 0x1A88));
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D8);
        var_s0 = -1;
        switch (temp_v1) {                          /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x18C4), s32 *, 0x130);
            func_001F4BF8(arg0);
            break;
        case 2:                                     /* switch 1 */
            func_001F4BF8(arg0);
            break;
        case 0:                                     /* switch 1 */
            Carry_SetState(arg0 + 0x17D0, -1);
            break;
        }
        if (var_s0 != -1) {
            temp_v0 = NewEmitter(var_s0);
            SetEmitterUnpositioned(temp_v0, 0);
            PosLoWorld(arg0);
            SetAmbPos(temp_v0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        }
        var_f22 = 0.0f;
        var_s0_2 = NULL;
        var_f21 = 1.0f;
        var_f20 = 0.0f;
        var_s3 = -1;
        switch (var_s2) {                           /* switch 2 */
        case -1:                                    /* switch 2 */
            M2C_FIELD(arg0, s32 *, 0x18C0) = 0;
            break;
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            func_001F4BF8(arg0);
            break;
        case 10:                                    /* switch 2 */
            func_001F4BF8(arg0);
            var_s0_2 = M2C_FIELD(arg0, void **, 0x14D4);
            break;
        case 11:                                    /* switch 2 */
            func_001F4BF8(arg0);
            var_s0_2 = M2C_FIELD(arg0, void **, 0x14D8);
            break;
        case 0:                                     /* switch 2 */
            Carry_SetState(arg0 + 0x17D0, 0);
            var_f21 = 0.0f;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1800);
            var_s3 = 0xF;
            var_f22 = M2C_FIELD(var_s0_2, f32 *, 0x74) * 0.5f;
            func_001F4BF8(arg0);
            var_f1 = 0.1f;
            var_f0 = g_2dded0;
block_42:
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (var_f0 + var_f1);
            break;
        case 3:                                     /* switch 2 */
            PosLoWorld(M2C_FIELD(arg0, void **, 0x19A4));
            sp20 = ConvertAloPos(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
            ConvertAloPos(0, arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x19C0), s128 *, 0x70));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf4, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            if (M2C_FIELD(arg0, s32 *, 0x18C8) == 0) {
                var_s2 = 6;
                if (B_002E1E44 == 0) {
                    var_s2 = 7;
                    if (B_002E1E48 == 0) {
                        var_s2 = 6;
                        if (!(sp4 < 0.0f)) {
                            var_s2 = 7;
                            goto block_38;
                        }
                        goto block_35;
                    }
                case 7:                             /* switch 2 */
block_38:
                    var_s3 = 0xB;
                    ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(arg0, arg0 + 0x1A58, M2C_FIELD(arg0, void **, 0x1A70));
                    var_f20 = D_FLT_002BF430;
                    var_s0_2 = M2C_FIELD(arg0, void **, 0x1A70);
                    var_v1 = &g_2dded0;
                    if (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x1028), 0x17B) >= 0) {
                        SeekSma(M2C_FIELD(arg0, s32 *, 0x1034), 0x17B);
                        var_v1 = &g_2dded0;
                    }
                    var_f1 = D_FLT_002BF438;
                } else {
                case 6:                             /* switch 2 */
block_35:
                    var_s3 = 0xB;
                    ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(arg0, arg0 + 0x1A3C, M2C_FIELD(arg0, void **, 0x1A54));
                    var_f20 = D_FLT_002BF430;
                    var_s0_2 = M2C_FIELD(arg0, void **, 0x1A54);
                    var_v1 = &g_2dded0;
                    if (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x1028), 0x17B) >= 0) {
                        SeekSma(M2C_FIELD(arg0, s32 *, 0x1034), 0x17B);
                        var_v1 = (f32 *)0x2E0000;
                    }
                    var_f1 = D_FLT_002BF434;
                }
                var_f0 = *var_v1;
                goto block_42;
            }
            var_s2 = 4;
            if (B_002E1E44 == 0) {
                var_s2 = 5;
                if (B_002E1E48 == 0) {
                    var_s2 = 4;
                    if (!(sp4 < 0.0f)) {
                        var_s2 = 5;
                        goto block_34;
                    }
                    goto block_33;
                }
            case 5:                                 /* switch 2 */
block_34:
                var_s3 = 0xB;
                ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(arg0, arg0 + 0x1A20, M2C_FIELD(arg0, void **, 0x1A38));
                var_f20 = D_FLT_002BF430;
                var_s0_2 = M2C_FIELD(arg0, void **, 0x1A38);
                M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF438);
            } else {
            case 4:                                 /* switch 2 */
block_33:
                var_s3 = 0xB;
                ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(arg0, arg0 + 0x1A04, M2C_FIELD(arg0, void **, 0x1A1C));
                var_f20 = D_FLT_002BF430;
                var_s0_2 = M2C_FIELD(arg0, void **, 0x1A1C);
                M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF434);
            }
            break;
        case 8:                                     /* switch 2 */
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1A74);
            break;
        case 9:                                     /* switch 2 */
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1A78);
            break;
        case 12:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            var_f0_2 = g_2dded0 + D_FLT_002BF440;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CE0);
block_47:
            M2C_FIELD(arg0, f32 *, 0x19B0) = var_f0_2;
            if ((M2C_FIELD(arg0, s32 *, 0x18C8) == 0) && (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x1028), 0x17B) >= 0)) {
                SeekSma(M2C_FIELD(arg0, s32 *, 0x1034), 0x17B);
            }
            break;
        case 13:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            var_f0_2 = g_2dded0 + D_FLT_002BF440;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CE4);
            goto block_47;
        case 14:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CE8);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 15:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CEC);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 16:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CF0);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 17:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CF4);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 18:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CF8);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 19:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1CFC);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 20:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1D00);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 21:                                    /* switch 2 */
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 1;
            var_s0_2 = M2C_FIELD(arg0, void **, 0x1D04);
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            break;
        case 22:                                    /* switch 2 */
        case 23:                                    /* switch 2 */
            if (var_s2 != 0x16) {
                var_s0_2 = M2C_FIELD(arg0, void **, 0x1D18);
            } else {
                var_s0_2 = M2C_FIELD(arg0, void **, 0x1D14);
            }
            var_f20 = D_FLT_002BF43C;
            M2C_FIELD(arg0, s32 *, 0x18EC) = 0;
            M2C_FIELD(arg0, f32 *, 0x19B0) = (f32) (g_2dded0 + D_FLT_002BF440);
            if ((M2C_FIELD(arg0, s32 *, 0x18C8) == 0) && (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x1028), 0x17B) >= 0)) {
                SeekSma(M2C_FIELD(arg0, s32 *, 0x1034), 0x17B);
            }
            break;
        }
        if (var_s4 == 0) {
            M2C_FIELD(arg0, s32 *, 0x18E4) = 0;
        } else {
            temp_v0_2 = M2C_FIELD(arg0, void **, 0x18E0);
            var_s3 = -1;
            var_f21 = M2C_FIELD(temp_v0_2, f32 *, 0x40) / M2C_FIELD(temp_v0_2, f32 *, 0x48);
            var_f22 = M2C_ERROR(/* unknown instruction: min.s $f22, $f0, $f1 */);
        }
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x18D8);
        var_a0 = 0;
        if ((temp_v1_2 == 0xB) || (temp_v1_2 == 2)) {
            var_a0 = 1;
        }
        var_v1_2 = 0;
        if ((var_s2 == 0xB) || (var_s2 == 2)) {
            var_v1_2 = 1;
        }
        if (var_a0 != var_v1_2) {
            if (var_s2 != 0xB) {
                if (var_s2 != 2) {
                    temp_a1 = M2C_FIELD(arg0, void **, 0x19A0);
                    temp_v0_3 = M2C_FIELD(temp_a1, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x44)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x40), temp_a1);
                    temp_a2 = M2C_FIELD(arg0, void **, 0x19A0);
                    temp_v0_4 = M2C_FIELD(temp_a2, void **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *, void *), 0x134)(temp_a2 + M2C_FIELD(temp_v0_4, s16 *, 0x130), M2C_FIELD(arg0, void **, 0x19A8), temp_a2);
                    temp_a1_2 = M2C_FIELD(arg0, void **, 0x19A8);
                    temp_v0_5 = M2C_FIELD(temp_a1_2, void **, 0xC);
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1_2 + M2C_FIELD(temp_v0_5, s16 *, 0x48), temp_a1_2);
                } else {
                    goto block_80;
                }
            } else {
block_80:
                temp_a1_3 = M2C_FIELD(arg0, void **, 0x19A8);
                temp_v0_6 = M2C_FIELD(temp_a1_3, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x44)(temp_a1_3 + M2C_FIELD(temp_v0_6, s16 *, 0x40), temp_a1_3);
                temp_a2_2 = M2C_FIELD(arg0, void **, 0x19A8);
                temp_v0_7 = M2C_FIELD(temp_a2_2, void **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, void *, void *), 0x134)(temp_a2_2 + M2C_FIELD(temp_v0_7, s16 *, 0x130), M2C_FIELD(arg0, void **, 0x19A0), temp_a2_2);
                temp_a1_4 = M2C_FIELD(arg0, void **, 0x19A0);
                temp_v0_8 = M2C_FIELD(temp_a1_4, void **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1_4 + M2C_FIELD(temp_v0_8, s16 *, 0x48), temp_a1_4);
            }
        }
        M2C_FIELD(arg0, s32 *, 0x18D8) = var_s2;
        M2C_FIELD(arg0, s32 *, 0x1880) = 0;
        M2C_FIELD(arg0, f32 *, 0x18DC) = (f32) g_2dded0;
        ApplyAsegToHandle(var_s0_2, arg0, 1, arg0 + 0x18E0, var_f22, var_f21);
        if (var_f20 != 0.0f) {
            func_00131A90(M2C_FIELD(arg0, void **, 0x18E0), g_2dded0 + var_f20);
        }
        if (var_s3 != -1) {
            temp_v0_9 = NewEmitter(var_s3);
            SetEmitterUnpositioned(temp_v0_9, 0);
            PosLoWorld(arg0);
            SetAmbPos(temp_v0_9, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        }
    }
}
