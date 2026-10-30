typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateMurrayCarry {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
void ClearVjoyPresses(s8 *, M2C_UNK);
void DetachMurrayObject(s8 *);
s32 FButtonPressedWithin(s8 *, M2C_UNK, M2C_UNK);
s32 FGadgetAcquired(M2C_UNK);
s32 GrfbtnVjoyPressedWithin(s8 *, M2C_UNK, M2C_UNK);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void SetMurrayCarryState(s8 *, M2C_UNK);
void SetMurrayState(s8 *, M2C_UNK);
void SetRunBlendU(s8 *, f32);
void SetStepRadTarget(s8 *, f32);
void StartBinoc(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void UpdateRunBlendFootsteps(s8 *);
s32 func_00204E38(s8 *, s8 *, f32);
void UpdateMurrayCarry(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_s0;
    s8 *temp_a1;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v1;
loop_1:
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x1458);
    if ((temp_s0 < 3) && (temp_s0 >= 0)) {
        if ((int)((u64) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x13F0), s8 **, 0x180), u64 *, 0x28) >> 0x3C) & 1) {
            if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x40, 0x3DCCCCCD) == 0) {
                goto block_12;
            }
            if (FGadgetAcquired(0x12) != 0) {
                ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x40);
                SetJmpState(arg0 + 0x2C0, 0xF, 0, 0);
            } else {
block_12:
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0xA0, 0) != 0) {
                    SetMurrayState(arg0, 7);
                } else if ((FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x10, 0) != 0) && (M2C_FIELD(arg0, s32 *, 0x1438) != 0)) {
                    M2C_FIELD(arg0, s32 *, 0x143C) = 0;
                    SetMurrayState(arg0, 8);
                } else if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), 0x400, 0x3E19999A) != 0) && (temp_v1 = M2C_FIELD(arg0, s8 **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(s8 *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x318), 3) != 0))) {
                    ClearVjoyPresses(M2C_FIELD(arg0, s8 **, 0x150), 0x400);
                    StartBinoc(arg0 + 0xF00, 0, 0, 0);
                } else {
                    temp_v0 = M2C_FIELD(arg0, s8 **, 0x150);
                    temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x1C);
                    if (M2C_FIELD(arg0, s32 *, 0x1458) == 0) {
                        if (!(temp_f1 > 0.1f)) {
                            goto block_30;
                        }
                        goto block_26;
                    }
                    if (!(temp_f1 > 0.0f)) {
block_30:
                        SetMurrayCarryState(arg0, 0);
                    } else {
block_26:
                        if ((M2C_FIELD(temp_v0, s32 *, 0x30) & 8) && (FGadgetAcquired(0x12) != 0)) {
                            SetMurrayCarryState(arg0, 2);
                        } else {
                            SetMurrayCarryState(arg0, 1);
                        }
                    }
                }
            }
        } else {
            DetachMurrayObject(arg0);
            M2C_FIELD(arg0, s8 **, 0x13F0) = NULL;
            SetMurrayState(arg0, 0);
        }
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1458);
    if ((temp_a0 != temp_s0) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 5)) {
        goto loop_1;
    }
    switch (temp_a0) {                              /* irregular */
    case 2:
        SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
        temp_a1 = M2C_FIELD(arg0, s8 **, 0x1030);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C))));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
        asm volatile("vmulx.xyzw vf2, vf3, vf1x");
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
        return;
    case 1:
        temp_s0_2 = arg0 + 0x1460;
        SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
        SetRunBlendU(temp_s0_2, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C));
        UpdateRunBlendFootsteps(temp_s0_2);
        break;
    }
}
}
