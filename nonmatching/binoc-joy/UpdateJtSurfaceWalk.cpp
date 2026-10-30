typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJtSurfaceWalk {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ char pad30[0xC];
    /* 0x03C */ s32 sp3C;                           /* inferred */
    /* 0x040 */ char pad40[0xC];                    /* maybe part of sp3C[4]? */
    /* 0x04C */ s32 sp4C;                           /* inferred */
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[0x10];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x30];
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s32 spD0;                           /* inferred */
    /* 0x0D4 */ char padD4[0x8C];                   /* maybe part of spD0[0x24]? */
    /* 0x160 */ M2C_UNK sp160;                      /* inferred */
    /* 0x160 */ char pad160[0x30];
    /* 0x190 */ M2C_UNK sp190;                      /* inferred */
    /* 0x190 */ char pad190[0x30];
    /* 0x1C0 */ M2C_UNK sp1C0;                      /* inferred */
    /* 0x1C0 */ char pad1C0[0x60];
    /* 0x220 */ s128 sp220;                         /* inferred */
    /* 0x230 */ s128 sp230;                         /* inferred */
    /* 0x240 */ s128 sp240;                         /* inferred */
    /* 0x250 */ M2C_UNK *sp250;                     /* inferred */
    /* 0x254 */ char pad254[0xCC];
};                                                  /* size = 0x320 */
#define spC0 (*(s128 *)(sp + 0x0C0))
#define sp230 (*(s128 *)(sp + 0x230))
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, s128);
void InvertMatrix3(M2C_UNK *, s8 *);
s32 PmatLoWorld(s8 *, s128);
s32 PosLoWorld();
s32 PosSmooth(s128, s128, M2C_UNK *, s128 *, f32);
void SetJtState(s8 *, M2C_UNK, M2C_UNK);
void SmoothMatrix(s32, s8 *, M2C_UNK *, M2C_UNK, f32);
void SolvePlainBlendWeights(s8 *, s8 *, s8 *);
void Spire_FindClosestPoint(s32, M2C_UNK, s8 *, s8 *);
f32 __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);
void func_001856B8(s32, s32 *);
void func_001856C0(s32, s32 *, M2C_UNK, M2C_UNK *, M2C_UNK);
s32 func_00185A80(s32, s32 *, M2C_UNK);
extern M2C_UNK D_002BE920;
extern M2C_UNK D_002BE930;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;
extern M2C_UNK g_2ddfa0;
void UpdateJtSurfaceWalk(s8 *arg0) {
    s32 unksp2C;
    s32 unkspB4;
    s32 unkspB8;
    s8 sp[0xa0] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s128 sp20;
    s32 sp3C;
    s32 sp4C;
    M2C_UNK sp50;
    M2C_UNK sp60;
    s128 sp90;
    s128 spA0;
    s128 spB0;                                      /* compiler-managed */
    s32 spD0;
    M2C_UNK sp160;
    M2C_UNK sp190;
    M2C_UNK sp1C0;
    s128 sp220;
    s128 sp240;
    M2C_UNK *sp250;
    M2C_UNK *var_v0;
    M2C_UNK temp_a2_2;
    s128 temp_v0;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_v1_2;
    s8 *temp_a2;
    s8 *temp_s5;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1;
    s8 *var_s2;
    s8 *var_v1;
    temp_v0 = PosLoWorld();
    sp220 = temp_v0;
    temp_a2 = arg0 + 0x1F1C;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
    Spire_FindClosestPoint(M2C_FIELD(arg0, s32 *, 0x1F18), vu_1, temp_a2, temp_a2);
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x220(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf3, vf1, vf2");
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf4, vf0, Q");
    asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
    asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_2));
    if (vu_2 < 0.0001f) {
        asm volatile("vmove.xyzw vf2, vf1");
    } else {
        asm volatile("vdiv Q, vf0w, vf4x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf2, vf3, Q");
    }
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    temp_s5 = arg0 + 0x1B0;
    var_s2 = arg0 + 0x1F30;
    var_s4 = 2;
    asm volatile("qmtc2.ni %0, vf3" : : "r"(-M2C_FIELD(arg0, f32 *, 0x1F30)));
    asm volatile("vadda.xyzw ACC, vf0, vf1");
    asm volatile("vmaddx.xyzw vf4, vf2, vf3x");
    asm volatile("sqc2 vf4, 0x230(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(sp));
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&spA0, vu_3, g_2a2dc0);
    __as__6VECTORG9VU_VECTOR(&sp50, sp230);
    sp250 = &sp160;
    sp20 = spA0;
    M2C_FIELD(&sp20, s128 *, 0x10) = spB0;
    M2C_FIELD(&sp20, s128 *, 0x20) = spC0;
    sp4C = 0;
    sp3C = 0;
    unksp2C = 0;
    M2C_FIELD(&sp20, f32 *, 0x3C) = 1.0f;
    do {
        asm volatile("lqc2 vf5, (%0)" : : "r"(var_s2));
        asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf4, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
        asm volatile("vmaddw.xyz vf6, vf1, vf0w");
        var_s2 += 0x10;
        var_s4 -= 1;
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_4));
        Spire_FindClosestPoint(M2C_FIELD(arg0, s32 *, 0x1F18), vu_4, arg0 + 0x1F1C, NULL);
    } while (var_s4 >= 0);
    asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf1, vf3");
    asm volatile("vsub.xyzw vf2, vf2, vf3");
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf3, vf1, Q");
    var_s4_2 = 2;
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp90, vu_5, g_2a2dc0);
    M2C_FIELD(arg0, s128 *, 0x1D0) = spB0;
    M2C_FIELD(arg0, s128 *, 0x1B0) = sp90;
    M2C_FIELD(arg0, s128 *, 0x1C0) = spA0;
    SmoothMatrix(PmatLoWorld(arg0, sp90), temp_s5, &D_002BE920, 0, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x120), sp90);
    PosSmooth(sp220, sp230, &D_002BE930, &spA0, M2C_FIELD(&g_2dded0, f32 *, 4) * 0.5f);
    asm volatile("lqc2 vf5, 0x230(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x1b0(%0)" : : "r"(arg0));
    var_v1 = arg0 + 0x1F30;
    var_v0 = &sp160;
    do {
        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
        var_s4_2 -= 1;
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_s5));
        var_v1 += 0x10;
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_s5));
        asm volatile("vmulax.xyz ACC, vf4, vf1x");
        asm volatile("vmadday.xyz ACC, vf3, vf1y");
        asm volatile("vmaddz.xyz vf1, vf2, vf1z");
        asm volatile("vadd.xyzw vf1, vf5, vf1");
        asm volatile("sqc2 vf1, (%0)" : : "r"(var_v0));
        var_v0 += 0x10;
    } while (var_s4_2 >= 0);
    func_001856B8(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0);
    func_001856C0(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0, 3, sp250, 0x41200000);
    temp_v0_3 = M2C_FIELD(arg0, s8 **, 0x150);
    if (M2C_FIELD(temp_v0_3, f32 *, 0x1C) > 0.0f) {
        spB0 = 0.0f;
        unkspB8 = M2C_FIELD(temp_v0_3, M2C_UNK32 *, 0x14);
        unkspB4 = -M2C_FIELD(temp_v0_3, f32 *, 0x10);
        InvertMatrix3(&sp1C0, temp_s5);
        asm volatile("lqc2 vf3, 0x1d0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x1e0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf7, 0x20(%0)" : : "r"(&g_2ddfa0));
        asm volatile("lqc2 vf6, (%0)" : : "r"(&g_2ddfa0));
        asm volatile("lqc2 vf5, 0x1c0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(&g_2ddfa0));
        asm volatile("vmulax.xyz ACC, vf5, vf7x");
        asm volatile("vmadday.xyz ACC, vf3, vf7y");
        asm volatile("vmaddz.xyz vf7, vf2, vf7z");
        asm volatile("vmulax.xyz ACC, vf5, vf6x");
        asm volatile("vmadday.xyz ACC, vf3, vf6y");
        asm volatile("vmaddz.xyz vf6, vf2, vf6z");
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf5, vf4x");
        asm volatile("vmadday.xyz ACC, vf3, vf4y");
        asm volatile("vmaddz.xyz vf5, vf2, vf4z");
        asm volatile("sqc2 vf6, 0x190(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf6, vf1x");
        asm volatile("vmadday.xyz ACC, vf5, vf1y");
        asm volatile("vmaddz.xyz vf1, vf7, vf1z");
        asm volatile("sqc2 vf5, 0x1a0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
        spB0 = 0.0f;
        asm volatile("sqc2 vf7, 0x1b0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0xb0(%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C)));
        asm volatile("sqc2 vf6, 0x1f0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0x200(%0)" : : "r"(sp));
        asm volatile("sqc2 vf7, 0x210(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0xc0(%0)" : : "r"(sp));
        s32 vu_6;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_6));
        if (vu_6 < 0.0001f) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dc0));
        } else {
            asm volatile("vdiv Q, vf0w, vf1x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf3, Q");
        }
        asm volatile("vmulx.xyzw vf1, vf1, vf2x");
        asm volatile("lqc2 vf2, 0x1e40(%0)" : : "r"(arg0));
        asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x1e60(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(unkspB4));
        asm volatile("qmtc2.ni %0, vf4" : : "r"(unkspB8));
        asm volatile("vmulax.xyzw ACC, vf2, vf3x");
        asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1F10), s32 *, 0x78)));
        asm volatile("sqc2 vf3, 0xc0(%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, 0xc0(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf2, vf1x");
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
        asm volatile("sqc2 vf1, 0xc0(%0)" : : "r"(sp));
    } else {
        temp_v0_4 = arg0 + 0x190;
        M2C_FIELD(temp_v0_4, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_v0_4, f32 *, 8) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x190) = 0.0f;
    }
    if (spD0 > 0) {
        sp240 = 0xBF800000;
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
        asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
        asm volatile("vmulx.xyzw vf1, vf1, vf2x");
        asm volatile("lqc2 vf4, 0x1b0(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_s5));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_s5));
        asm volatile("vmulax.xyz ACC, vf4, vf1x");
        asm volatile("vmadday.xyz ACC, vf3, vf1y");
        asm volatile("vmaddz.xyz vf5, vf2, vf1z");
        s32 vu_7;
        asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_7));
        temp_a2_2 = vu_7;
        spB0 = 0xBF800000;
        asm volatile("qmtc2.ni %0, vf2" : : "r"(func_00185A80(M2C_FIELD(arg0, s32 *, 0x1F18), &spD0, temp_a2_2)));
        asm volatile("sqc2 vf2, 0x260(%0)" : : "r"(sp));
        InvertMatrix3(&sp190, temp_s5);
        asm volatile("lqc2 vf6, 0x240(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x260(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x190(%0)" : : "r"(sp));
        asm volatile("vmulx.xyzw vf2, vf2, vf6x");
        asm volatile("lqc2 vf3, 0x1a0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x1b0(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf4, vf2x");
        asm volatile("vmadday.xyz ACC, vf3, vf2y");
        asm volatile("vmaddz.xyz vf2, vf1, vf2z");
        s32 vu_8;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_8));
        spB0 = vu_8;
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
    }
    asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(arg0));
    var_v1_2 = 0;
    asm volatile("vmul.xyz vf1, vf1, vf1");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    s32 vu_9;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_9));
    if ((vu_9 > 1.0f) || (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C) != 0.0f)) {
        var_v1_2 = 1;
    }
    if (var_v1_2 != 0) {
        SetJtState(arg0, 0x15, 0xB);
        SolvePlainBlendWeights(arg0, arg0 + 0x1E10, M2C_FIELD(arg0, s8 **, 0x1F10));
        asm volatile("lqc2 vf2, 0x190(%0)" : : "r"(arg0));
        asm volatile("qmtc2.ni %0, vf5" : : "r"(0xBF800000));
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        asm volatile("lqc2 vf3, 0x1b0(%0)" : : "r"(arg0));
        asm volatile("vmulx.xyzw vf2, vf2, vf5x");
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_s5));
        asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(temp_s5));
        asm volatile("vmulax.xyz ACC, vf3, vf2x");
        asm volatile("vmadday.xyz ACC, vf1, vf2y");
        asm volatile("vmaddz.xyz vf2, vf4, vf2z");
        asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
        asm volatile("vadd.xyzw vf3, vf1, vf2");
        asm volatile("sqc2 vf5, 0xb0(%0)" : : "r"(sp));
        s32 vu_10;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_10));
        M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x118), vu_10);
        return;
    }
    SetJtState(arg0, 0x15, 0xA);
    temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x118), spA0);
}
}
