#include "m2c_macros.h"

M2C_UNK ApplyAseg(s32, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK BindAnimref(void *, void *);                /* extern */
M2C_UNK EnsureCrvExcludedRanges(s32);               /* extern */
M2C_UNK EnsureSggAlarm__FP3SGGP5ALARM(s32, s32);    /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
void *PcmdFindScriptLabel(s32, s32);                /* extern */
s32 PloFindScriptObject(void *, s32);               /* extern */
M2C_UNK ResetAnimref(void *, void *);               /* extern */
M2C_UNK SetGoalTarget(void *, s32 *);               /* extern */
M2C_UNK TeleportGuardScript(void *, s128, f32);     /* extern */
M2C_UNK func_00171AF8(void *, s32, void *, f32 *);  /* extern */
M2C_UNK func_0017CDB8(void *, s128 *);              /* extern */
M2C_UNK func_0017D110(void *, s128 *);              /* extern */
M2C_UNK func_001EEFC0(void *);                      /* extern */
M2C_UNK func_001EF038(void *);                      /* extern */
void *func_00205438(void *, M2C_UNK);               /* extern */
M2C_UNK func_002562A8(s32 *);                       /* extern */
extern f32 g_2dded0;

void ExecuteGuardScriptCmd(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    s32 sp10;
    s32 sp14;
    s128 sp20;
    f32 sp30;
    void *sp34;
    M2C_UNK sp38;
    M2C_UNK (*temp_a1)(void *, M2C_UNK);
    M2C_UNK (*temp_a1_2)(void *, M2C_UNK);
    M2C_UNK var_a1;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0_2;
    s32 temp_v0_7;
    s32 temp_v1_3;
    u32 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a1_6;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_10;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *var_s0;
    void *var_v0;

    temp_v1 = M2C_FIELD(arg1, u32 *, 0);
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s32 *, 0x34) = PloFindScriptObject(arg0, M2C_FIELD(arg1, s32 *, 4));
    default:
        break;
    case 1:
        M2C_ERROR(/* unknown instruction: ldl $v1, 0xf($s3) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, 0x8($s3) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x2d3($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x2cc($v0) */);
        break;
    case 2:
        M2C_ERROR(/* unknown instruction: ldl $v1, 0xf($s3) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, 0x8($s3) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x2db($v0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x2d4($v0) */);
        break;
    case 3:
        func_00171AF8(arg0, PloFindScriptObject(arg0, M2C_FIELD(arg1, s32 *, 4)), sp, &sp30);
        TeleportGuardScript(arg0, sp0, sp30);
        break;
    case 4:
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        sp34 = arg1 + 4;
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 4, 0, 1);
        break;
    case 5:
        temp_a0 = M2C_FIELD(arg0, void **, 0x10);
        temp_v1_3 = M2C_FIELD(temp_a0, s32 *, 0xF80);
        if (temp_v1_3 != 2) {
            if (temp_v1_3 < 3) {
                if (temp_v1_3 != -1) {
                    M2C_FIELD(arg0, s32 *, 0x40) = 1;
                } else {
                    temp_v0 = func_00205438(temp_a0, 0x9E);
                    temp_v1_4 = M2C_FIELD(temp_v0, void **, 0xC);
                    temp_a1 = M2C_FIELD(temp_v1_4, M2C_UNK (**)(void *, M2C_UNK), 0x44);
                    temp_a1(temp_v0 + M2C_FIELD(temp_v1_4, s16 *, 0x40), temp_a1);
                    goto block_55;
                }
            } else if (temp_v1_3 != 3) {
                M2C_FIELD(arg0, s32 *, 0x40) = 1;
            } else {
                var_a1 = 0xBC;
                goto block_15;
            }
        } else {
            var_a1 = 0xBB;
block_15:
            var_v0 = func_00205438(temp_a0, var_a1);
block_54:
            temp_v1_5 = M2C_FIELD(var_v0, void **, 0xC);
            temp_a1_2 = M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *, M2C_UNK), 0x44);
            temp_a1_2(var_v0 + M2C_FIELD(temp_v1_5, s16 *, 0x40), temp_a1_2);
block_55:
block_56:
            M2C_FIELD(arg0, s32 *, 0x40) = 1;
        }
        break;
    case 6:
        temp_v0_2 = PloFindScriptObject(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 4));
        if (temp_v0_2 != 0) {
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
            temp_s1 = M2C_FIELD(temp_a0_2, s32 *, 0xF80);
            if (temp_s1 != 0) {
                if (temp_s1 <= 0) {
                    if (temp_s1 != -1) {
                        M2C_FIELD(arg0, s32 *, 0x40) = 1;
                    } else {
                        var_s0 = func_00205438(temp_a0_2, 0xC0);
                        M2C_FIELD(var_s0, s32 *, 0x30) = temp_v0_2;
                        M2C_FIELD(var_s0, s32 *, 0x34) = (s32) M2C_FIELD(arg1, s32 *, 8);
                        M2C_FIELD(var_s0, s32 *, 0x58) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
                        if (M2C_FIELD(arg0, s32 *, 0x4C) == 0) {
                            EnsureCrvExcludedRanges(temp_v0_2);
                        }
                        temp_v0_3 = M2C_FIELD(arg0, void **, 0x44);
                        if (temp_v0_3 != NULL) {
                            M2C_FIELD(var_s0, f32 *, 0x38) = (f32) M2C_FIELD(temp_v0_3, f32 *, 8);
                        }
                        temp_a1_3 = M2C_FIELD(arg1, s32 *, 0xC);
                        if (temp_a1_3 != temp_s1) {
                            M2C_FIELD(var_s0, s32 *, 0x50) = PloFindScriptObject(arg0, temp_a1_3);
                        }
                        goto block_31;
                    }
                } else if (temp_s1 != 1) {
                    M2C_FIELD(arg0, s32 *, 0x40) = 1;
                } else {
                    temp_v0_4 = func_00205438(temp_a0_2, 0xB9);
                    func_0017D110(temp_v0_4, M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s128 **, 8));
                    temp_v0_5 = M2C_FIELD(temp_v0_4, void **, 0xC);
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *), 0x44)(temp_v0_4 + M2C_FIELD(temp_v0_5, s16 *, 0x40));
                    goto block_55;
                }
            } else {
                var_s0 = func_00205438(temp_a0_2, 0xB8);
                func_0017CDB8(var_s0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s128 **, 8));
