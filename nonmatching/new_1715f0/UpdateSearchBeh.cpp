typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSearchBeh {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
s32 FGoalAnimDone(s32);                             /* extern */
s32 GoalGoto_FArrived(s32);                         /* extern */
s32 GoalGoto_FBlocked(s32);                         /* extern */
s32 PosLoWorld(s32, s128);                          /* extern */
M2C_UNK SetGoalTarget(s32, s8 *, s128);           /* extern */
M2C_UNK SetSearchState(s8 *, M2C_UNK);            /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
M2C_UNK func_00172560(s8 *);                      /* extern */
s32 func_00172658(s8 *);                          /* extern */
s128 func_00172760(s8 *);                         /* extern */
M2C_UNK func_00172F10(s8 *);                      /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
s32 func_00209098(s32);                             /* extern */
M2C_UNK func_00209818(s32, f32);                    /* extern */
M2C_UNK func_002562A8(s8 *);                      /* extern */
extern f32 g_2dded0;
void UpdateSearchBeh(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK temp_v0;
    s128 temp_s0;
    s32 temp_s0_2;
    u32 temp_s2;
    func_001EEF98();
loop_42:
    if (func_001EF0A8(arg0) == 0) {
        temp_s2 = M2C_FIELD(arg0, u32 *, 0x30);
        switch (temp_s2) {
        case 0:
            if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
block_34:
                SetSearchState(arg0, 1);
            }
            break;
        case 1:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
                    if (func_00172658(arg0) == 0) {
                        s64 vu_1;
                        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(func_00172760(arg0)));
                        temp_s0 = vu_1;
                        func_002562A8(sp);
                        SetGoalTarget(M2C_FIELD(arg0, s32 *, 0x18), sp, temp_s0);
                        M2C_FIELD(arg0, s32 *, 0x48) = 0;
                    } else {
block_37:
                        SetSearchState(arg0, 2);
                        M2C_FIELD(arg0, s32 *, 0x48) = 0;
                    }
                } else if ((func_00172658(arg0) != 0) || (GoalGoto_FArrived(M2C_FIELD(arg0, s32 *, 0x18)) != 0) || (GoalGoto_FBlocked(M2C_FIELD(arg0, s32 *, 0x18)) != 0)) {
                    SetSearchState(arg0, 2);
                }
            } else {
block_25:
                SetSearchState(arg0, 5);
            }
            break;
        case 2:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
                    if (func_00172658(arg0) != 0) {
                        func_00172560(arg0);
                        M2C_FIELD(arg0, s32 *, 0x48) = 0;
                    } else {
block_38:
                        SetSearchState(arg0, 1);
                        M2C_FIELD(arg0, s32 *, 0x48) = 0;
                    }
                } else if (!(M2C_FIELD(arg0, f32 *, 0x38) < g_2dded0) && (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) == 0)) {
                    if (M2C_FIELD(arg0, f32 *, 0x3C) < g_2dded0) {
                        SetSearchState(arg0, 3);
                    } else {
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10), func_00172760(arg0))));
                        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf1, vf2");
                        temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0;
                        s32 vu_2;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                        temp_v0 = vu_2;
                        s64 vu_3;
                        asm volatile("prot3w %0, %1" : "=r"(vu_3) : "r"(temp_v0));
                        func_00209818(temp_s0_2, atan2f(vu_3, temp_v0));
                    }
                } else {
block_30:
                    SetSearchState(arg0, 4);
                }
            } else {
block_24:
                goto block_25;
            }
            break;
        case 3:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) != 0) {
                goto block_24;
            }
            if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
                if (func_00172658(arg0) == 0) {
                    goto block_38;
                }
                goto block_37;
            }
            if (M2C_FIELD(arg0, f32 *, 0x38) < g_2dded0) {
                goto block_30;
            }
            func_00172F10(arg0);
            break;
        case 5:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                goto block_34;
            }
            break;
        case 4:
            if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
                if (func_00172658(arg0) != 0) {
                    goto block_37;
                }
                goto block_38;
            }
            if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                SetSearchState(arg0, -1);
            }
            break;
        }
        if (M2C_FIELD(arg0, u32 *, 0x30) != temp_s2) {
            goto loop_42;
        }
    }
}
}
