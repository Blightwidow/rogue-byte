typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_player_p5_states_18bce0 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0x10];
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x6C];
};                                                  /* size = 0xC0 */
void EnsureAloSfx__FP3ALO(s8 *);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
s32 FMatchJtXmg(s8 *, s8 *, s32);
void FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(s128, s128, s128, s128, s8 *, f32 *, M2C_UNK *);
void FindCrvClosestPointFromS(s8 *, s128, M2C_UNK, s128 *, M2C_UNK, M2C_UNK, M2C_UNK, f32);
s32 PosLoWorld(s8 *);
void RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(s8 *, s32, s32, s32, s8 *, f32);
void SetJtState(s8 *, M2C_UNK, M2C_UNK);
void SetRunBlendU(s8 *, M2C_UNK);
void SetStepRadTarget(s8 *, f32);
void SolvePlainBlendWeights(s8 *, s8 *, s32);
void UpdateJt();
void UpdateJtBalance(s8 *);
void UpdateJtHangPose(s8 *);
void UpdateJtRide(s8 *);
void UpdateJtStand__FP2JT(s8 *);
void UpdateJtSurfaceWalk(s8 *);
void UpdateRunBlendFootsteps(s8 *);
void bevy_player_input_from_pad_cm(s8 *);
extern s32 D_002BF3D4;
extern s32 D_002BF3D8;
extern f32 D_FLT_002BF3DC;
void bevy_player_p5_states_18bce0(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    s128 sp30;
    M2C_UNK sp40;
    f32 sp50;
    s128 *var_s0;
    s128 *var_s1;
    s128 *var_s1_2;
    s128 temp_v0;
    s32 temp_a3;
    s32 var_s2;
    s32 var_s2_2;
    u32 temp_v1;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *temp_s2;
    s8 *temp_s4;
    s8 *temp_v1_2;
    s8 *var_s0_2;
    UpdateJt();
    if ((int)((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        if (M2C_FIELD(arg0, s8 **, 0x150) != NULL) {
            bevy_player_input_from_pad_cm(arg0);
        }
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x18C8);
        switch (temp_v1) {
        case 1:
            temp_s0 = arg0 + 0x1320;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
            SetRunBlendU(temp_s0, 0x3F800000);
            UpdateRunBlendFootsteps(temp_s0);
            asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(D_002BF3D4));
            asm volatile("vmulx.xyzw vf1, vf1, vf2x");
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(arg0));
            break;
        case 5:
            if (M2C_FIELD(arg0, s32 *, 0x18D0) == 5) {
                SolvePlainBlendWeights(arg0, arg0 + 0x13D0, M2C_FIELD(arg0, s32 *, 0x14D0));
                asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(D_002BF3D8));
                asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("vmulx.xyzw vf1, vf1, vf2x");
                asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(arg0));
                M2C_FIELD(arg0, f32 *, 0x180) = 1.0f;
            }
            break;
        case 10:
            SolvePlainBlendWeights(arg0, arg0 + 0x1AC0, M2C_FIELD(arg0, s32 *, 0x1BC0));
            break;
        case 0:
            UpdateJtStand__FP2JT(arg0);
            break;
        case 3:
            UpdateJtHangPose(arg0);
            break;
        case 12:
            UpdateRunBlendFootsteps(arg0 + 0x1C30);
            break;
        case 21:
            UpdateJtSurfaceWalk(arg0);
            break;
        case 22:
            UpdateJtRide(arg0);
            break;
        case 24:
            temp_a3 = M2C_FIELD(arg0, s32 *, 0x19F0);
            if (temp_a3 != 0) {
                temp_s2 = arg0 + 0x1520;
                temp_s1 = arg0 + 0x1620;
                RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(arg0, M2C_FIELD(arg0, s32 *, 0x19D8), M2C_FIELD(arg0, s32 *, 0x19E0), temp_a3, temp_s2, D_FLT_002BF3DC);
                RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(arg0, M2C_FIELD(arg0, s32 *, 0x19D4), M2C_FIELD(arg0, s32 *, 0x19DC), M2C_FIELD(arg0, s32 *, 0x19F4), temp_s1, D_FLT_002BF3DC);
                FMatchJtXmg(arg0, temp_s2, M2C_FIELD(arg0, s32 *, 0x19F0));
                FMatchJtXmg(arg0, temp_s1, M2C_FIELD(arg0, s32 *, 0x19F4));
            }
            break;
        }
        EnsureAloSfx__FP3ALO(arg0);
        if (M2C_FIELD(arg0, s32 *, 0x18D8) == 0) {
            var_s1 = &sp10;
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x1854), 0xB) != 0) {
                temp_s4 = M2C_FIELD(arg0, s8 **, 0x1854);
                var_s0 = (s128 *)(arg0 + 0x1890);
                var_s2 = 2;
                do {
                    FindCrvClosestPointFromS(temp_s4, *var_s0, 0, var_s1, 0, 0, 0, M2C_FIELD(arg0, f32 *, 0x1858));
                    var_s1 += 0x10;
                    var_s2 -= 1;
                    var_s0 += 0x10;
                } while (var_s2 >= 0);
                goto block_24;
            }
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x1854), 0x13) != 0) {
                temp_v0 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x1854));
                sp10 = temp_v0;
                sp30 = temp_v0;
                sp20 = temp_v0;
block_24:
                var_s2_2 = 1;
                if (M2C_FIELD(arg0, s32 *, 0x1880) > 1) {
                    var_s1_2 = &sp10;
                    var_s0_2 = arg0 + 0x18A0;
loop_26:
                    FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(M2C_FIELD(var_s0_2, s128 *, -0x10), M2C_FIELD(var_s0_2, s128 *, 0), M2C_FIELD(var_s1_2, s128 *, 0), M2C_FIELD(var_s1_2, s128 *, 0x10), sp, &sp50, &sp40);
                    if (!(sp50 < M2C_FIELD(arg0, f32 *, 0x19AC))) {
                        var_s2_2 += 1;
                        var_s1_2 += 0x10;
                        var_s0_2 += 0x10;
                        if (var_s2_2 < M2C_FIELD(arg0, s32 *, 0x1880)) {
                            goto loop_26;
                        }
                    } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x1854), 0x13) == 0) {
                        M2C_FIELD(arg0, s8 **, 0xF5C) = (s8 *) M2C_FIELD(arg0, s8 **, 0x1854);
                        M2C_FIELD(arg0, f32 *, 0xF60) = (f32) M2C_FIELD(arg0, f32 *, 0x1858);
                        SetJtState(arg0, 8, -1);
                    } else {
                        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x1854);
                        M2C_FIELD(arg0, s8 **, 0x18C4) = temp_v1_2;
                        if (M2C_FIELD(temp_v1_2, s32 *, 0x124) != 3) {
                            SetJtState(arg0, 3, 1);
                        } else {
                            SetJtState(arg0, 0x16, -1);
                        }
                    }
                }
            }
        }
        UpdateJtBalance(arg0);
    }
}
}
