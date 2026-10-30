typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalNotice_Update {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0x40];
};                                                  /* size = 0x70 */
s32 FGoalAnimDone(s32);                             /* extern */
s32 FGoalReactDone(s32);                            /* extern */
M2C_UNK GoalNotice_SetState(s8 *, M2C_UNK);       /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
s32 PpathzoneFindPos(s128, M2C_UNK);                /* extern */
M2C_UNK SetGoalTarget(s32, s8 *, s128);           /* extern */
s32 func_00175D00(s8 *);                          /* extern */
s32 func_00175FF0(s8 *);                          /* extern */
s32 func_00176060(s8 *);                          /* extern */
s32 func_0017B7F8(s32);                             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
s32 func_00209098(s8 *);                          /* extern */
M2C_UNK func_0020B140(s8 *, s8 *);              /* extern */
M2C_UNK func_002562A8(s8 *, s32);                 /* extern */
extern f32 B_FLT_003E1BE8;
extern f32 D_FLT_002BE614;
extern f32 g_2dded0;
void GoalNotice_Update(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s128 sp20;
    f32 var_f20;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u32 temp_s1;
    u32 temp_v1_2;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *var_v1;
    s8 *var_v1_2;
    func_001EEF98();
    do {
        temp_s1 = M2C_FIELD(arg0, u32 *, 0x34);
        switch (temp_s1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            if (func_001EF0A8(arg0) == 0) {
                if (func_00209098(M2C_FIELD(arg0, s8 **, 0x10)) == 0) {
                    if (func_00176060(arg0) != 0) {
                        GoalNotice_SetState(arg0, 4);
                    } else if (func_00175FF0(arg0) != 0) {
                        GoalNotice_SetState(arg0, 1);
                    } else if (func_00175D00(arg0) != 0) {
                        GoalNotice_SetState(arg0, 2);
                    } else {
                        sp20 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x30));
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
                        temp_a0 = M2C_FIELD(arg0, s8 **, 0x10);
                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf2, vf3");
                        temp_v1 = M2C_FIELD(temp_a0, s32 *, 0xFBC);
                        asm volatile("vmul.xy vf1, vf1, vf1");
                        asm volatile("vaddy.x vf1, vf1, vf1y");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        var_f20 = vu_1;
                        switch (temp_v1) {          /* switch 2; irregular */
                        case 13:                    /* switch 2 */
                            /* fallthrough */
                        case 8:                     /* switch 2 */
                            temp_v0 = M2C_FIELD(temp_a0, s8 **, 0xFC4);
                            if (temp_v0 != NULL) {
                                var_f20 /= M2C_FIELD(temp_v0, f32 *, 0x20);
                            }
                            break;
                        }
                        temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x34);
                        temp_a1 = PpathzoneFindPos(sp20, 1);
                        if (temp_v1_2 != 0) {
                            if (temp_v1_2 == 3) {
                                temp_v0_2 = M2C_FIELD(arg0, s8 **, 0x10);
                                if (var_f20 < M2C_FIELD(temp_v0_2, f32 *, 0x314)) {
                                    temp_v0_3 = M2C_FIELD(temp_v0_2, s8 **, 0xE8);
                                    var_v1 = NULL;
                                    if (temp_v0_3 != NULL) {
                                        var_v1 = M2C_FIELD(temp_v0_3, s8 **, 0xDC);
                                    }
                                    var_v0 = 0;
                                    if (var_v1 != NULL) {
                                        var_v0 = M2C_FIELD(var_v1, s32 *, 0x10);
                                    }
                                    if (temp_a1 != var_v0) {
                                        goto block_25;
                                    }
block_45:
                                    GoalNotice_SetState(arg0, 0);
                                } else {
block_25:
                                    if (M2C_FIELD(arg0, s32 *, 0x44) == temp_a1) {
                                        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                                        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(arg0));
                                        asm volatile("vsub.xyzw vf1, vf2, vf1");
                                        asm volatile("vmul.xyz vf1, vf1, vf1");
                                        asm volatile("vaddw.x vf2, vf0, vf0w");
                                        asm volatile("vadday.x ACC, vf1, vf1y");
                                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                                        var_v0_2 = 1;
                                        asm volatile("vsqrt Q, vf1x");
                                        asm volatile("vwaitq");
                                        asm volatile("vaddq.x vf1, vf0, Q");
                                        s32 vu_2;
                                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                                        if (!(D_FLT_002BE614 < vu_2)) {
                                            var_v0_2 = 0;
                                        }
                                        if (var_v0_2 != 0) {
                                            goto block_29;
                                        }
                                    } else {
block_29:
                                        M2C_FIELD(arg0, s32 *, 0x44) = temp_a1;
                                        M2C_FIELD(arg0, s128 *, 0x50) = sp20;
                                        func_002562A8(sp, temp_a1);
                                        SetGoalTarget(M2C_FIELD(arg0, s32 *, 0x18), sp, sp20);
                                    }
                                }
                            }
                        } else {
                            temp_v0_4 = M2C_FIELD(arg0, s8 **, 0x10);
                            if (!(M2C_FIELD(temp_v0_4, f32 *, 0x318) < var_f20)) {
                                temp_v0_5 = M2C_FIELD(temp_v0_4, s8 **, 0xE8);
                                var_v1_2 = NULL;
                                if (temp_v0_5 != NULL) {
                                    var_v1_2 = M2C_FIELD(temp_v0_5, s8 **, 0xDC);
                                }
                                var_v0_3 = 0;
                                if (var_v1_2 != NULL) {
                                    var_v0_3 = M2C_FIELD(var_v1_2, s32 *, 0x10);
                                }
                                if (temp_a1 != var_v0_3) {
                                    goto block_36;
                                }
                            } else {
block_36:
                                GoalNotice_SetState(arg0, 3);
                            }
                        }
                    }
                } else {
block_41:
                    GoalNotice_SetState(arg0, 5);
                }
            }
            break;
        case 1:                                     /* switch 1 */
            if (func_00209098(M2C_FIELD(arg0, s8 **, 0x10)) == 0) {
                if (func_001EF0A8(arg0) == 0) {
                    var_v0_4 = FGoalReactDone(M2C_FIELD(arg0, s32 *, 0x18));
block_44:
                    if (var_v0_4 != 0) {
                        goto block_45;
                    }
                }
            } else {
                goto block_41;
            }
            break;
        case 2:                                     /* switch 1 */
            if (func_00209098(M2C_FIELD(arg0, s8 **, 0x10)) != 0) {
                goto block_41;
            }
            if (func_001EF0A8(arg0) == 0) {
                var_v0_4 = func_0017B7F8(M2C_FIELD(arg0, s32 *, 0x18));
                goto block_44;
            }
            break;
        case 4:                                     /* switch 1 */
            if ((func_001EF0A8(arg0) == 0) && (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0)) {
                GoalNotice_SetState(arg0, -1);
            }
            break;
        case 5:                                     /* switch 1 */
            if ((func_001EF0A8(arg0) == 0) && (func_00209098(M2C_FIELD(arg0, s8 **, 0x10)) == 0)) {
                GoalNotice_SetState(arg0, 3);
            }
            break;
        }
    } while (temp_s1 != M2C_FIELD(arg0, u32 *, 0x34));
    temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x10);
    if ((M2C_FIELD(temp_a0_2, s32 *, 0xF40) != 0) && ((s32) temp_s1 < 4) && ((s32) temp_s1 >= 0) && (M2C_FIELD(temp_a0_2, f32 *, 0xF44) <= g_2dded0) && (B_FLT_003E1BE8 <= g_2dded0)) {
        func_0020B140(temp_a0_2, M2C_FIELD(arg0, s8 **, 0x30));
    }
}
}
