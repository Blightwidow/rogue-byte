typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetTaskState {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s8 *sp14;                          /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s32 sp1C;                            /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[8];                       /* maybe part of sp24[3]? */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of sp30[4]? */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of sp40[4]? */
    /* 0x50 */ s32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x8C];
};                                                  /* size = 0xE0 */
M2C_UNK CRef_CopyConstruct(s32 *, s32 *);           /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK CollectTaskPrerequisites(s8 *, s32, s32 *, s8 **); /* extern */
s32 FTaskRunning(s8 *);                           /* extern */
u32 IEpisodeCurrent();                              /* extern */
s32 NPercentComplete(M2C_UNK *);                    /* extern */
M2C_UNK NotifyJobTaskState(s32, s8 *);            /* extern */
s8 **PvAllocStackClearImpl__Fi(s32 *, s32 *, M2C_UNK); /* extern */
M2C_UNK RefSetGameSaveValue(s32 *, s32, s32 *, M2C_UNK *); /* extern */
M2C_UNK SetTaskStateCascade(s8 *, s32);           /* extern */
M2C_UNK TryAutosave(M2C_UNK *, M2C_UNK);            /* extern */
extern s32 B_002DEB28;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E65E0;
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003DD490;
extern s32 B_003E0F8C;
void SetTaskState(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    s8 *sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp30;
    s32 sp40;
    s32 sp50;
    s32 temp_a0_2;
    s32 temp_s3_2;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a2;
    s32 var_a3_2;
    s32 var_s0;
    s32 var_s1;
    u32 temp_v0;
    s8 **temp_s3;
    s8 **temp_v0_4;
    s8 **var_a3;
    s8 **var_s0_2;
    s8 *temp_a0;
    s8 *var_v1;
    temp_s5 = M2C_FIELD(arg0, s32 *, 0x54);
    if ((arg1 != temp_s5) && (B_002DEB28 == 0)) {
        var_s0 = -1;
        B_002DEB28 = 1;
        if (arg1 < 3) {
            if (arg1 > 0) {
                var_s0 = 2;
            }
        } else if (arg1 == 3) {
            var_s0 = 3;
        }
        if (var_s0 != -1) {
            var_s1 = 0;
            CStackFrame_Construct(sp);
            sp50 = 0;
            sp10 = B_003E0F8C * 4;
            M2C_FIELD(&sp10, s32 *, 4) = 0x10;
            temp_s3 = PvAllocStackClearImpl__Fi(&sp10, &sp10, 0x10);
            M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
            CollectTaskPrerequisites(arg0, var_s0, &sp50, temp_s3);
            if (sp50 > 0) {
                var_s0_2 = temp_s3;
                do {
                    temp_a0 = *var_s0_2;
                    sp10 = 0;
                    sp14 = temp_a0;
                    if (temp_a0 != NULL) {
                        sp18 = M2C_FIELD(temp_a0, s32 *, 0xF4);
                        M2C_FIELD(temp_a0, s32 *, 0xF4) = (s32) M2C_FIELD(arg0, s32 *, 0xF4);
                        sp1C = M2C_FIELD(sp14, s32 *, 0xF8);
                        M2C_FIELD(sp14, s32 *, 0xF8) = (s32) M2C_FIELD(arg0, s32 *, 0xF8);
                    }
                    SetTaskStateCascade(temp_a0, M2C_FIELD(temp_a0, s32 *, 0xF0));
                    if (sp10 != 0) {
                        M2C_FIELD(sp10, s32 *, 0xF0) = sp18;
                        M2C_FIELD(sp10, s32 *, 0xF4) = sp1C;
                    }
                    if (sp14 != NULL) {
                        M2C_FIELD(sp14, s32 *, 0xF4) = sp18;
                        M2C_FIELD(sp14, s32 *, 0xF8) = sp1C;
                    }
                    var_s1 += 1;
                    var_s0_2 += 4;
                } while (var_s1 < sp50);
                var_a0 = 0;
                if (sp50 > 0) {
                    var_a3 = temp_s3;
                    do {
                        var_a0 += 1;
                        M2C_FIELD(*var_a3, s32 *, 0xF0) = -1;
                        var_a3 += 4;
                    } while (var_a0 < sp50);
                }
            }
            M2C_FIELD(arg0, s32 *, 0xF0) = -1;
            CStackFrame_Destructor(sp, 2);
        }
        SetTaskStateCascade(arg0, arg1);
        B_002DEB28 = 0;
        temp_v0 = IEpisodeCurrent();
        if (temp_v0 < 9U) {
            temp_s3_2 = M2C_FIELD((&B_003DD490 + (temp_v0 * 4)), s32 *, 0x3B7C);
            if (temp_s3_2 != 0) {
                temp_v0_2 = NPercentComplete(&B_002DEB30);
                sp20 = 0x15;
                sp24 = temp_v0_2;
                CRef_CopyConstruct(&sp30, &sp20);
                RefSetGameSaveValue(&sp40, temp_s3_2, &sp30, &B_003D4A60);
                CRef_Destruct(&sp40);
                CRef_Destruct(&sp30);
                CRef_Destruct(&sp20);
            }
        }
        if ((FTaskRunning(arg0) != 0) && (temp_s5 != -1) && (temp_s5 < 2) && (M2C_FIELD(arg0, s32 *, 0x54) >= 2) && ((temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x7C), (temp_a0_2 == 0)) || (NotifyJobTaskState(temp_a0_2, arg0), (M2C_FIELD(arg0, s32 *, 0x7C) == 0)))) {
            var_a3_2 = 1;
            if (M2C_FIELD(arg0, s32 *, 0x94) != 0) {
                temp_v0_3 = M2C_FIELD(arg0, s32 *, 0xA0);
                var_a2 = 0;
                if (temp_v0_3 > 0) {
                    temp_v0_4 = M2C_FIELD(arg0, s8 ***, 0xA4);
                    var_v1 = *temp_v0_4;
loop_39:
                    if (M2C_FIELD(var_v1, s32 *, 0x7C) != 0) {
                        var_a2 += 1;
                        if (var_a2 < temp_v0_3) {
                            var_v1 = *((var_a2 * 4) + temp_v0_4);
                            goto loop_39;
                        }
                    } else {
                        var_a3_2 = 0;
                    }
                }
                if (var_a3_2 != 0) {
                    goto block_44;
                }
            } else {
block_44:
                TryAutosave(&B_002E65E0, 0);
            }
        }
    }
}
}
