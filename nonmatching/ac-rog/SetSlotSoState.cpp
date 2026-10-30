typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSlotSoState {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[8];
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ char pad2C[0x24];                    /* maybe part of sp28[0xA]? */
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ f32 sp54;                            /* inferred */
    /* 0x58 */ char pad58[0x68];
};                                                  /* size = 0xC0 */
void ApplyAsegToHandle(s32, s8 *, s32, s8 *, M2C_UNK, M2C_UNK);
s32 ConvertAloPos(s8 *, M2C_UNK, s128);
void DecomposeSphere(M2C_UNK, f32 *, M2C_UNK, M2C_UNK);
void FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK, s128 *);
f32 GRandInRange(f32, f32);
void InvalidateXfSegment(s8 *, s32);
s32 NewEmitter(M2C_UNK);
void OnDifficultyBreak(M2C_UNK *, M2C_UNK, s32, M2C_UNK);
s32 PosLoWorld(s8 *);
f32 SMaxCrv(s32);
void SetAmbPos(s32, M2C_UNK);
void SetEmitterUnpositioned(s32, M2C_UNK);
void SetSlotSoHeading(s8 *, f32);
f32 SetSlotSoSmp(s8 *, f32);
void SetXfKind(s8 *, s32, s32);
f32 bevy_player_p5_target_1e77e8(s32);
s32 *func_001C4AF8(M2C_UNK *, M2C_UNK);
s32 func_0022C818(s8 *, s32);
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
extern s128 g_2a2da0;
extern s128 g_2a2dd0;
extern f32 g_2dded0;
void SetSlotSoState(s8 *arg0, u32 arg1) {
    s8 sp[0x58] __attribute__((aligned(16)));
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp28 (*(s32 *)(sp + 0x28))
#define sp50 (*(f32 *)(sp + 0x50))
#define sp54 (*(f32 *)(sp + 0x54))
    f32 g_2dded0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 var_f12;
    f32 var_f13;
    s128 temp_v0;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v1;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_v0_3;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x220);
    if (temp_v1 != arg1) {
        if (temp_v1 >= -1) {
            if (temp_v1 > 0) {
                if (temp_v1 < 4) {
                    if (temp_v1 >= 2) {
                        SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x1D4));
                        InvalidateXfSegment(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
                    }
                }
            } else {
                SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x1D4));
                InvalidateXfSegment(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
            }
        }
        if (arg1 < 6U) {
            switch (arg1) {
            case 0:
                temp_a2 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_a2, M2C_UNK (**)(s8 *, s128, s8 *), 0x11C)(arg0 + M2C_FIELD(temp_a2, s16 *, 0x118), g_2a2dd0, temp_a2);
                func_0022C818(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
                var_f12 = M2C_FIELD(arg0, f32 *, 0x158);
                var_f13 = M2C_FIELD(arg0, f32 *, 0x15C);
block_11:
                temp_f20 = g_2dded0;
                M2C_FIELD(arg0, f32 *, 0x228) = (f32) (temp_f20 + GRandInRange(var_f12, var_f13));
                break;
            case 1:
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK), 0x17C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x178), 4);
                var_f12 = M2C_FIELD(arg0, f32 *, 0x160);
                var_f13 = M2C_FIELD(arg0, f32 *, 0x164);
                goto block_11;
            case 2:
                temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(arg0, f32 *, 0x178) = (f32) -M2C_FIELD(arg0, f32 *, 0x178);
                asm volatile("lqc2 vf1, (%0)" : : "r"(M2C_FIELD(temp_v1_3, s32 (**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0xF8))));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
                asm volatile("vmulx.xyzw vf3, vf1, vf2x");
                asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
                DecomposeSphere(vu_1, &sp50, 0, 0);
                SetSlotSoHeading(arg0, sp50);
                temp_a2_2 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_a2_2, M2C_UNK (**)(s8 *, s128, s8 *), 0x11C)(arg0 + M2C_FIELD(temp_a2_2, s16 *, 0x118), g_2a2dd0, temp_a2_2);
block_14:
                SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 1);
                InvalidateXfSegment(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
                break;
            case 3:
                temp_a2_3 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_a2_3, M2C_UNK (**)(s8 *, s128, s8 *), 0x11C)(arg0 + M2C_FIELD(temp_a2_3, s16 *, 0x118), g_2a2dd0, temp_a2_3);
                SetSlotSoSmp(arg0, 2.0f * M2C_FIELD(arg0, f32 *, 0x21C));
                goto block_14;
            case 4:
                temp_v0 = PosLoWorld(arg0);
                temp_a0 = M2C_FIELD(arg0, s32 *, 0x170);
                sp0 = temp_v0;
                if (temp_a0 != 0) {
                    s64 vu_2;
                    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_v0));
                    FindCrvClosestPointAll(temp_a0, vu_2, 0, &sp10);
                    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    M2C_FIELD(arg0, f32 *, 0x178) = bevy_player_p5_target_1e77e8(M2C_FIELD(arg0, s32 *, 0x170));
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    temp_f20_2 = vu_3 / M2C_FIELD(arg0, f32 *, 0x1D0);
                    M2C_FIELD(arg0, f32 *, 0x22C) = (f32) ((g_2dded0 + temp_f20_2 + ((SMaxCrv(M2C_FIELD(arg0, s32 *, 0x170)) - sp54) / M2C_FIELD(arg0, f32 *, 0x1D0))) - M2C_FIELD(arg0, f32 *, 0x168));
                } else {
                    s64 vu_4;
                    asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_v0));
                    temp_a0_2 = (s8 *)(func_001C4AF8(&B_003DD490, vu_4));
                    sp10 = sp0;
                    sp0 = PosLoWorld(temp_a0_2);
                    M2C_FIELD(arg0, f32 *, 0x22C) = (f32) (g_2dded0 + 2.0f);
                }
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf1, vf2");
                asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                sp28 = 0;
                asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf3, vf3");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("qmtc2.ni %0, vf2" : : "r"(g_2a2da0));
                s32 vu_5;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
                if (!(vu_5 < 0.0001f)) {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf2, vf3, Q");
                }
                asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(arg0, f32 *, 0x1D0)));
                temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
                s32 vu_6;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_6));
                M2C_FIELD(temp_v1_4, M2C_UNK (**)(s8 *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x118), vu_6);
                temp_v1_5 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_5, M2C_UNK (**)(s8 *, M2C_UNK), 0x17C)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x178), 4);
                break;
            case 5:
                temp_v0_2 = NewEmitter(0x14);
                SetEmitterUnpositioned(temp_v0_2, 0);
                s64 vu_7;
                asm volatile("por %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(PosLoWorld(arg0)));
                SetAmbPos(temp_v0_2, vu_7);
                s64 vu_8;
                asm volatile("por %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(ConvertAloPos(arg0, 0, M2C_FIELD(arg0, s128 *, 0x240))));
                OnDifficultyBreak(&B_002DE578, vu_8, M2C_FIELD(arg0, s32 *, 0x230), -0x64);
                temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *), 0x4C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x48));
                break;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x220) = (s32) arg1;
        M2C_FIELD(arg0, f32 *, 0x224) = (f32) g_2dded0;
        if (arg1 != 2) {
            temp_v1_6 = arg0 + (arg1 * 0xC);
            ApplyAsegToHandle(M2C_FIELD(temp_v1_6, s32 *, 0x180), arg0, M2C_FIELD(temp_v1_6, s32 *, 0x184) | 1, arg0 + 0x1C4, 0, 0x3F800000);
        }
    }
}
}
