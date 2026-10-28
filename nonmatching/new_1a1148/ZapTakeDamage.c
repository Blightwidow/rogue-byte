#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(); /* extern */
s32 CidGetBasic();                            /* extern */
M2C_UNK DropJtLoot();                         /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
s32 NewEmitter();                            /* extern */
M2C_UNK PhitfxSpawn();          /* extern */
M2C_UNK PosLoWorld();                         /* extern */
s32 SFromCrvlU__FP4CRVLf();           /* extern */
M2C_UNK SetEmitterUnpositioned();        /* extern */
M2C_UNK SetJtZapState();             /* extern */
M2C_UNK SetZapContinuation();  /* extern */
M2C_UNK ZapKnockback();                /* extern */
M2C_UNK bevy_camera_follow_activity(); /* extern */
s32 func_001A2358();                                /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern s128 D_002BFB10;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

s32 ZapTakeDamage(void *arg0, void **arg1) {
    char sp[0x400];
    s32 sp30;
    M2C_UNK (*temp_a2_5)(void *, s128, M2C_UNK, void *);
    M2C_UNK var_a1_2;
    M2C_UNK var_s0_2;
    s128 temp_a2_4;
    s32 *temp_a1;
    s32 *temp_v1_4;
    s32 temp_a0;
    s32 temp_a0_4;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1_5;
    s32 var_s0;
    s32 var_v0;
    void **var_a1;
    void **var_s2;
    void **var_v0_2;
    void **var_v0_3;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_5;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_a2_6;
    void *temp_a2_7;
    void *temp_a3;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_6;
    void *temp_v1_7;
    void *var_v1;

    var_s2 = arg1;
    if (func_001A2358() == 0) {
        temp_a2_2 = M2C_FIELD(arg0, void **, 0);
        temp_v1_2 = M2C_FIELD(temp_a2_2, void **, 0xC);
        var_v0 = 0;
        if (M2C_FIELD(temp_v1_2, s32 (**)(void *, s32, void *), 0x264)(temp_a2_2 + M2C_FIELD(temp_v1_2, s16 *, 0x260), M2C_FIELD(var_s2, s32 *, 0xC), temp_a2_2) == 0) {
            temp_v1_3 = M2C_FIELD(arg0, void **, 0);
            if (M2C_FIELD(temp_v1_3, s32 *, 0x4C8) != 1) {
                var_s0 = 0;
                if (M2C_FIELD(temp_v1_3, s32 *, 0x29C) == 0) {
                    if (M2C_FIELD(arg0, s32 *, 0x90) == 1) {

                    } else {
                        var_s0 = SFromCrvlU__FP4CRVLf(&B_002DE578, M2C_FIELD(var_s2, s32 *, 0x10));
                    }
                }
                if (M2C_FIELD(var_s2, s32 *, 0xC) == 0x100000) {
                    var_a1 = var_s2;
                    if ((*M2C_FIELD(arg0, s32 **, 0x10) + var_s0) > 0) {
                        if (M2C_FIELD(arg0, s32 *, 0x90) != 1) {
                            M2C_FIELD(arg0, s32 *, 0x90) = 0;
                            M2C_FIELD(arg0, f32 *, 0x94) = (f32) g_2dded0;
                            M2C_FIELD(arg0, f32 *, 0x98) = (f32) g_2dded0;
                        }
                        temp_v1_4 = M2C_FIELD(arg0, s32 **, 0x10);
                        *temp_v1_4 += var_s0;
                        temp_a0 = M2C_FIELD(arg0, s32 *, 0x108);
                        if (temp_a0 != 0) {
                            ApplyAsegToHandle(temp_a0, M2C_FIELD(arg0, void **, 0), 1, arg0 + 0x10C, 0, 0x3F800000);
                        }
                    } else {
                        var_v0_2 = sp;
                        temp_a0_2 = var_a1 + 0x60;
                        do {
                            M2C_FIELD(var_v0_2, s128 *, 0) = (s128) M2C_FIELD(var_a1, s128 *, 0);
                            M2C_FIELD(var_v0_2, s128 *, 0x10) = (s128) M2C_FIELD(var_a1, s128 *, 0x10);
                            var_a1 += 0x20;
                            var_v0_2 += 0x20;
                        } while (var_a1 != temp_a0_2);
                        var_s2 = sp;
                        M2C_FIELD(&sp30, s32 *, 4) = 0;
                        M2C_FIELD(&sp30, s32 *, 8) = 0;
                        sp30 = 0;
                        goto block_23;
                    }
                } else {
block_23:
                    temp_a0_3 = *var_s2;
                    if ((temp_a0_3 != NULL) && (FIsBasicDerivedFrom(temp_a0_3, 0x38) != 0) && ((temp_a0_4 = M2C_FIELD(*var_s2, s32 *, 0xFBC), (temp_a0_4 == 8)) || (temp_a0_4 == 0xD))) {
                        var_s0 = var_s0 / 2;
                    }
                    goto block_28;
                }
                goto block_81;
            }
            temp_a2 = M2C_FIELD(temp_v1_3, void **, 0x4D4);
            temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
            return M2C_FIELD(temp_v1, s32 (**)(void *, void **, void *), 0x25C)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x258), var_s2, temp_a2);
        }
        /* Duplicate return node #82. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = 0;
    if ((u32) (M2C_FIELD(arg0, s32 *, 4) - 8) >= 5U) {
        var_s0 = -0x8000;
block_28:
        temp_a2_3 = M2C_FIELD(arg0, void **, 0);
        temp_v0 = M2C_FIELD(temp_a2_3, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2C4)(temp_a2_3 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 3, temp_a2_3);
        temp_a0_5 = M2C_FIELD(arg0, void **, 0);
        temp_v0_2 = M2C_FIELD(temp_a0_5, void **, 0x11A8);
        if ((temp_v0_2 != NULL) && ((M2C_FIELD(M2C_FIELD(temp_v0_2, void **, 0x158), s32 *, 8) != 0) || ((*M2C_FIELD(arg0, s32 **, 0x10) + var_s0) <= 0))) {
            DropJtLoot(temp_a0_5);
        }
        bevy_camera_follow_activity(&B_002DEB30, 0xF, M2C_FIELD(var_s2, void **, 0));
        var_v1 = arg0 + 0x30;
        var_v0_3 = var_s2;
        do {
            temp_a2_4 = M2C_FIELD(var_v0_3, s128 *, 0x10);
            M2C_FIELD(var_v1, s128 *, 0) = (s128) M2C_FIELD(var_v0_3, s128 *, 0);
            M2C_FIELD(var_v1, s128 *, 0x10) = temp_a2_4;
            var_v0_3 += 0x20;
            var_v1 += 0x20;
        } while (var_v0_3 != (var_s2 + 0x60));
        M2C_FIELD(arg0, s32 *, 0x40) = var_s0;
        M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A676F)($v0) */);
        SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6768)($v0) */), temp_a2_4);
        temp_a1 = M2C_FIELD(arg0, s32 **, 0x10);
        temp_v0_3 = *temp_a1 + M2C_FIELD(arg0, s32 *, 0x40);
        *temp_a1 = (temp_v0_3 <= -1) ? 0 : temp_v0_3;
        if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
            M2C_FIELD(arg0, s32 *, 0x90) = 1;
            M2C_FIELD(arg0, f32 *, 0x94) = (f32) g_2dded0;
        }
        temp_v1_5 = M2C_FIELD(var_s2, s32 *, 0xC);
        switch (temp_v1_5) {                        /* switch 1; irregular */
        case 0x400:                                 /* switch 1 */
            temp_a3 = M2C_FIELD(arg0, void **, 0);
            temp_v1_6 = M2C_FIELD(temp_a3, void **, 0xC);
            temp_a2_5 = M2C_FIELD(temp_v1_6, M2C_UNK (**)(void *, s128, M2C_UNK, void *), 0x11C);
            temp_a2_5(temp_a3 + M2C_FIELD(temp_v1_6, s16 *, 0x118), D_002BFB10, temp_a2_5, temp_a3);
            if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
                SetJtZapState(arg0, 4);
            } else {
                SetJtZapState(arg0, 0xC);
            }
            break;
        case 0x100:                                 /* switch 1 */
        case 0x200:                                 /* switch 1 */
            ZapKnockback(arg0, temp_a1);
            temp_a1_2 = M2C_FIELD(arg0, void **, 0);
            temp_v1_7 = M2C_FIELD(temp_a1_2, void **, 0xC);
            M2C_FIELD(temp_v1_7, M2C_UNK (**)(void *, void *), 0x10C)(temp_a1_2 + M2C_FIELD(temp_v1_7, s16 *, 0x108), temp_a1_2);
            if (M2C_ERROR(/* unknown instruction: pextuw $t1, $zero, $v0 */) > 400.0f) {
                var_s0_2 = -1;
                temp_v0_4 = CidGetBasic(M2C_FIELD(arg0, void **, 0));
                switch (temp_v0_4) {                /* switch 2; irregular */
                case 0x35:                          /* switch 2 */
                    var_s0_2 = 0x69;
                    break;
                case 0x37:                          /* switch 2 */
                    var_s0_2 = 0x83;
                    break;
                case 0x36:                          /* switch 2 */
                    var_s0_2 = 0x84;
                    break;
                }
                temp_s0 = M2C_FIELD(arg0, void **, 0);
                SetEmitterUnpositioned(NewEmitter(var_s0_2), temp_s0);
            }
            M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A6777)($v0) */);
            SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6770)($v0) */));
            break;
        case 0x8000:                                /* switch 1 */
            SetJtZapState(arg0, 7);
            M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A677F)($v0) */);
            SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6778)($v0) */));
            break;
        case 0x800:                                 /* switch 1 */
        case 0x1000:                                /* switch 1 */
            temp_a2_6 = M2C_FIELD(arg0, void **, 0);
            temp_v0_5 = M2C_FIELD(temp_a2_6, void **, 0xC);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2_6 + M2C_FIELD(temp_v0_5, s16 *, 0x118), g_2a2dd0, temp_a2_6);
            temp_a2_7 = M2C_FIELD(arg0, void **, 0);
            temp_v0_6 = M2C_FIELD(temp_a2_7, void **, 0xC);
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, s128, void *), 0x124)(temp_a2_7 + M2C_FIELD(temp_v0_6, s16 *, 0x120), g_2a2dd0, temp_a2_7);
            SetJtZapState(arg0, ((M2C_FIELD(var_s2, s32 *, 0xC) ^ 0x800) != 0) ? 2 : 1);
            M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A6787)($v0) */);
            SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6780)($v0) */));
            break;
        case 0x2000:                                /* switch 1 */
            if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
                var_a1_2 = 3;
block_78:
                SetJtZapState(arg0, var_a1_2);
                M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A678F)($v0) */);
                SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6788)($v0) */));
            } else {
                SetJtZapState(arg0, 0xA);
            }
            break;
        case 0x4000:                                /* switch 1 */
            if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
                var_a1_2 = 5;
                goto block_78;
            }
            SetJtZapState(arg0, 0xB);
            break;
        case 0x40:                                  /* switch 1 */
            ZapKnockback(arg0, temp_a1);
            M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A6777)($v0) */);
            SetZapContinuation(arg0, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6770)($v0) */));
            break;
        }
block_81:
        PosLoWorld(M2C_FIELD(arg0, void **, 0));
        PhitfxSpawn(M2C_FIELD(&B_003DD490, s32 *, 0x4038), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), M2C_FIELD(arg0, void **, 0));
        var_v0 = 1;
    }
    return var_v0;
}