block_31:
                temp_v0_6 = M2C_FIELD(var_s0, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0x44)(var_s0 + M2C_FIELD(temp_v0_6, s16 *, 0x40));
                goto block_55;
            }
        }
        break;
    case 7:
        func_002562A8(&sp10);
        temp_a0_3 = M2C_FIELD(arg0, void **, 0x38);
        temp_a1_4 = M2C_FIELD(temp_a0_3, s32 *, 4);
        if (temp_a1_4 == -1) {
            sp20 = *M2C_FIELD(temp_a0_3, s128 **, 8);
            M2C_FIELD(arg0, f32 *, 0x48) = (f32) M2C_FIELD(temp_a0_3, f32 *, 0xC);
        } else {
            temp_v0_7 = PloFindScriptObject(arg0, temp_a1_4);
            if (temp_v0_7 != 0) {
                func_00171AF8(arg0, temp_v0_7, NULL, arg0 + 0x48);
                if (FIsBasicDerivedFrom(temp_v0_7, 0xA) == 0) {
                    sp14 = temp_v0_7;
                } else {
                    sp10 = temp_v0_7;
                }
            }
        }
        temp_a0_4 = M2C_FIELD(arg0, void **, 0x10);
        temp_s1_2 = M2C_FIELD(temp_a0_4, s32 *, 0xF80);
        if (temp_s1_2 == -1) {
            temp_v0_8 = func_00205438(temp_a0_4, 0xBA);
            SetGoalTarget(temp_v0_8, &sp10);
            temp_a1_5 = M2C_FIELD(arg1, s32 *, 0x10);
            if (temp_a1_5 != temp_s1_2) {
                M2C_FIELD(temp_v0_8, s32 *, 0xA8) = PloFindScriptObject(arg0, temp_a1_5);
            }
            temp_v1_6 = M2C_FIELD(temp_v0_8, void **, 0xC);
            M2C_FIELD(temp_v0_8, f32 *, 0xB0) = (f32) M2C_FIELD(arg1, f32 *, 0x14);
            M2C_FIELD(temp_v0_8, s32 *, 0xBC) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            M2C_FIELD(temp_v1_6, M2C_UNK (**)(void *), 0x44)(temp_v0_8 + M2C_FIELD(temp_v1_6, s16 *, 0x40));
        }
        goto block_56;
    case 8:
        ApplyAseg(PloFindScriptObject(arg0, M2C_FIELD(arg1, s32 *, 4)), 0, 0, &sp38, 0, 0x3F800000);
        break;
    case 10:
        temp_v0_9 = PcmdFindScriptLabel(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg1, s32 *, 4));
        if (temp_v0_9 != NULL) {
            M2C_FIELD(arg0, void **, 0x38) = temp_v0_9;
        }
        break;
    case 11:
        func_001EEFC0(arg0);
        break;
    case 12:
        func_001EF038(arg0);
        break;
    case 13:
        temp_s0 = PloFindScriptObject(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 4));
        temp_v0_10 = func_00205438(M2C_FIELD(arg0, void **, 0x10), 0xAC);
        M2C_FIELD(temp_v0_10, s32 *, 0x60) = temp_s0;
        M2C_FIELD(temp_v0_10, s32 *, 0x68) = 1;
        temp_a1_6 = M2C_FIELD(temp_v0_10, void **, 0xC);
        M2C_FIELD(temp_v0_10, s32 *, 0x64) = (s32) M2C_FIELD(arg1, s32 *, 8);
        M2C_FIELD(temp_a1_6, M2C_UNK (**)(void *, void *), 0x44)(temp_v0_10 + M2C_FIELD(temp_a1_6, s16 *, 0x40), temp_a1_6);
        M2C_FIELD(arg0, s32 *, 0x40) = 1;
        break;
    case 14:
        temp_s0_2 = arg0 + 0x50;
        ResetAnimref(temp_s0_2, M2C_FIELD(arg0, void **, 0x10));
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x5C) = (s32) M2C_FIELD(arg1, s32 *, 8);
        BindAnimref(temp_s0_2, M2C_FIELD(arg0, void **, 0x10));
        temp_a0_5 = M2C_FIELD(arg0, void **, 0x10);
        if (M2C_FIELD(temp_a0_5, s32 *, 0xF80) == -1) {
            var_v0 = func_00205438(temp_a0_5, 0x9D);
            M2C_FIELD(var_v0, void **, 0x40) = temp_s0_2;
            goto block_54;
        }
        break;
    case 15:
        EnsureSggAlarm__FP3SGGP5ALARM(PloFindScriptObject(arg0, M2C_FIELD(arg1, s32 *, 4)), M2C_FIELD(arg1, s32 *, 8));
        break;
    }
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) g_2dded0;
}
