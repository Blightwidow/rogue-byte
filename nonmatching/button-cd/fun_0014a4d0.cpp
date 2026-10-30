typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0014A4D0 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ char pad80[0xB0];
};                                                  /* size = 0x130 */
#define sp40 (*(s128 *)(sp + 0x040))
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, s8 **);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
s32 FStgSwitchDone(s8 *);
s32 FSwHandsOff(M2C_UNK *);
f32 GRandInRange(f32, f32);
s32 NRandInRange(M2C_UNK, s32);
s32 PosLoWorld(...);
s32 *PpoSwFocusBase(M2C_UNK *);
f32 RadBetweenVectors__FP6VECTORN20(s128, M2C_UNK, M2C_UNK);
s32 SetVectorCylind__FP6VECTORfff(f32, f32, f32);
s32 SetVectorSphere__FP6VECTORfff(f32, f32, f32);
f32 atan2f(M2C_UNK, M2C_UNK);
void func_00208540(s8 *, s8 *);
extern M2C_UNK B_003DD490;
extern s8 *B_003E1450;
extern f32 g_2bd460;
extern M2C_UNK g_2bd468;
extern f32 g_2bd470;
extern f32 g_2bd474;
extern f32 g_2bd478;
extern f32 g_2bd47c;
extern f32 g_2dded0;
void func_0014A4D0(s8 *arg0) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s128 sp50;
    s128 sp60;
    s128 sp70;
    M2C_UNK temp_v0_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f25;
    f32 var_f22;
    s128 *var_a0;
    s128 temp_v0_2;
    s128 temp_v1_3;
    s128 var_v0;
    s32 temp_v0_3;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v1;
    s8 **var_a0_2;
    s8 **var_a2_2;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_5;
    s8 *temp_v1;
    s8 *temp_v1_4;
    s8 *var_s1;
    temp_v0 = (s8 *)(PpoSwFocusBase(&B_003DD490));
    temp_v0_2 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10), PosLoWorld(temp_v0));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
    temp_v1 = M2C_FIELD(temp_v0, s8 **, 0xC);
    asm volatile("vsub.xyzw vf1, vf1, vf2");
    asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
    sp50 = M2C_FIELD(temp_v1, s128 (**)(s8 *, s128), 0x10C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_v0_2);
    var_v1 = 1;
    asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (!(g_2bd460 < vu_1)) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
    }
    temp_f20 = g_2dded0 - M2C_FIELD(arg0, f32 *, 0x48);
    if ((GRandInRange(M2C_FIELD(&g_2bd468, f32 *, 0), M2C_FIELD(&g_2bd468, f32 *, 4)) < temp_f20) && (FSwHandsOff(&B_003DD490) == 0)) {
        if ((FIsBasicDerivedFrom(temp_v0, 0x34) != 0) && (M2C_FIELD(temp_v0, s32 *, 0x2DC) == 0x11)) {
            temp_s0 = M2C_FIELD(temp_v0, s8 **, 0x258);
            var_v0 = PosLoWorld(temp_v0);
            temp_v1_2 = M2C_FIELD(temp_s0, s32 *, 0x90);
            var_a2 = temp_v1_2;
            if (temp_v1_2 > 0) {
                var_a0 = M2C_FIELD(temp_s0, s128 **, 0x94);
                do {
                    temp_v1_3 = *var_a0;
                    s64 vu_2;
                    asm volatile("pextuw %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_v1_3));
                    s64 vu_3;
                    asm volatile("pextuw %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(var_v0));
                    if (vu_3 < vu_2) {
                        s64 vu_4;
                        asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_v1_3));
                        var_v0 = vu_4;
                    }
                    var_a2 -= 1;
                    var_a0 += 0x10;
                } while (var_a2 != 0);
            }
            goto block_40;
        }
        func_00208540(M2C_FIELD(arg0, s8 **, 0x10), temp_v0);
        return;
    }
    var_s1 = B_003E1450;
    asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
    if (var_s1 != NULL) {
        asm volatile("vmul.xy vf1, vf2, vf2");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_5;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
        temp_f25 = vu_5;
loop_17:
        if (FStgSwitchDone(var_s1) == 0) {
            temp_a0 = M2C_FIELD(var_s1, s8 **, 0xEC);
            sp60 = PosLoWorld(var_s1);
            var_f22 = g_2bd478;
            if (temp_a0 != NULL) {
                var_f22 = M2C_FIELD(temp_a0, f32 *, 0x30);
                sp60 = M2C_FIELD(temp_a0, s128 *, 0x20);
            }
            temp_v0_3 = CploFindSwObjectsByClass(&B_003DD490, 1, 0x12, var_s1, 8, (s8 **)(sp));
            var_a1 = 0;
            if (temp_v0_3 > 0) {
                var_a3 = temp_v0_3;
                var_a2_2 = (s8 **)(sp);
                var_a0_2 = (s8 **)(sp);
                do {
                    temp_v1_4 = *var_a2_2;
                    var_a3 -= 1;
                    if (M2C_FIELD(temp_v1_4, s32 *, 0xE8) & 0x17E) {
                        *var_a0_2 = temp_v1_4;
                        var_a1 += 1;
                        var_a0_2 += 4;
                    }
                    var_a2_2 += 4;
                } while (var_a3 != 0);
            }
            if (var_a1 != 0) {
                temp_s0_2 = (s8 *)(sp[NRandInRange(0, var_a1 - 1)]);
                var_f22 = M2C_FIELD(temp_s0_2, f32 *, 0xEC);
                sp60 = PosLoWorld(temp_s0_2);
            }
            asm volatile("lqc2 vf2, 0x60(%0)" : : "r"(sp));
            var_v0_2 = 1;
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf2, vf3");
            asm volatile("vmul.xyz vf1, vf1, vf1");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            s32 vu_6;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_6));
            if (!((g_2bd478 * g_2bd478) < vu_6)) {
                var_v0_2 = 0;
            }
            if (var_v0_2 == 0) {
                temp_f21 = GRandInRange(-3.1415927f, 3.1415927f);
                temp_f20_2 = GRandInRange(-3.1415927f, 3.1415927f);
                asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorSphere__FP6VECTORfff(temp_f21, temp_f20_2, GRandInRange(0.0f, var_f22))));
                asm volatile("vadd.xyzw vf3, vf1, vf2");
                asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf2, vf3, vf4");
                var_v0_3 = 1;
                asm volatile("vmul.xy vf1, vf2, vf2");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_7;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_7));
                if (!(vu_7 < temp_f25)) {
                    var_v0_3 = 0;
                }
                s32 vu_8;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_8));
                var_v0 = vu_8;
                if (var_v0_3 == 0) {
                    var_v0 = sp60;
                    s32 vu_9;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_9));
                    if (!(g_2bd47c < (fabsf(RadBetweenVectors__FP6VECTORN20(sp40, vu_9, 0)) * 57.295776f))) {
                        goto block_34;
                    }
                }
            } else {
                goto block_34;
            }
        } else {
block_34:
            var_s1 = M2C_FIELD(var_s1, s8 **, 0x174);
            if (var_s1 == NULL) {
                goto block_35;
            }
            goto loop_17;
        }
    } else {
block_35:
        asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(sp));
        var_v0_4 = 1;
        asm volatile("vmul.xy vf1, vf2, vf2");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_10;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_10));
        if (!(vu_10 < g_2bd460)) {
            var_v0_4 = 0;
        }
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
        if (var_v0_4 != 0) {
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            s32 vu_11;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_11));
            temp_v0_4 = vu_11;
            s64 vu_12;
            asm volatile("prot3w %0, %1" : "=r"(vu_12) : "r"(temp_v0_4));
            temp_f20_3 = atan2f(vu_12, temp_v0_4);
            sp70 = PosLoWorld(temp_v0);
            asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(GRandInRange(temp_f20_3 - 1.5707964f, temp_f20_3 + 1.5707964f), g_2bd470, g_2bd474)));
            asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            s32 vu_13;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_13));
            var_v0 = vu_13;
        } else {
            asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf1, vf3, vf3");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf3, Q");
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(-g_2bd470));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("vadda.xyzw ACC, vf0, vf3");
            asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
            s32 vu_14;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_14));
            var_v0 = vu_14;
        }
    }
block_40:
    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0x1010);
    temp_v0_5 = M2C_FIELD(temp_a2, s8 **, 0xC);
    s64 vu_15;
    asm volatile("por %0, %1, %2" : "=r"(vu_15) : "r"(0), "r"(var_v0));
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0xEC)(temp_a2 + M2C_FIELD(temp_v0_5, s16 *, 0xE8), vu_15, temp_a2);
    temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x10);
    func_00208540(temp_a0_2, M2C_FIELD(temp_a0_2, s8 **, 0x1010));
}
}
