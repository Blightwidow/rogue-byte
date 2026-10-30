typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s32 jtbl_002A51E0[];
struct _m2c_stack_bevy_game_app_job_level_loaded {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s32 spC;                             /* inferred */
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[4];
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ char pad2C[0x74];
};                                                  /* size = 0xA0 */
#define sp14 (*(f32 *)(sp + 0x14))
void ApplyOptionsFromSave(void *);
void ApplyPendingSave();
void CRef_Destruct(s8 **);
s32 CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
void EnterTask(s32);
s32 IEpisodeCurrent();
s32 JobMgr_Construct(s8 *);
s32 LootId(s32);
void OrderTasks(s32 *, s8 ***);
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, M2C_UNK);
void PostTaskJobEvent(s32);
s32 RefGetGameSaveValue(s8 **, s32, void *);
void RequestTransition(M2C_UNK *, M2C_UNK, s32, s32, s32, s32);
void RestoreTaskStateFromSave(s8 *);
void SaveTaskVariables(s8 *);
s32 SetSwCurrentJob(M2C_UNK *, s32);
s32 SetSwCurrentTask(M2C_UNK *, s32);
s32 SetSwRestartTask(M2C_UNK *, s32);
void StartJob(s8 *);
s32 func_00143AF0(s8 *, s32);
void func_00165280(s8 *);
void func_001AB630(void *);
struct EP_2E65E0 { int pad0[2]; int mode; char pad1[0xFD50 - 0xC]; int flag; void *obj; };
extern EP_2E65E0 B_002E65E0;
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E1088;
extern M2C_UNK RO_002A37E8;
#define sp0 (*(s8 **)(sp + 0))
#define sp4p (*(s8 **)(sp + 4))
#define sp8 (*(s32 *)(sp + 8))
#define spC (*(s32 *)(sp + 0xC))
#define sp20 (*(s32 *)(sp + 0x20))
#define sp24 (*(s32 *)(sp + 0x24))
#define sp28 (*(s8 ***)(sp + 0x28))
#define sp4 (*(f32 *)(sp + 4))
void bevy_game_app_job_level_loaded(s8 *arg0, s32 arg1) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v0;
    u32 temp_v1;
    s8 **var_s1;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_s0;
    s8 *frame;
    temp_v1 = arg1 - 1;
    if (temp_v1 < 0x10U) {
        switch (arg1) {
        case 1:
            if (&B_003E1088 == &RO_002A37E8) {
                var_v0 = 1;
            } else if (&B_003E1088 == NULL) {
                var_v0 = 0;
            } else if (&RO_002A37E8 != NULL) {
                var_v0 = (M2C_FIELD(&B_003E1088, s32 *, 8) ^ M2C_FIELD(&B_003E1088, s32 *, 0x38)) == (M2C_FIELD(&RO_002A37E8, s32 *, 8) ^ M2C_FIELD(&RO_002A37E8, s32 *, 0x38));
            } else {
                var_v0 = 0;
            }
            if (var_v0 != 0) {
                temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0, 3, sp);
                var_s2 = temp_v0;
                if (temp_v0 > 0) {
                    var_s1 = (s8 **)(sp);
                    do {
                        temp_s0 = *var_s1;
                        temp_a0 = M2C_FIELD(temp_s0, s32 *, 0x11A8);
                        var_s2 -= 1;
                        if (temp_a0 != 0) {
                            func_00143AF0(temp_s0, LootId(temp_a0));
                        }
                        var_s1 += 4;
                    } while (var_s2 != 0);
                }
            }
            break;
        case 3: {
            M2C_UNK *swp = &B_003DD490;
            if (M2C_FIELD(swp, s32 *, 0x3BF4) & 1) {
                JobMgr_Construct(arg0);
                B_002E65E0.flag = 0;
            } else if (M2C_FIELD(swp, s32 *, 0x3BF4) & 0x40) {
                ApplyPendingSave();
            }
            func_001AB630(&B_002E65E0);
            if ((IEpisodeCurrent() == 0) && (B_002E65E0.mode == 6) && (B_002E65E0.flag == 0) && (B_002E65E0.obj != NULL)) {
                RefGetGameSaveValue((s8 **)(sp + 0x10), M2C_FIELD(swp, s32 *, 0x3B1C), &B_003D4A60);
                f32 fromSave = *(f32 *)(sp + 0x14);
                CRef_Destruct((s8 **)(sp + 0x10));
                if (fromSave == 0.0f) {
                    RefGetGameSaveValue((s8 **)sp, M2C_FIELD(swp, s32 *, 0x3B1C), B_002E65E0.obj);
                    f32 fromSave2 = *(f32 *)(sp + 4);
                    CRef_Destruct((s8 **)sp);
                    if (fromSave2 != 0.0f) {
                        ApplyOptionsFromSave(B_002E65E0.obj);
                    }
                }
            }
            break;
        }
        case 4:
            func_00165280(arg0);
            break;
        case 5: {
            M2C_UNK *swp = &B_003DD490;
            var_s0 = 0;
            frame = sp + 0x20;
            CStackFrame_Construct(frame);
            OrderTasks((s32 *)(sp + 0x24), (s8 ***)(sp + 0x28));
            if (sp24 > 0) {
                do {
                    temp_a0_2 = sp28[var_s0];
                    sp0 = NULL;
                    sp4p = temp_a0_2;
                    if (temp_a0_2 != NULL) {
                        sp8 = M2C_FIELD(temp_a0_2, s32 *, 0xF4);
                        M2C_FIELD(temp_a0_2, s32 *, 0xF4) = 1;
                        spC = M2C_FIELD(sp4p, s32 *, 0xF8);
                        M2C_FIELD(sp4p, s32 *, 0xF8) = 0;
                    }
                    RestoreTaskStateFromSave(temp_a0_2);
                    if (sp0 != NULL) {
                        M2C_FIELD(sp0, s32 *, 0xF0) = sp8;
                        M2C_FIELD(sp0, s32 *, 0xF4) = spC;
                    }
                    if (sp4p != NULL) {
                        M2C_FIELD(sp4p, s32 *, 0xF4) = sp8;
                        M2C_FIELD(sp4p, s32 *, 0xF8) = spC;
                    }
                    var_s0 += 1;
                } while (var_s0 < sp24);
            }
            SetSwCurrentJob(swp, PloFindSwObject_thunk(swp, 0x105, M2C_FIELD(arg0, s32 *, 0x10), 0));
            SetSwCurrentTask(swp, PloFindSwObject_thunk(swp, 0x105, M2C_FIELD(arg0, s32 *, 0x14), 0));
            SetSwRestartTask(swp, PloFindSwObject_thunk(swp, 0x105, M2C_FIELD(arg0, s32 *, 0x18), 0));
            if (M2C_FIELD(swp, s8 **, 0x3B0C) != NULL) {
                StartJob(M2C_FIELD(swp, s8 **, 0x3B0C));
            }
            if (M2C_FIELD(swp, s32 *, 0x3B10) != 0) {
                EnterTask(M2C_FIELD(swp, s32 *, 0x3B10));
            }
            if (M2C_FIELD(swp, s32 *, 0x3BF4) & 4) {
                if (M2C_FIELD(swp, s32 *, 0x3B14) != 0) {
                    PostTaskJobEvent(M2C_FIELD(swp, s32 *, 0x3B14));
                } else {
                    if (M2C_FIELD(swp, s8 **, 0x3B0C) != NULL) {
                        PostTaskJobEvent(M2C_FIELD(M2C_FIELD(swp, s8 **, 0x3B0C), s32 *, 0x64));
                    }
                }
            }
            var_s0_2 = 0;
            if (sp24 > 0) {
                do {
                    temp_a0_3 = sp28[var_s0_2];
                    sp0 = NULL;
                    sp4p = temp_a0_3;
                    if (temp_a0_3 != NULL) {
                        sp8 = M2C_FIELD(temp_a0_3, s32 *, 0xF4);
                        M2C_FIELD(temp_a0_3, s32 *, 0xF4) = 0;
                        spC = M2C_FIELD(sp4p, s32 *, 0xF8);
                        M2C_FIELD(sp4p, s32 *, 0xF8) = 0;
                    }
                    SaveTaskVariables(temp_a0_3);
                    if (sp0 != NULL) {
                        M2C_FIELD(sp0, s32 *, 0xF0) = sp8;
                        M2C_FIELD(sp0, s32 *, 0xF4) = spC;
                    }
                    if (sp4p != NULL) {
                        M2C_FIELD(sp4p, s32 *, 0xF4) = sp8;
                        M2C_FIELD(sp4p, s32 *, 0xF8) = spC;
                    }
                    var_s0_2 += 1;
                } while (var_s0_2 < sp24);
            }
            CStackFrame_Destructor(frame, 2);
            break;
        }
        case 16:
            if (M2C_FIELD(&B_003DD490, s8 **, 0x3B0C) == NULL) {
                RequestTransition(&B_003DD490, 0, M2C_FIELD(&B_003DD490, s32 *, 0x3C88), M2C_FIELD(&B_003DD490, s32 *, 0x3C8C), M2C_FIELD(&B_003DD490, s32 *, 0x3E38) != 0 ? 0x20 : 0, 0x30A);
            }
            break;
        }
    }
}
}
