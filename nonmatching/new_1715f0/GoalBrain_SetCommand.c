#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
s32 GoalBrain_FCmdEqual(s128 *, s128 *);            /* extern */
M2C_UNK Goal_Pop(s32);                              /* extern */
M2C_UNK SetGuardScript(void *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetSearchGoal(void *, s32);                 /* extern */
void *func_00205438(void *, M2C_UNK, s128);         /* extern */
M2C_UNK func_00208540(void *, M2C_UNK);             /* extern */
extern M2C_UNK D_FLT_002BE618;
extern M2C_UNK g_2dded0;

void GoalBrain_SetCommand(void *arg0, s128 *arg1) {
    M2C_UNK (*temp_a1)(void *, M2C_UNK);
    M2C_UNK var_a1_4;
    f32 temp_f20;
    s128 *temp_s0;
    s128 *var_a1;
    s128 *var_v0;
    s128 temp_a2;
    s32 temp_v0;
    s32 var_s4;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_a1_2;
    void *var_a1_3;
    void *var_s0;
    void *var_v0_2;
    void *var_v0_3;
    void *var_v0_4;
    void *var_v0_5;
    void *var_v0_6;
    void *var_v0_7;
    void *var_v1;
    void *var_v1_2;
    void *var_v1_3;
    void *var_v1_4;

    temp_s0 = arg0 + 0x30;
    if (GoalBrain_FCmdEqual(arg1, temp_s0) == 0) {
        Goal_Pop(arg0 + 0x18);
        var_a1 = temp_s0;
        var_v0 = arg1;
        do {
            temp_a2 = M2C_FIELD(var_v0, s128 *, 0x10);
            M2C_FIELD(var_a1, s128 *, 0) = M2C_FIELD(var_v0, s128 *, 0);
            M2C_FIELD(var_a1, s128 *, 0x10) = temp_a2;
            var_v0 += 0x20;
            var_a1 += 0x20;
        } while (var_v0 != (arg1 + 0x60));
        *var_a1 = *var_v0;
        M2C_FIELD(arg0, f32 *, 0xA0) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
        temp_v0 = M2C_FIELD(arg1, s32 *, 0);
        var_s4 = 0;
        switch (temp_v0) {
        case 5:
            var_s4 = 1;
            var_s0 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA9, temp_a2);
            SetGuardScript(var_s0, M2C_FIELD(arg1, s32 *, 0x10), 1, 0);
block_10:
            temp_v0_2 = M2C_FIELD(var_s0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(var_s0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
            break;
        case 1:
            var_s4 = 1;
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xAA, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
block_28:
            temp_a1 = M2C_FIELD(var_v1, M2C_UNK (**)(void *, M2C_UNK), 0x44);
            temp_a1(var_v0_2 + M2C_FIELD(var_v1, s16 *, 0x40), temp_a1);
            break;
        case 3:
            var_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0x9D, temp_a2);
            var_a1_2 = M2C_FIELD(var_v0_3, void **, 0xC);
            M2C_FIELD(var_v0_3, s32 *, 0x3C) = 0xB;
            M2C_FIELD(var_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
block_33:
            M2C_FIELD(var_a1_2, M2C_UNK (**)(void *, void *), 0x44)(var_v0_3 + M2C_FIELD(var_a1_2, s16 *, 0x40), var_a1_2);
            break;
        case 4:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA5, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            M2C_FIELD(var_v0_2, s32 *, 0x30) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            goto block_28;
        case 2:
            var_s4 = 1;
            var_s0 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xAB, temp_a2);
            SetSearchGoal(var_s0, M2C_FIELD(arg1, s32 *, 0x10));
            goto block_10;
        case 9:
            var_a1_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA1, temp_a2);
            var_v1_2 = var_a1_3 + 0x50;
            var_v0_4 = arg1 + 0x10;
            do {
                M2C_FIELD(var_v1_2, s128 *, 0) = (s128) M2C_FIELD(var_v0_4, s128 *, 0);
                M2C_FIELD(var_v1_2, s128 *, 0x10) = (s128) M2C_FIELD(var_v0_4, s128 *, 0x10);
                var_v0_4 += 0x20;
                var_v1_2 += 0x20;
            } while (var_v0_4 != (arg1 + 0x70));
            var_v0_5 = M2C_FIELD(var_a1_3, void **, 0xC);
block_20:
            M2C_FIELD(var_v0_5, M2C_UNK (**)(void *, void *), 0x44)(var_a1_3 + M2C_FIELD(var_v0_5, s16 *, 0x40), var_a1_3);
            break;
        case 10:
            var_a1_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA2, temp_a2);
            var_v1_3 = var_a1_3 + 0x50;
            var_v0_6 = arg1 + 0x10;
            do {
                M2C_FIELD(var_v1_3, s128 *, 0) = (s128) M2C_FIELD(var_v0_6, s128 *, 0);
                M2C_FIELD(var_v1_3, s128 *, 0x10) = (s128) M2C_FIELD(var_v0_6, s128 *, 0x10);
                var_v0_6 += 0x20;
                var_v1_3 += 0x20;
            } while (var_v0_6 != (arg1 + 0x70));
            var_v0_5 = M2C_FIELD(var_a1_3, void **, 0xC);
            goto block_20;
        case 11:
            var_a1_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xA3, temp_a2);
            var_v1_4 = var_a1_3 + 0x50;
            var_v0_7 = arg1 + 0x10;
            do {
                M2C_FIELD(var_v1_4, s128 *, 0) = (s128) M2C_FIELD(var_v0_7, s128 *, 0);
                M2C_FIELD(var_v1_4, s128 *, 0x10) = (s128) M2C_FIELD(var_v0_7, s128 *, 0x10);
                var_v0_7 += 0x20;
                var_v1_4 += 0x20;
            } while (var_v0_7 != (arg1 + 0x70));
            var_v0_5 = M2C_FIELD(var_a1_3, void **, 0xC);
            var_s4 = 1;
            goto block_20;
        case 8:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xAF, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            goto block_28;
        case 6:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xB0, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            M2C_FIELD(var_v0_2, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
            goto block_28;
        case 7:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xB1, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            M2C_FIELD(var_v0_2, s32 *, 0x5C) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            goto block_28;
        case 12:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xB2, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            goto block_28;
        case 13:
            var_a1_4 = 0xB4;
block_27:
            var_v0_2 = func_00205438(M2C_FIELD(arg0, void **, 0x10), var_a1_4, temp_a2);
            var_v1 = M2C_FIELD(var_v0_2, void **, 0xC);
            M2C_FIELD(var_v0_2, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            goto block_28;
        case 14:
            var_a1_4 = 0xB6;
            goto block_27;
        case 15:
            var_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xAE, temp_a2);
            var_a1_2 = M2C_FIELD(var_v0_3, void **, 0xC);
            M2C_FIELD(var_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x108C);
            goto block_33;
        case 16:
            var_s4 = 1;
            var_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xB7, temp_a2);
            var_a1_2 = M2C_FIELD(var_v0_3, void **, 0xC);
            M2C_FIELD(var_v0_3, s32 *, 0x30) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF68);
            M2C_FIELD(var_v0_3, s128 *, 0x40) = (s128) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s128 *, 0xF70);
            goto block_33;
        case 17:
            temp_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0x9E, temp_a2);
            temp_a1_2 = M2C_FIELD(temp_v0_3, void **, 0xC);
            M2C_FIELD(temp_v0_3, s32 *, 0x3C) = 0x1A;
            M2C_FIELD(temp_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            M2C_FIELD(temp_a1_2, M2C_UNK (**)(void *, void *), 0x44)(temp_v0_3 + M2C_FIELD(temp_a1_2, s16 *, 0x40), temp_a1_2);
            temp_f20 = M2C_FIELD(&g_2dded0, f32 *, -0x2130);
            M2C_FIELD(arg0, f32 *, 0xA4) = (f32) (temp_f20 + GRandInRange(M2C_FIELD(&D_FLT_002BE618, f32 *, 0), M2C_FIELD(&D_FLT_002BE618, f32 *, 4)));
            break;
        case 18:
            var_v0_3 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xBD, temp_a2);
            var_a1_2 = M2C_FIELD(var_v0_3, void **, 0xC);
            M2C_FIELD(var_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            M2C_FIELD(var_v0_3, f32 *, 0x40) = (f32) M2C_FIELD(arg1, f32 *, 0x14);
            goto block_33;
        case 19:
            temp_v0_4 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xBF, temp_a2);
            temp_a1_3 = M2C_FIELD(temp_v0_4, void **, 0xC);
            M2C_FIELD(temp_v0_4, s128 *, 0x40) = (s128) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s128 *, 0x4B0);
            M2C_FIELD(temp_a1_3, M2C_UNK (**)(void *, void *), 0x44)(temp_v0_4 + M2C_FIELD(temp_a1_3, s16 *, 0x40), temp_a1_3);
            break;
        }
        if (var_s4 != 0) {
            func_00208540(M2C_FIELD(arg0, void **, 0x10), 0);
        }
    }
}
