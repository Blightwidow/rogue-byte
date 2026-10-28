#include "m2c_macros.h"

M2C_UNK ActivateSpawn(void *);                      /* extern */
M2C_UNK AddGrfusr__Fi(M2C_UNK);                     /* extern */
M2C_UNK AllocSwBuffers(void *, void *, s64, s64);   /* extern */
M2C_UNK CBinaryFileStream_Close(M2C_UNK *);         /* extern */
M2C_UNK CBinaryFileStream_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 CBinaryFileStream_FOpenLocation(M2C_UNK *, s32 *); /* extern */
M2C_UNK CBinaryFileStream_Pump(M2C_UNK *);          /* extern */
M2C_UNK CBinaryInputStream_ConstructFromBuffer(M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *, s32, s64, s64); /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK Clear__13CFileLocation(s32 *);              /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FPlayQueuedMovies(M2C_UNK *);                   /* extern */
M2C_UNK FlushFrames__Fi(M2C_UNK);                   /* extern */
s32 GetPoVjoyMode(void *);                          /* extern */
s32 IEpisodeCurrent();                              /* extern */
M2C_UNK InitClock(f32 *);                           /* extern */
M2C_UNK InitCm(M2C_UNK *);                          /* extern */
M2C_UNK LoadSwFromBrx(void *, M2C_UNK *);           /* extern */
void *PloFindSpawn(void *, s32, s32);               /* extern */
void *PloFindSwObject_thunk(void *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK PostLoadWipe(M2C_UNK *);                    /* extern */
s32 PpoSwFocus(void *);                             /* extern */
void *PpoSwFocusBase(void *);                       /* extern */
M2C_UNK RunNextBootQueueEntry(M2C_UNK *);           /* extern */
M2C_UNK SetBlotBlots(void *, M2C_UNK);              /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK ShowCountdownBlot(void *, f32);             /* extern */
M2C_UNK ShutdownSwForLoad(void *);                  /* extern */
M2C_UNK Sw_Construct(M2C_UNK *);                    /* extern */
M2C_UNK UpdateCmLast(M2C_UNK *);                    /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001179D8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0014C258();                            /* extern */
M2C_UNK func_001C2A78(M2C_UNK);                     /* extern */
M2C_UNK func_001C2BA8(M2C_UNK);                     /* extern */
M2C_UNK func_001D8A38(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_0020E740(void *);                      /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E1E88;
extern M2C_UNK B_002F66B0;
extern M2C_UNK B_002F7980;
extern M2C_UNK B_003DD490;
extern M2C_UNK B_00443740;
extern void *g_2dd5bc;
extern f32 g_2dded0;
extern void *g_2e1e40;
extern void *g_2f7900;

void ExecuteSwLoadRequest(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp1E4;
    M2C_UNK sp38;
    M2C_UNK sp8;
    s32 sp4;
    s32 sp40;
    M2C_UNK sp50;
    s32 sp60;
    s32 sp64;
    M2C_UNK sp170;
    M2C_UNK sp1E0;
    f32 var_f20;
    s32 *var_v1_4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s2;
    s32 temp_s7;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0_2;
    s32 var_s2;
    s32 var_v0;
    s32 var_v1_2;
    s64 var_a2;
    s64 var_a2_2;
    s64 var_a3;
    s64 var_a3_2;
    void **var_s1;
    void *temp_a0_2;
    void *temp_a2;
    void *temp_s0;
    void *temp_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *var_a0;
    void *var_a1;
    void *var_s3;
    void *var_v1;
    void *var_v1_3;

    if (M2C_FIELD(arg0, s32 *, 0x3BF0) != 0) {
        FlushFrames__Fi(1);
        var_v1 = arg0 + 0x3BF4;
        var_a0 = sp;
        temp_s3 = var_v1;
        if ((s32) var_v1 & 7) {
            do {
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, ($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $a2, 0xf($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, 0x8($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $a3, 0x17($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a3, 0x10($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $t0, 0x1f($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $t0, 0x18($v1) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, ($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0xf($a0) */);
                var_a2 = M2C_ERROR(/* unknown instruction: sdr $a2, 0x8($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a3, 0x17($a0) */);
                var_a3 = M2C_ERROR(/* unknown instruction: sdr $a3, 0x10($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $t0, 0x1f($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $t0, 0x18($a0) */);
                var_v1 += 0x20;
                var_a0 += 0x20;
            } while (var_v1 != (arg0 + 0x3C34));
        } else {
            do {
                var_a2 = M2C_FIELD(var_v1, s64 *, 8);
                var_a3 = M2C_FIELD(var_v1, s64 *, 0x10);
                M2C_FIELD(var_a0, s64 *, 0) = (s64) M2C_FIELD(var_v1, s64 *, 0);
                M2C_FIELD(var_a0, s64 *, 8) = var_a2;
                M2C_FIELD(var_a0, s64 *, 0x10) = var_a3;
                M2C_FIELD(var_a0, s64 *, 0x18) = (s64) M2C_FIELD(var_v1, s64 *, 0x18);
                var_v1 += 0x20;
                var_a0 += 0x20;
            } while (var_v1 != (arg0 + 0x3C34));
        }
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($v1) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, ($v1) */);
        temp_a1 = M2C_FIELD(var_v1, s32 *, 8);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($a0) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, ($a0) */);
        M2C_FIELD(var_a0, s32 *, 8) = temp_a1;
        M2C_FIELD(arg0, s32 *, 0x3BF0) = 0;
        if (sp0 & 0xCD) {
            var_f20 = 0.0f;
        } else {
            var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f1 */);
        }
        CStackFrame_Construct(&sp50, temp_a1, var_a2, var_a3);
        func_001C2A78(2);
        M2C_FIELD(&sp60, s32 *, 8) = 2;
        Clear__13CFileLocation(&sp60);
        temp_a0 = sp8 ^ sp40;
        temp_s7 = sp8 != sp40;
        if ((temp_s7 == 0) || (M2C_FIELD(&sp60, s32 *, 8) = 2, sp64 = temp_a0, sp60 = (sp4 ^ sp38) + 0xCA0, (temp_a0 != 0))) {
            temp_a2 = arg0 + 0x3C40;
            var_v1_2 = 1;
            if (&sp4 != temp_a2) {
                if (temp_a2 != NULL) {
                    var_v1_2 = (M2C_FIELD(&sp4, s32 *, 8) ^ M2C_FIELD(&sp4, s32 *, 0x38)) == (M2C_FIELD(temp_a2, s32 *, 8) ^ M2C_FIELD(temp_a2, s32 *, 0x38));
                } else {
                    var_v1_2 = 0;
                }
            }
            CBinaryInputStream_ConstructFromBuffer(&sp170, 0xD8000, &B_002F7980, 0);
            if (temp_s7 != 0) {
                if (CBinaryFileStream_FOpenLocation(&sp170, &sp60) == 0) {
                    CBinaryFileStream_Destructor(&sp170, 2);
                    goto block_21;
                }
                goto block_23;
            }
block_23:
            func_001179D8(&sp170, 0x4000, 0x70000000);
            CBinaryFileStream_Pump(&sp170);
            ShutdownSwForLoad(arg0);
            InitClock(&g_2dded0);
            AddGrfusr__Fi(8);
            memset(&B_003DD490, 0, 0x4790);
            memset(&B_003DD490, 0, 0x4790);
            Sw_Construct(&B_003DD490);
            temp_s2 = (FPlayQueuedMovies(&B_002F66B0) != 0) ? 1 : (var_v1_2 == 0);
            InitCm(&B_002DDF40);
            var_a1 = temp_s3;
            M2C_ERROR(/* unknown instruction: ldl $t0, 0xb($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $t0, 0x4($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a0, 0x13($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a0, 0xc($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a2, 0x1b($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a2, 0x14($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a3, 0x23($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a3, 0x1c($sp) */);
            M2C_ERROR(/* unknown instruction: sdl $t0, 0x3c47($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $t0, 0x3c40($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a0, 0x3c4f($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a0, 0x3c48($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a2, 0x3c57($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a2, 0x3c50($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a3, 0x3c5f($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a3, 0x3c58($s4) */);
            M2C_ERROR(/* unknown instruction: ldl $t0, 0x2b($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $t0, 0x24($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a0, 0x33($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a0, 0x2c($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a2, 0x3b($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a2, 0x34($sp) */);
            M2C_ERROR(/* unknown instruction: ldl $a3, 0x43($sp) */);
            M2C_ERROR(/* unknown instruction: ldr $a3, 0x3c($sp) */);
            M2C_ERROR(/* unknown instruction: sdl $t0, 0x3c67($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $t0, 0x3c60($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a0, 0x3c6f($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a0, 0x3c68($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a2, 0x3c77($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a2, 0x3c70($s4) */);
            M2C_ERROR(/* unknown instruction: sdl $a3, 0x3c7f($s4) */);
            M2C_ERROR(/* unknown instruction: sdr $a3, 0x3c78($s4) */);
            var_v1_3 = sp;
            if ((s32) var_a1 & 7) {
                do {
                    M2C_ERROR(/* unknown instruction: ldl $t0, 0x7($v1) */);
                    M2C_ERROR(/* unknown instruction: ldr $t0, ($v1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a0, 0xf($v1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a0, 0x8($v1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a2, 0x17($v1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a2, 0x10($v1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a3, 0x1f($v1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a3, 0x18($v1) */);
                    M2C_ERROR(/* unknown instruction: sdl $t0, 0x7($a1) */);
                    M2C_ERROR(/* unknown instruction: sdr $t0, ($a1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a0, 0xf($a1) */);
                    M2C_ERROR(/* unknown instruction: sdr $a0, 0x8($a1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a2, 0x17($a1) */);
                    var_a2_2 = M2C_ERROR(/* unknown instruction: sdr $a2, 0x10($a1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a3, 0x1f($a1) */);
                    var_a3_2 = M2C_ERROR(/* unknown instruction: sdr $a3, 0x18($a1) */);
                    var_v1_3 += 0x20;
                    var_a1 += 0x20;
                } while (var_v1_3 != &sp40);
            } else {
                do {
                    var_a2_2 = M2C_FIELD(var_v1_3, s64 *, 0x10);
                    var_a3_2 = M2C_FIELD(var_v1_3, s64 *, 0x18);
                    M2C_FIELD(var_a1, s64 *, 0) = (s64) M2C_FIELD(var_v1_3, s64 *, 0);
                    M2C_FIELD(var_a1, s64 *, 8) = (s64) M2C_FIELD(var_v1_3, s64 *, 8);
                    M2C_FIELD(var_a1, s64 *, 0x10) = var_a2_2;
                    M2C_FIELD(var_a1, s64 *, 0x18) = var_a3_2;
                    var_v1_3 += 0x20;
                    var_a1 += 0x20;
                } while (var_v1_3 != &sp40);
            }
            M2C_ERROR(/* unknown instruction: ldl $t0, 0x7($v1) */);
            M2C_ERROR(/* unknown instruction: ldr $t0, ($v1) */);
            M2C_ERROR(/* unknown instruction: sdl $t0, 0x7($a1) */);
            M2C_ERROR(/* unknown instruction: sdr $t0, ($a1) */);
            M2C_FIELD(var_a1, s32 *, 8) = (s32) M2C_FIELD(var_v1_3, s32 *, 8);
            AllocSwBuffers(arg0, var_a1, var_a2_2, var_a3_2);
            if (temp_s7 != 0) {
                LoadSwFromBrx(arg0, &sp170);
                CBinaryFileStream_Close(&sp170);
            }
            func_0020E740(arg0);
            if (var_f20 > 0.0f) {
                ShowCountdownBlot(arg0, var_f20);
            }
            if ((temp_s2 != 0) || (M2C_FIELD(arg0, s32 *, 0x3BF4) & 0x40)) {
                func_0014C258();
            }
            temp_v0 = PloFindSpawn(arg0, M2C_FIELD(arg0, s32 *, 0x3C38), M2C_FIELD(arg0, s32 *, 0x3C3C));
            if (temp_v0 != NULL) {
                ActivateSpawn(temp_v0);
                M2C_FIELD(arg0, s32 *, 0x3C88) = (s32) M2C_FIELD(arg0, s32 *, 0x3C38);
                M2C_FIELD(arg0, s32 *, 0x3C8C) = (s32) M2C_FIELD(arg0, s32 *, 0x3C3C);
            }
            if ((PpoSwFocusBase(arg0) == NULL) && (PpoSwFocus(arg0) == 0) && (M2C_FIELD(arg0, s32 *, 0x3EB8) > 0)) {
                var_s3 = NULL;
                func_001D8A38(&sp1E0, "oidPoCurrent", 0);
                CRef_Destruct(&sp1E0);
                if (sp1E4 != -1) {
                    var_s3 = PloFindSwObject_thunk(arg0, 5, sp1E4, 0);
                }
                if ((var_s3 != NULL) || (var_s3 = g_2e1e40, (var_s3 != NULL)) || (var_s3 = g_2dd5bc, (var_s3 != NULL)) || (var_s3 = g_2f7900, (var_s3 != NULL))) {
                    temp_v0_2 = M2C_FIELD(var_s3, void **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(var_s3 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
                    temp_v0_3 = M2C_FIELD(var_s3, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK), 0x27C)(var_s3 + M2C_FIELD(temp_v0_3, s16 *, 0x278), 1);
                    if (temp_v0 != NULL) {
                        temp_v0_4 = M2C_FIELD(temp_v0, s32 *, 0x148);
                        if (temp_v0_4 > 0) {
                            temp_v1 = M2C_FIELD(var_s3, s32 *, 0x18);
                            var_v0 = temp_v0_4 > 0;
                            if (M2C_FIELD(temp_v0, s32 *, 0x14C) != temp_v1) {
                                var_v1_4 = temp_v0 + 0x14C;
                                var_a0_2 = 1;
loop_51:
                                var_v1_4 += 8;
                                if (var_a0_2 < temp_v0_4) {
                                    if (*var_v1_4 != temp_v1) {
                                        var_a0_2 += 1;
                                        goto loop_51;
                                    }
                                    var_v0 = var_a0_2 < temp_v0_4;
                                    goto block_56;
                                }
                                goto block_57;
                            }
block_56:
                            if (var_v0 == 0) {
                                goto block_57;
                            }
                        } else {
block_57:
                            temp_v0_5 = M2C_FIELD(var_s3, void **, 0xC);
                            M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, void *), 0x134)(var_s3 + M2C_FIELD(temp_v0_5, s16 *, 0x130), temp_v0);
                        }
                    }
                    var_s2 = 0;
                    if (M2C_FIELD(arg0, s32 *, 0x3EB8) > 0) {
                        var_s1 = arg0 + 0x3EBC;
                        do {
                            temp_s0 = *var_s1;
                            if ((temp_s0 != var_s3) && (FIsBasicDerivedFrom(temp_s0, 0x34) != 0) && (GetPoVjoyMode(temp_s0) == 0)) {
                                temp_v0_6 = M2C_FIELD(temp_s0, void **, 0xC);
                                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0x4C)(temp_s0 + M2C_FIELD(temp_v0_6, s16 *, 0x48));
                            }
                            var_s2 += 1;
                            var_s1 += 4;
                        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x3EB8));
                    }
                }
            }
            if (IEpisodeCurrent() == 0) {
                temp_v0_7 = PpoSwFocusBase(arg0);
                if ((temp_v0_7 != NULL) && (FIsBasicDerivedFrom(temp_v0_7, 0x34) != 0)) {
                    temp_a0_2 = M2C_FIELD(temp_v0_7, void **, 0xF2C);
                    if ((temp_a0_2 != NULL) && (M2C_FIELD(temp_a0_2, s32 *, 0x58) == 0)) {
                        SetBlotBlots(temp_a0_2, 1);
                    }
                }
            }
            UpdateCmLast(&B_002DDF40);
            SetResetFlag__FP2CM(&B_002DDF40);
            bevy_camera_follow_activity(&B_002DEB30, 5, 0);
            func_001C2BA8(2);
            PostLoadWipe(&B_00443740);
            if (temp_s7 == 0) {
                RunNextBootQueueEntry(&B_002E1E88);
            }
            CBinaryFileStream_Destructor(&sp170, 2);
            CStackFrame_Destructor(&sp50, 2);
        } else {
block_21:
            CStackFrame_Destructor(&sp50, 2);
        }
    }
}
