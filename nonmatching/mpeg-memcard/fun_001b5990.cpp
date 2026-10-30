typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B5990 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
void ClearVjoyPresses(s8 *, M2C_UNK);
s32 FAttachGroundTarget(s8 *, M2C_UNK, M2C_UNK);
s32 FButtonPressedWithin(s8 *, M2C_UNK, f32);
s32 FJtInFocusRange(s8 *, M2C_UNK);
s32 FMurrayAttackCanChain(s8 *);
s32 FMurrayTryGrabGuard(s8 *);
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, M2C_UNK);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void SetMurrayState(s8 *, M2C_UNK);
void SetRunBlendU(s8 *, f32);
void SetStepRadTarget(s8 *, f32);
s32 SetVectorCylind__FP6VECTORfff(f32, f32, f32, M2C_UNK);
void SolvePlainBlendWeights(s8 *, s8 *, s32);
void StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void StartMurrayAttackA(s8 *);
void StartMurrayAttackB(s8 *);
void UpdateRunBlendFootsteps(s8 *);
void func_001B5D30(s8 *, M2C_UNK);
void func_002046F0(s8 *, s32);
extern f32 D_FLT_002C08DC;
void func_001B5990(s8 *arg0) {
    f32 temp_a0_2;
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *temp_v1_2;
loop_1:
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x17F4);
    if ((temp_s0 < 3) && (temp_s0 >= 0)) {
        if (!(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & 8)) {
            if (FJtInFocusRange(arg0, 1) != 0) {
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0.1f) != 0) {
                    SetJmpState(arg0 + 0x2C0, 1, 0, 0);
                } else if (FMurrayTryGrabGuard(arg0) == 0) {
                    if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x20, 0.2f) != 0) {
                        if ((FAttachGroundTarget(arg0 + 0x4C0, 0x80, 0) == 0) && (M2C_FIELD(arg0, s32 *, 0x13EC) != 0)) {
                            M2C_FIELD(arg0, s32 *, 0x144C) = 0;
                            SetMurrayState(arg0, 4);
                        }
                    } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x80, D_FLT_002C08DC) != 0)) {
                        StartMurrayAttackA(arg0);
                    } else if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0x3E19999A) != 0) && (temp_v1 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(s8 *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x318), 3) != 0))) {
                        ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x400);
                        StartBinoc(arg0 + 0xF00, 0, 0, 0);
                    } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, D_FLT_002C08DC) != 0)) {
                        StartMurrayAttackB(arg0);
                    } else {
                        temp_f1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C);
                        if (M2C_FIELD(arg0, s32 *, 0x13D0) == 0) {
                            if (!(temp_f1 > 0.1f)) {
                                goto block_30;
                            }
                            goto block_29;
                        }
                        if (temp_f1 > 0.0f) {
block_29:
                            func_001B5D30(arg0, 2);
                        } else {
block_30:
                            func_001B5D30(arg0, 0);
                        }
                    }
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            SetMurrayState(arg0, 0);
        }
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x17F4);
    if ((temp_a0 != temp_s0) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 9)) {
        goto loop_1;
    }
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_002046F0(arg0, M2C_FIELD(arg0, s32 *, 0x10DC));
        return;
    case 2:
        func_002046F0(arg0, M2C_FIELD(arg0, s32 *, 0x10DC));
        asm volatile("lqc2 vf1, 0x1720(%0)" : : "r"(arg0));
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x150);
        asm volatile("vmul.xy vf1, vf1, vf1");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_a0_2 = vu_1;
        asm volatile("qmtc2.ni %0, vf4" : : "r"(SetVectorCylind__FP6VECTORfff(temp_a0_2, M2C_FIELD(temp_v1_2, f32 *, 0x18) + 3.1415927f, M2C_FIELD(temp_v1_2, f32 *, 0x1C) * temp_a0_2 * M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), f32 *, 0x40), 0)));
        asm volatile("sqc2 vf4, 0x190(%0)" : : "r"(arg0));
        temp_v0 = arg0 + 0x1B0;
        asm volatile("lqc2 vf3, 0x1b0(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0));
        asm volatile("vmul.xyzw vf7, vf3, vf4");
        asm volatile("vmaxw.xyzw vf8, vf0, vf0w");
        asm volatile("vmul.xyzw vf6, vf1, vf4");
        asm volatile("vmul.xyzw vf5, vf2, vf4");
        asm volatile("vadday.x ACC, vf7, vf7y");
        asm volatile("vmaddz.x vf3, vf8, vf7z");
        asm volatile("vaddax.y ACC, vf6, vf6x");
        asm volatile("vmaddz.y vf3, vf8, vf6z");
        asm volatile("vaddax.z ACC, vf5, vf5x");
        asm volatile("vmaddy.z vf3, vf8, vf5y");
        M2C_FIELD(arg0, s32 *, 0x1038) = -1;
        asm volatile("sqc2 vf3, 0x190(%0)" : : "r"(arg0));
        SolvePlainBlendWeights(arg0, arg0 + 0x16F0, M2C_FIELD(arg0, s32 *, 0x17F0));
        break;
    case 1:
        temp_s0_2 = arg0 + 0x1630;
        SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
        SetRunBlendU(temp_s0_2, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C));
        UpdateRunBlendFootsteps(temp_s0_2);
        break;
    }
}
}
