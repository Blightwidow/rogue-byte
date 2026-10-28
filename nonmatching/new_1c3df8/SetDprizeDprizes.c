#include "m2c_macros.h"

s32 PpoolFromLoClone(void *);                       /* extern */
void *PsmaApplySm(s32, void *, s32, M2C_UNK);       /* extern */
M2C_UNK RetractSma(void *);                         /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID(void *, s32);        /* extern */
M2C_UNK SkipSma(void *, f32);                       /* extern */
M2C_UNK UnlockLeaseOfPlo(s32, void *);              /* extern */
M2C_UNK func_001A58D0(M2C_UNK, M2C_UNK);            /* extern */
extern s128 D_002C0D60;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void SetDprizeDprizes(void *arg0, u32 arg1) {
    M2C_UNK (*temp_a1_3)(void *, M2C_UNK);
    f32 temp_f12;
    s128 *var_v1;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 var_s2;
    s32 var_v0;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1_2;
    void *temp_a1_4;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1_2;
    void *temp_v1_3;

    var_s2 = -1;
    if (M2C_FIELD(arg0, u32 *, 0x150) != arg1) {
        if ((arg1 != 0) && (arg1 != 5)) {
            func_001A58D0(0, 0);
        }
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x150);
        if ((temp_v1 == -1U) || (var_v0 = arg1 < 6U, (temp_v1 == 2))) {
            temp_v0 = M2C_FIELD(arg0, void **, 0x58);
            M2C_FIELD(arg0, s128 *, 0x170) = (s128) M2C_FIELD(temp_v0, s128 *, 0x30);
            M2C_FIELD(arg0, s128 *, 0x180) = (s128) M2C_FIELD(temp_v0, s128 *, 0xB0);
            var_v0 = arg1 < 6U;
        }
        if (var_v0 != 0) {
            switch (arg1) {
            case 0:
                temp_a1 = M2C_FIELD(arg0, s32 *, 0x15C);
                var_s2 = (~temp_a1 != 0) ? temp_a1 : 0x184;
                M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
                break;
            case 3:
            case 4:
                var_s2 = 0x183;
                var_v1 = &D_002C0D60;
block_14:
                M2C_FIELD(arg0, s128 *, 0x190) = (s128) *var_v1;
                break;
            case 2:
                temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(arg0, f32 *, 0x1CC) = 3.4028235e38f;
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x48));
                temp_v0_2 = PpoolFromLoClone(arg0);
                if (temp_v0_2 != 0) {
                    UnlockLeaseOfPlo(temp_v0_2, arg0);
                }
                break;
            case 5:
                var_s2 = 0x186;
                var_v1 = &g_2a2dd0;
                goto block_14;
            }
        }
        if (arg1 != 0) {
            if (((s32) arg1 >= 0) && ((s32) arg1 < 6)) {
                if ((s32) arg1 >= 4) {
                    goto block_19;
                }
                goto block_22;
            }
block_22:
            if (M2C_FIELD(arg0, void **, 0x16C) != NULL) {
                temp_v0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x16C), void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x4C)(M2C_FIELD(arg0, void **, 0x16C) + M2C_FIELD(temp_v0_3, s16 *, 0x48), M2C_FIELD(arg0, void **, 0x16C));
            }
        } else {
block_19:
            temp_a1_2 = M2C_FIELD(arg0, void **, 0x16C);
            if (temp_a1_2 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_a1_2, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *), 0x44)(temp_a1_2 + M2C_FIELD(temp_v0_4, s16 *, 0x40), temp_a1_2);
            }
        }
        M2C_FIELD(arg0, u32 *, 0x150) = arg1;
        M2C_FIELD(arg0, f32 *, 0x154) = (f32) g_2dded0;
        if (var_s2 != -1) {
            temp_a0 = M2C_FIELD(arg0, void **, 0x168);
            if (temp_a0 == NULL) {
                temp_v0_5 = PsmaApplySm(M2C_FIELD(arg0, s32 *, 0x164), arg0, var_s2, 0);
                M2C_FIELD(arg0, void **, 0x168) = temp_v0_5;
                temp_v1_3 = M2C_FIELD(temp_v0_5, void **, 0xC);
                temp_a1_3 = M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK), 0xC);
                temp_a1_3(temp_v0_5 + M2C_FIELD(temp_v1_3, s16 *, 8), temp_a1_3);
                temp_f12 = M2C_FIELD(arg0, f32 *, 0x160);
                if (temp_f12 > 0.0f) {
                    SkipSma(M2C_FIELD(arg0, void **, 0x168), temp_f12);
                }
            } else {
                SetSmaGoal__FP3SMA3OID(temp_a0, var_s2);
            }
        } else {
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x168);
            if (temp_a0_2 != NULL) {
                RetractSma(temp_a0_2);
                temp_a1_4 = M2C_FIELD(arg0, void **, 0x168);
                temp_v0_6 = M2C_FIELD(temp_a1_4, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x14)(temp_a1_4 + M2C_FIELD(temp_v0_6, s16 *, 0x10), temp_a1_4);
                M2C_FIELD(arg0, void **, 0x168) = NULL;
            }
        }
    }
}
