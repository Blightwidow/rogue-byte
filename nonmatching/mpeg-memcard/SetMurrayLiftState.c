#include "m2c_macros.h"

M2C_UNK CalcMurrayThrow(void *, s128, f32 *, f32 *); /* extern */
M2C_UNK ConvertAloMat(s128 *, void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK ConvertXfVec(s32, M2C_UNK, s128);           /* extern */
M2C_UNK DetachMurrayObject(void *);                 /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
M2C_UNK PostGuardStunCommand(void *, void *);       /* extern */
M2C_UNK PredictXfTransform(s32, s32, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetSoNoXpsAll(void *, M2C_UNK);             /* extern */
s32 func_0012DC18(void *, void *, M2C_UNK, M2C_UNK); /* extern */
s32 func_0012DD28(void *, s32, M2C_UNK, void *);    /* extern */
s32 func_0012DDB0(void *, s32, M2C_UNK, M2C_UNK);   /* extern */
s32 func_0012DE58(void *, void *, M2C_UNK, s128, f32); /* extern */
M2C_UNK func_0012E460(void *);                      /* extern */
M2C_UNK func_001A58D0(void *, void *, M2C_UNK);     /* extern */
M2C_UNK func_001B72B0(void *, s32, M2C_UNK *, s128 *); /* extern */
M2C_UNK func_00209E88(void *);                      /* extern */
extern f32 D_FLT_002C0A3C;
extern f32 D_FLT_002C0A40;
extern M2C_UNK RO_002A2D30;
extern f32 g_2dded0;

void SetMurrayLiftState(void *arg0, s32 arg1) {
    char sp[0x400];
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    f32 sp80;
    f32 *temp_v0_2;
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v1_3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s1;
    void *temp_s3;
    void *temp_s3_2;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1450);
    if (temp_v0 != arg1) {
        if (temp_v0 == 1) {
            func_0012E460(arg0 + 0x13FC);
            func_0012E460(arg0 + 0x1400);
        }
        M2C_FIELD(arg0, s32 *, 0x1450) = arg1;
        M2C_FIELD(arg0, f32 *, 0x1454) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case 0:
            M2C_FIELD(arg0, s32 *, 0x1448) = 0;
            break;
        case 2:
            temp_a0 = M2C_FIELD(arg0, void **, 0x13F0);
            if (temp_a0 != NULL) {
                temp_s3 = M2C_FIELD(temp_a0, void **, 0x180);
                if (((u64) M2C_FIELD(temp_s3, u64 *, 0x28) >> 0x3C) & 1) {
                    temp_s0 = M2C_FIELD(arg0, void **, 0x13EC);
                    func_001A58D0(temp_s3, temp_s0, 0xF);
                    SetSoNoXpsAll(temp_s3, 1);
                    func_001B72B0(arg0, M2C_FIELD(temp_s0, s32 *, 0x60), &RO_002A2D30, &sp10);
                    M2C_FIELD(arg0, s32 *, 0x13F8) = func_0012DC18(temp_s3, M2C_FIELD(temp_s3, void **, 0x5C), 5, 7);
                    M2C_FIELD(arg0, s32 *, 0x13F4) = func_0012DC18(temp_s3, M2C_FIELD(temp_s3, void **, 0x58), 5, 7);
                    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13F0), void **, 0x190);
                    if (temp_a2 != NULL) {
                        temp_v1 = M2C_FIELD(temp_a2, void **, 0xC);
                        temp_s0_2 = M2C_FIELD(arg0, void **, 0x1610);
                        M2C_FIELD(temp_s0_2, s32 *, 0) = M2C_FIELD(temp_v1, s32 (**)(void *, s128 *, void *), 0x104)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 0x100), &sp20, temp_a2);
                        M2C_FIELD(temp_s0_2, f32 *, 0xCC) = (f32) D_FLT_002C0A3C;
                        M2C_FIELD(temp_s0_2, s128 *, 0xA0) = sp50;
                        M2C_FIELD(arg0, s32 *, 0x1618) = func_0012DD28(arg0, M2C_FIELD(temp_s0_2, s32 *, 4), 5, temp_s0_2);
                        M2C_FIELD(arg0, s32 *, 0x161C) = func_0012DD28(arg0, M2C_FIELD(temp_s0_2, s32 *, 8), 5, temp_s0_2);
                        M2C_FIELD(arg0, s32 *, 0x1604) = func_0012DDB0(arg0, M2C_FIELD(arg0, s32 *, 0x15F4), 5, 5);
                    }
                    temp_a2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13F0), void **, 0x198);
                    if (temp_a2_2 != NULL) {
                        temp_v1_2 = M2C_FIELD(temp_a2_2, void **, 0xC);
                        temp_s0_3 = M2C_FIELD(arg0, void **, 0x1614);
                        M2C_FIELD(temp_s0_3, s32 *, 0) = M2C_FIELD(temp_v1_2, s32 (**)(void *, s128 *, void *), 0x104)(temp_a2_2 + M2C_FIELD(temp_v1_2, s16 *, 0x100), &sp20, temp_a2_2);
                        M2C_FIELD(temp_s0_3, f32 *, 0xCC) = (f32) D_FLT_002C0A40;
                        M2C_FIELD(temp_s0_3, s128 *, 0xA0) = sp50;
                        M2C_FIELD(arg0, s32 *, 0x1620) = func_0012DD28(arg0, M2C_FIELD(temp_s0_3, s32 *, 4), 5, temp_s0_3);
                        M2C_FIELD(arg0, s32 *, 0x1624) = func_0012DD28(arg0, M2C_FIELD(temp_s0_3, s32 *, 8), 5, temp_s0_3);
                        M2C_FIELD(arg0, s32 *, 0x160C) = func_0012DDB0(arg0, M2C_FIELD(arg0, s32 *, 0x15FC), 5, 5);
                    }
                    var_v0 = arg0 + 0x190;
                    if (FIsBasicDerivedFrom(temp_s3, 0x38) != 0) {
                        func_00209E88(temp_s3);
                        var_v0 = arg0 + 0x190;
                    }
                    M2C_FIELD(var_v0, s32 *, 4) = 0;
                    M2C_FIELD(var_v0, s32 *, 8) = 0;
                    M2C_FIELD(arg0, s32 *, 0x190) = 0;
                } else {
                    goto block_22;
                }
            } else {
block_22:
                DetachMurrayObject(arg0);
                M2C_FIELD(arg0, void **, 0x13F0) = NULL;
                SetMurrayState(arg0, 0);
            }
            break;
        case 1:
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x13F0);
            if ((temp_a0_2 != NULL) && (temp_s3_2 = M2C_FIELD(temp_a0_2, void **, 0x180), ((((u64) M2C_FIELD(temp_s3_2, u64 *, 0x28) >> 0x3C) & 1) != 0))) {
                SetSoCnstrForce(temp_s3_2, 0);
                M2C_FIELD(arg0, s32 *, 0x1404) = (s32) M2C_FIELD(M2C_FIELD(temp_s3_2, void **, 0x58), s16 *, 0x98);
                M2C_FIELD(arg0, s32 *, 0x1408) = (s32) M2C_FIELD(M2C_FIELD(temp_s3_2, void **, 0x5C), s16 *, 0x98);
                func_001A58D0(temp_s3_2, NULL, 0xF);
                SetSoNoXpsAll(temp_s3_2, 1);
                temp_v0_2 = PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), s32 *, 0x14), 0x1C7);
                temp_v0_3 = M2C_FIELD(arg0, void **, 0x1030);
                temp_f0 = (*temp_v0_2 - M2C_FIELD(temp_v0_3, f32 *, 0x1C)) / M2C_FIELD(temp_v0_3, f32 *, 0x40);
                sp80 = temp_f0;
                PredictXfTransform(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13EC), s32 *, 0x60), M2C_FIELD(arg0, s32 *, 0x60), sp, 0, temp_f0);
                ConvertAloMat(&sp40, arg0, 0, sp);
                sp0 = sp40;
                sp10 = sp50;
                sp20 = sp60;
                sp30 = sp70;
                func_001B72B0(arg0, 0, sp, &sp40);
                if (FIsBasicDerivedFrom(temp_s3_2, 0x38) != 0) {
                    PostGuardStunCommand(temp_s3_2, arg0);
                }
                CalcMurrayThrow(arg0, sp50, temp_v0_2, &sp80);
                M2C_FIELD(arg0, s32 *, 0x13FC) = func_0012DE58(temp_s3_2, M2C_FIELD(temp_s3_2, void **, 0x58), 5, sp50, g_2dded0 + sp80);
                temp_s0_4 = M2C_FIELD(temp_s3_2, void **, 0xC);
                temp_s0_5 = temp_s0_4 + 0x118;
                temp_s1 = temp_s3_2 + M2C_FIELD(temp_s0_4, s16 *, 0x118);
                ConvertXfVec(M2C_FIELD(M2C_FIELD(temp_s3_2, void **, 0x58), s32 *, 0xA0), 0, sp60);
                M2C_FIELD(temp_s0_5, M2C_UNK (**)(void *, M2C_UNK), 4)(temp_s1, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
                M2C_FIELD(arg0, s32 *, 0x1400) = func_0012DC18(temp_s3_2, M2C_FIELD(temp_s3_2, void **, 0x5C), 5, 7);
            } else {
                goto block_22;
            }
            break;
        }
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x1450);
        if ((temp_v1_3 < 2) && (temp_v1_3 >= 0)) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x1088), s32 *, 0x1C) = 1;
            return;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1088), s32 *, 0x1C) = 0;
    }
}
