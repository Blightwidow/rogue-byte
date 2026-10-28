#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(s32, void *, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK DecrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK DecrementSwHandsOff__FP2SW(M2C_UNK *);      /* extern */
M2C_UNK IncrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK IncrementSwHandsOff__FP2SW(M2C_UNK *);      /* extern */
M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK SetAsegaSpeed(void *, M2C_UNK);             /* extern */
M2C_UNK SetBinocHudBlot(void *, s32);               /* extern */
M2C_UNK SetBinocHudState(void *, M2C_UNK);          /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, void *, void *); /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK SetSndbankVolumeFactor(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD040;
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void SetBinocState(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_s3;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_a2_4;
    void *temp_a3;
    void *temp_a3_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_12;
    void *temp_v0_13;
    void *temp_v0_14;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *var_a0;
    void *var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 4);
    if (arg1 != temp_a0) {
        if (temp_a0 != -1) {
            if (temp_a0 == 1) {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x20);
                if (temp_v1 != temp_a0) {
                    switch (temp_v1) {              /* switch 1; irregular */
                    case 0:                         /* switch 1 */
                        RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 7, &B_002DDF40 + 0x450);
                        break;
                    case 2:                         /* switch 1 */
                        RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 7, &B_002DDF40 + 0x450);
                        break;
                    }
                } else {
                    RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 8, &B_002DDF40 + 0x520);
                    temp_s0 = M2C_FIELD(arg0, void **, 0x40);
                    if (temp_s0 != NULL) {
                        temp_v0 = M2C_FIELD(temp_s0, void **, 0xC);
                        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x2A4)(temp_s0 + M2C_FIELD(temp_v0, s16 *, 0x2A0), 0x3F, 1);
                        SetSoCnstrForce(temp_s0, 0);
                    }
                    temp_a3 = M2C_FIELD(arg0, void **, 0);
                    temp_v0_2 = M2C_FIELD(temp_a3, void **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, void *), 0x2A4)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x2A0), 0x3F, 0, temp_a3);
                }
                SetResetFlag__FP2CM(&B_002DDF40);
                SetSndbankVolumeFactor(&B_003DD040, 0, 3, 0x3F800000);
                SetSndbankVolumeFactor(&B_003DD040, 1, 3, 0x3F800000);
                if (M2C_FIELD(arg0, s32 *, 0x20) != 2) {
                    temp_a2 = M2C_FIELD(arg0, void **, 0);
                    temp_v0_3 = M2C_FIELD(temp_a2, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2BC)(temp_a2 + M2C_FIELD(temp_v0_3, s16 *, 0x2B8), 0, temp_a2);
                }
            }
        } else {
            if (M2C_FIELD(arg0, s32 *, 0x20) == 1) {
                IncrementSwBinocCount(&B_003DD490);
                IncrementSwHandsOff__FP2SW(&B_003DD490);
            }
            temp_v1_2 = M2C_FIELD(arg0, void **, 0);
            var_v0 = M2C_FIELD(temp_v1_2, void **, 0x1030);
            if (var_v0 == NULL) {
                temp_v0_4 = M2C_FIELD(temp_v1_2, void **, 0x1034);
                if (temp_v0_4 != NULL) {
                    var_v0 = M2C_FIELD(temp_v0_4, void **, 0x30);
                    goto block_21;
                }
            } else {
block_21:
                M2C_FIELD(arg0, void **, 0x18) = var_v0;
            }
            temp_a1 = M2C_FIELD(arg0, void **, 0x18);
            if (temp_a1 != NULL) {
                temp_v0_5 = M2C_FIELD(temp_a1, void **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, void *), 0xC)(temp_a1 + M2C_FIELD(temp_v0_5, s16 *, 8), temp_a1);
                SetAsegaSpeed(M2C_FIELD(arg0, void **, 0x18), 0);
            }
        }
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        var_s3 = 0;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2; irregular */
        case -1:                                    /* switch 2 */
            temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x20);
            switch (temp_v1_3) {                    /* switch 4; irregular */
            default:                                /* switch 4 */
                var_a0 = arg0 + 0x24;
                if (temp_v1_3 != 0) {

                } else {
block_57:
                    SetBinocHudState(var_a0, -1);
                }
                break;
            case 2:                                 /* switch 4 */
                var_a0 = arg0 + 0x24;
                goto block_57;
            case 1:                                 /* switch 4 */
                SetBinocHudState(arg0 + 0x24, -1);
                DecrementSwBinocCount(&B_003DD490);
                DecrementSwHandsOff__FP2SW(&B_003DD490);
                break;
            }
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x18);
            if (temp_a0_2 != NULL) {
                SetAsegaSpeed(temp_a0_2, 0x3F800000);
                temp_a1_2 = M2C_FIELD(arg0, void **, 0x18);
                temp_v0_6 = M2C_FIELD(temp_a1_2, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x14)(temp_a1_2 + M2C_FIELD(temp_v0_6, s16 *, 0x10), temp_a1_2);
                M2C_FIELD(arg0, void **, 0x18) = NULL;
            }
            M2C_FIELD(arg0, s32 *, 0x20) = -1;
            break;
        case 0:                                     /* switch 2 */
            var_s3 = M2C_FIELD(arg0, s32 *, 0xC);
            break;
        case 1:                                     /* switch 2 */
            temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x20);
            if (temp_v1_4 != arg1) {
                switch (temp_v1_4) {                /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 7, &B_002DDF40 + 0x450, M2C_FIELD(arg0, void **, 0));
                    SetStepRadTarget(M2C_FIELD(arg0, void **, 0), M2C_FIELD(&B_002DDF40, f32 *, 0x460));
                    SetBinocHudState(arg0 + 0x24, 0);
                    break;
                case 2:                             /* switch 3 */
                    SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 7, &B_002DDF40 + 0x450, M2C_FIELD(arg0, void **, 0x40));
                    SetBinocHudState(arg0 + 0x24, 0);
                    break;
                }
            } else {
                SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 8, &B_002DDF40 + 0x520, M2C_FIELD(arg0, void **, 0));
                SetStepRadTarget(M2C_FIELD(arg0, void **, 0), M2C_FIELD(&B_002DDF40, f32 *, 0x5C4));
                temp_s1 = M2C_FIELD(arg0, void **, 0x40);
                if (temp_s1 != NULL) {
                    temp_v1_5 = M2C_FIELD(temp_s1, void **, 0xC);
                    M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x29C)(temp_s1 + M2C_FIELD(temp_v1_5, s16 *, 0x298), 0x3F, 1);
                    SetSoCnstrForce(temp_s1, 1);
                    temp_v0_7 = temp_s1 + 0x190;
                    M2C_FIELD(temp_v0_7, s32 *, 4) = 0;
                    M2C_FIELD(temp_v0_7, s32 *, 8) = 0;
                    M2C_FIELD(temp_s1, s32 *, 0x190) = 0;
                    temp_v0_8 = M2C_FIELD(temp_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, s128), 0x11C)(temp_s1 + M2C_FIELD(temp_v0_8, s16 *, 0x118), g_2a2dd0);
                    temp_v0_9 = M2C_FIELD(temp_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_9, M2C_UNK (**)(void *, s128), 0x124)(temp_s1 + M2C_FIELD(temp_v0_9, s16 *, 0x120), g_2a2dd0);
                }
                temp_s0_2 = arg0 + 0x24;
                SetBinocHudBlot(temp_s0_2, M2C_FIELD(arg0, s32 *, 0x44));
                SetBinocHudState(temp_s0_2, 0);
                temp_a3_2 = M2C_FIELD(arg0, void **, 0);
                temp_v0_10 = M2C_FIELD(temp_a3_2, void **, 0xC);
                M2C_FIELD(temp_v0_10, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, void *), 0x29C)(temp_a3_2 + M2C_FIELD(temp_v0_10, s16 *, 0x298), 0x3F, 0, temp_a3_2);
            }
            temp_v1_6 = M2C_FIELD(arg0, void **, 0);
            temp_v0_11 = temp_v1_6 + 0x190;
            M2C_FIELD(temp_v0_11, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_11, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_6, s32 *, 0x190) = 0;
            temp_a2_2 = M2C_FIELD(arg0, void **, 0);
            temp_v0_12 = M2C_FIELD(temp_a2_2, void **, 0xC);
            M2C_FIELD(temp_v0_12, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2_2 + M2C_FIELD(temp_v0_12, s16 *, 0x118), g_2a2dd0, temp_a2_2);
            temp_a2_3 = M2C_FIELD(arg0, void **, 0);
            temp_v0_13 = M2C_FIELD(temp_a2_3, void **, 0xC);
            M2C_FIELD(temp_v0_13, M2C_UNK (**)(void *, s128, void *), 0x124)(temp_a2_3 + M2C_FIELD(temp_v0_13, s16 *, 0x120), g_2a2dd0, temp_a2_3);
            SetResetFlag__FP2CM(&B_002DDF40);
            SetSndbankVolumeFactor(&B_003DD040, 0, 3, 0x3F19999A);
            SetSndbankVolumeFactor(&B_003DD040, 1, 3, 0x3F19999A);
            if (M2C_FIELD(arg0, s32 *, 0x20) != 2) {
                temp_a2_4 = M2C_FIELD(arg0, void **, 0);
                temp_v0_14 = M2C_FIELD(temp_a2_4, void **, 0xC);
                M2C_FIELD(temp_v0_14, M2C_UNK (**)(void *, M2C_UNK, void *), 0x2BC)(temp_a2_4 + M2C_FIELD(temp_v0_14, s16 *, 0x2B8), 1, temp_a2_4);
            }
            break;
        case 2:                                     /* switch 2 */
            SetBinocHudState(arg0 + 0x24, 2);
            var_s3 = M2C_FIELD(arg0, s32 *, 0x10);
            break;
        }
        temp_a1_3 = M2C_FIELD(arg0, void **, 0);
        if (var_s3 != 0) {
            temp_v1_7 = M2C_FIELD(temp_a1_3, void **, 0xC);
            var_s3 = (M2C_FIELD(temp_v1_7, s32 (**)(void *, void *), 0x2F4)(temp_a1_3 + M2C_FIELD(temp_v1_7, s16 *, 0x2F0), temp_a1_3) == 0) ? 0 : var_s3;
        }
        ApplyAsegToHandle(var_s3, M2C_FIELD(arg0, void **, 0), 1, arg0 + 0x14, 0, 0x3F800000);
    }
}
