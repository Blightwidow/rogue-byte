typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MergeObstacles {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s32 sp10;                           /* inferred */
    /* 0x014 */ s8 **sp14;                        /* inferred */
    /* 0x018 */ s32 sp18;                           /* inferred */
    /* 0x01C */ s32 *sp1C;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s8 **sp60;                        /* inferred */
    /* 0x064 */ s32 *sp64;                          /* inferred */
    /* 0x068 */ char pad68[0xB8];
};                                                  /* size = 0x120 */
M2C_UNK AppendDlEntry(M2C_UNK *, s8 *);           /* extern */
M2C_UNK CStackFrame_Construct(s8 *, s8 **, s32); /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK MeasureCrv(s8 *);                         /* extern */
M2C_UNK Obstacle_JoinGroup(s8 *, s8 *);         /* extern */
M2C_UNK Obstacle_SetConvexHull(s8 *, s32, s32);   /* extern */
s8 *PobstacleGroupAlloc();                        /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
M2C_UNK RemoveDlEntry(s8 **, s8 *);             /* extern */
s32 func_001BC2F8(s8 *);                          /* extern */
extern M2C_UNK B_003E1A40;
extern M2C_UNK g_2a2dd0;
extern s32 *g_2dd2fc;
void MergeObstacles(s32 arg0, s8 **arg1, s32 arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s32 sp10;                                       /* compiler-managed */
    s8 **sp14;
    s32 sp18;
    s32 *sp1C;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s8 **sp60;
    s32 *sp64;
    s32 temp_s4;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;
    s8 **temp_v0_6;
    s8 **var_a1;
    s8 *temp_s1;
    s8 *temp_s1_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_7;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_v0_2;
    var_a1 = arg1;
    var_a2 = arg2;
    var_s3 = 0;
    sp60 = var_a1;
    sp64 = &sp10;
    if (arg0 > 0) {
        var_a2 = arg0;
        do {
            temp_v0 = *var_a1;
            var_a1 += 4;
            var_a2 -= 1;
            var_s3 = var_s3 - 1 + M2C_FIELD(temp_v0, s32 *, 0xE8);
        } while (var_a2 != 0);
    }
    var_s0 = 0;
    CStackFrame_Construct(sp, var_a1, var_a2);
    sp10 = var_s3 * 0x10;
    M2C_FIELD(sp64, s32 *, 4) = 0x10;
    temp_s4 = PvAllocStackImpl__Fi(sp64);
    if (arg0 > 0) {
        var_s2 = -0x10;
        do {
            temp_s1 = sp60[var_s0];
            temp_v1 = M2C_FIELD(temp_s1, s8 **, 0xC);
            temp_v0_2 = M2C_FIELD(temp_v1, s8 *(**)(s8 *), 0xFC)(temp_s1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            sp20 = M2C_FIELD(temp_v0_2, s128 *, 0);
            sp30 = M2C_FIELD(temp_v0_2, s128 *, 0x10);
            sp40 = M2C_FIELD(temp_v0_2, s128 *, 0x20);
            sp50 = M2C_FIELD(temp_v0_2, s128 *, 0x30);
            var_a1_2 = 0;
            if ((M2C_FIELD(temp_s1, s32 *, 0xE8) - 1) > 0) {
                var_a0 = var_s2 + temp_s4;
loop_7:
                asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                var_a0 += 0x10;
                asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
                asm volatile("lqc2 vf4, (%0)" : : "r"((var_a1_2 * 0x10) + M2C_FIELD(temp_s1, s32 *, 0xF4)));
                var_a1_2 += 1;
                asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
                var_s2 += 0x10;
                asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf3, vf4x");
                asm volatile("vmadday.xyz ACC, vf5, vf4y");
                asm volatile("vmaddaz.xyz ACC, vf2, vf4z");
                asm volatile("vmaddw.xyz vf3, vf1, vf0w");
                asm volatile("sqc2 vf3, (%0)" : : "r"(var_a0));
                if (var_a1_2 < (M2C_FIELD(temp_s1, s32 *, 0xE8) - 1)) {
                    goto loop_7;
                }
            }
            var_s0 += 1;
        } while (var_s0 < arg0);
    }
    temp_v0_3 = PobstacleGroupAlloc();
    Obstacle_SetConvexHull(temp_v0_3, var_s3, temp_s4);
    var_a0_2 = M2C_FIELD(temp_v0_3, s32 *, 0xE8) - 2;
    asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dd0));
    if (var_a0_2 >= 0) {
        var_v0 = (var_a0_2 * 0x10) + M2C_FIELD(temp_v0_3, s32 *, 0xF4);
        do {
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0));
            var_a0_2 -= 1;
            asm volatile("vadd.xyzw vf2, vf2, vf1");
            var_v0 -= 0x10;
        } while (var_a0_2 >= 0);
    }
    temp_v1_2 = M2C_FIELD(temp_v0_3, s8 **, 0xC);
    asm volatile("qmtc2.ni %0, vf1" : : "r"((f32) (M2C_FIELD(temp_v0_3, s32 *, 0xE8) - 1)));
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf2, Q");
    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
    M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK), 0xEC)(temp_v0_3 + M2C_FIELD(temp_v1_2, s16 *, 0xE8), vu_1);
    var_a0_3 = M2C_FIELD(temp_v0_3, s32 *, 0xE8) - 1;
    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
    if (var_a0_3 >= 0) {
        do {
            temp_v0_4 = var_a0_3 * 0x10;
            var_a0_3 -= 1;
            temp_v0_5 = temp_v0_4 + M2C_FIELD(temp_v0_3, s32 *, 0xF4);
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_v0_5));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("sqc2 vf1, (%0)" : : "r"(temp_v0_5));
        } while (var_a0_3 >= 0);
    }
    var_s0_2 = 0;
    if (arg0 > 0) {
        do {
            temp_s1_2 = sp60[var_s0_2];
            if (M2C_FIELD(temp_s1_2, s32 *, 0x1C0) != 0) {
                temp_v0_6 = (s8 **)(temp_s1_2 + 0x1C4);
                sp14 = temp_v0_6;
                sp10 = (s32)(temp_v0_6);
                var_s4 = var_s0_2 + 1;
                var_v1 = M2C_FIELD(temp_v0_6, s32 *, 8);
                sp18 = var_v1;
                sp1C = g_2dd2fc;
                g_2dd2fc = sp64;
                var_v0_2 = M2C_FIELD(temp_s1_2, s8 **, 0x1C4);
loop_21:
                sp14 = (s8 **)(var_v0_2 + var_v1);
                if (var_v0_2 != NULL) {
                    RemoveDlEntry(temp_v0_6, var_v0_2);
                    M2C_FIELD(var_v0_2, s32 *, 0x1D8) = 0;
                    Obstacle_JoinGroup(var_v0_2, temp_v0_3);
                    var_v1 = sp18;
                    var_v0_2 = *sp14;
                    goto loop_21;
                }
                temp_v0_7 = M2C_FIELD(temp_s1_2, s8 **, 0xC);
                M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *), 0x4C)(temp_s1_2 + M2C_FIELD(temp_v0_7, s16 *, 0x48));
                AppendDlEntry(&B_003E1A40, temp_s1_2);
                g_2dd2fc = sp1C;
            } else {
                Obstacle_JoinGroup(temp_s1_2, temp_v0_3);
                var_s4 = var_s0_2 + 1;
            }
            var_s0_2 = var_s4;
        } while (var_s0_2 < arg0);
    }
    M2C_FIELD(temp_v0_3, s32 *, 0xE4) = 1;
    MeasureCrv(temp_v0_3);
    M2C_FIELD(temp_v0_3, s32 *, 0x190) = func_001BC2F8(temp_v0_3);
    CStackFrame_Destructor(sp, 2);
}
}
