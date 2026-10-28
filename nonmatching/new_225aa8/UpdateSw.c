#include "m2c_macros.h"

M2C_UNK AssignObstaclesToPathzones();               /* extern */
M2C_UNK ExpireSwWkrs();                       /* extern */
M2C_UNK HitFx_CheckExpiry();                /* extern */
M2C_UNK SolveSw();                            /* extern */
M2C_UNK UpdateAsega();                      /* extern */
M2C_UNK UpdateCmLast();                    /* extern */
M2C_UNK UpdateSaas();                               /* extern */
M2C_UNK UpdateSave__FP4SAVE();             /* extern */
M2C_UNK UpdateSnd();                       /* extern */
M2C_UNK UpdateSwCallbacks();             /* extern */
M2C_UNK UpdateSwGuardsFrozen();          /* extern */
M2C_UNK UpdateSwHudBlots();                   /* extern */
M2C_UNK UpdateSwPaused();                     /* extern */
M2C_UNK UpdateVjoy();                         /* extern */
M2C_UNK func_00128148();                   /* extern */
M2C_UNK func_00147F40();                      /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002E65E0;
extern M2C_UNK B_003DD040;
extern void **g_2dd2fc;
extern M2C_UNK g_2dd598;
extern M2C_UNK g_2dded0;

void UpdateSw(void *arg0) {
    char sp[0x400];
    s32 *sp4;
    s32 sp8;
    void **spC;
    void *sp10;
    s32 *sp14;
    s32 sp18;
    void **sp1C;
    s32 sp20;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    void *temp_a1;
    void *temp_s5;
    void *temp_v0;
    void *temp_v1;
    void *var_s0;

    UpdateSwCallbacks();
    func_00147F40(arg0);
    if (M2C_FIELD(&g_2dded0, f32 *, 4) <= 0.0f) {
        UpdateSwPaused(arg0);
    } else {
        var_s0 = M2C_FIELD(arg0, void **, 0x3EAC);
        temp_s5 = arg0 + 0x3FFC;
        if (var_s0 != NULL) {
            do {
                UpdateVjoy(var_s0);
                var_s0 = M2C_FIELD(var_s0, void **, 0x84);
            } while (var_s0 != NULL);
        }
        ExpireSwWkrs(arg0);
        var_a1 = 0;
        M2C_FIELD(arg0, s32 **, 0x3F1C) = &sp20;
        sp20 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x3F14) > 0) {
            do {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x3F20) + (var_a1 * 8);
                if (M2C_FIELD(temp_v1, s32 *, 0) & 2) {
                    temp_a1 = M2C_FIELD(temp_v1, void **, 4);
                    temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x84)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x80), temp_a1);
                }
                temp_v0_2 = sp20 + 1;
                var_a1 = temp_v0_2;
                sp20 = temp_v0_2;
            } while (var_a1 < M2C_FIELD(arg0, s32 *, 0x3F14));
        }
        M2C_FIELD(arg0, s32 **, 0x3F1C) = NULL;
        UpdateSwGuardsFrozen(arg0, var_a1);
        temp_a0 = M2C_FIELD((arg0 + 0x3D88), s32 *, 8);
        spC = g_2dd2fc;
        g_2dd2fc = sp;
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x3D88);
        var_a1_2 = temp_v1_2;
        sp4 = temp_v1_2 + temp_a0;
        sp8 = temp_a0;
        if (var_a1_2 != 0) {
            do {
                UpdateAsega(var_a1_2, var_a1_2);
                temp_a0_2 = *sp4;
                var_a1_2 = temp_a0_2;
                sp4 = temp_a0_2 + sp8;
            } while (var_a1_2 != 0);
        }
        temp_a0_3 = M2C_FIELD(temp_s5, s32 *, 8);
        sp1C = g_2dd2fc;
        g_2dd2fc = &sp10;
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x3FFC);
        sp10 = temp_s5;
        var_a1_3 = temp_v1_3;
        sp14 = temp_v1_3 + temp_a0_3;
        sp18 = temp_a0_3;
        if (var_a1_3 != 0) {
            do {
                HitFx_CheckExpiry(var_a1_3, var_a1_3);
                temp_a0_4 = *sp14;
                var_a1_3 = temp_a0_4;
                sp14 = temp_a0_4 + sp18;
            } while (var_a1_3 != 0);
        }
        UpdateSwCallbacks(arg0, var_a1_3);
        SolveSw(arg0);
        AssignObstaclesToPathzones();
        UpdateSaas();
        UpdateSwCallbacks(arg0);
        g_2dd2fc = spC;
    }
    UpdateSave__FP4SAVE(&B_002E65E0);
    UpdateSnd(&B_003DD040);
    if (M2C_FIELD(&g_2dded0, f32 *, 0x10) > 0.0f) {
        UpdateCmLast(&B_002DDF40);
    }
    UpdateSwHudBlots(arg0);
    func_00128148(&g_2dd598);
}
