typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FMurrayTryGrabGuard {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
s32 FButtonPressedWithin(s32, M2C_UNK, M2C_UNK);
s32 FCheckLm__FP2LMf(M2C_UNK *, M2C_UNK);
s32 FIsGuardInSgs(s8 *, M2C_UNK);
void GoalAnimLeap_SetState(s8 *, M2C_UNK);
s32 *GoalStack_PgoalFind(s8 *, M2C_UNK);
s32 GrfbtnVjoyPressedWithin(s32, M2C_UNK, M2C_UNK);
s32 PosLoWorld(...);
void SetMurrayAttackState(s8 *, M2C_UNK);
void SetMurrayState(s8 *, M2C_UNK);
void StartMurrayLiftGuard(s8 *, s32);
extern M2C_UNK D_002C09B0;
extern M2C_UNK D_002C09C0;
extern f32 D_FLT_002C09AC;
extern f32 D_FLT_002C09B8;
s32 FMurrayTryGrabGuard(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v0_3;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s8 *temp_a0;
    s8 *temp_v0;
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x10DC);
    var_v0 = 0;
    if (temp_a0 != NULL) {
        if ((FIsGuardInSgs(temp_a0, 0x17) != 0) && (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0xA0, 0x3E19999A) != 0)) {
            temp_v0 = (s8 *)(GoalStack_PgoalFind(M2C_FIELD(arg0, s8 **, 0x10DC) + 0x26C, 0xB1));
            if (M2C_FIELD(temp_v0, s32 *, 0x50) < 3) {
                var_v0 = 0;
                if (M2C_FIELD(temp_v0, s32 *, 0x5C) == (s32)arg0) {
                    var_s2 = 0;
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0, PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10DC)))));
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf2, vf1, vf2");
                    asm volatile("vmul.xy vf1, vf2, vf2");
                    asm volatile("vaddy.x vf1, vf1, vf1y");
                    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                    temp_v0_2 = vu_1;
                    s64 vu_2;
                    asm volatile("pextuw %0, %1, %0" : "=r"(vu_2) : "r"(0), "r"(temp_v0_2));
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    if ((vu_3 < D_FLT_002C09AC) && (FCheckLm__FP2LMf(&D_002C09B0, vu_2) != 0) && (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10DC), s32 *, 0xFEC) != 0)) {
                        var_s2 = FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x20, 0x3E19999A) != 0;
                    }
                    if (var_s2 != 0) {
                        GoalAnimLeap_SetState(temp_v0, 2);
                        StartMurrayLiftGuard(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10DC), s32 *, 0xFEC));
                        goto block_20;
                    }
                    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("vmul.xy vf1, vf2, vf2");
                    asm volatile("vaddy.x vf1, vf1, vf1y");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    var_s1 = 0;
                    s32 vu_4;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_4));
                    temp_v0_3 = vu_4;
                    s64 vu_5;
                    asm volatile("pextuw %0, %1, %0" : "=r"(vu_5) : "r"(0), "r"(temp_v0_3));
                    s32 vu_6;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_6));
                    if ((vu_6 < D_FLT_002C09B8) && (FCheckLm__FP2LMf(&D_002C09C0, vu_5) != 0) && (M2C_FIELD(arg0, s32 *, 0x180C) != 0)) {
                        var_s1 = FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x80, 0x3E19999A) != 0;
                    }
                    if (var_s1 != 0) {
                        SetMurrayState(arg0, 0xB);
                        SetMurrayAttackState(arg0, 4);
block_20:
                        var_v0 = 1;
                        /* Duplicate return node #21. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    goto block_6;
                }
                /* Duplicate return node #21. Try simplifying control flow for better match */
                return var_v0;
            }
            goto block_6;
        }
block_6:
        return 0;
    }
    return var_v0;
}
}
