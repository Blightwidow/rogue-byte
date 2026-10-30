typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PresetJtOrbitAccel {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[0x30];
    /* 0x080 */ f32 sp80;                           /* inferred */
    /* 0x084 */ char pad84[0x1C];                   /* maybe part of sp80[8]? */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ char padB0[0x90];
};                                                  /* size = 0x140 */
M2C_UNK AddSoAcceleration(s8 *, M2C_UNK);         /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, f32, f32, f32); /* extern */
s32 LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32);  /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
extern M2C_UNK D_002BC9A8;
extern f32 D_FLT_002BC998;
extern f32 D_FLT_002BC99C;
extern f32 D_FLT_002BC9A0;
extern s128 g_2a2dc0;
extern M2C_UNK g_2dded0;
void PresetJtOrbitAccel(s8 **arg0) {
    s8 sp[0xd0] __attribute__((aligned(16)));
    M2C_UNK sp50;
    f32 sp80;
    s128 spA0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_v1_3;
    s8 *temp_a1;
    s8 *temp_s1;
    s8 *temp_v1;
    s8 *temp_v1_2;
    temp_a1 = *arg0;
    temp_s1 = M2C_FIELD(temp_a1, s8 **, 0x10DC);
    if (temp_s1 != NULL) {
        temp_v1 = M2C_FIELD(temp_a1, s8 **, 0xC);
        temp_f22 = ((D_FLT_002BC99C * D_FLT_002BC99C) / D_FLT_002BC998) + D_FLT_002BC9A0;
        temp_v1_2 = M2C_FIELD(temp_s1, s8 **, 0xC);
        spA0 = M2C_FIELD(temp_v1, s128 (**)(s8 *, s8 *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1);
        asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x10C)(temp_s1 + M2C_FIELD(temp_v1_2, s16 *, 0x108))));
        asm volatile("vsub.xyzw vf2, vf1, vf2");
        asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(*arg0)));
        asm volatile("sqc2 vf3, 0xc0(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_s1)));
        asm volatile("lqc2 vf3, 0xc0(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf3, vf3, vf1");
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vmul.xyz vf2, vf3, vf1");
        asm volatile("vaddw.x vf4, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf4, vf2z");
        asm volatile("vmulx.xyzw vf2, vf1, vf2x");
        asm volatile("vsub.xyzw vf3, vf3, vf2");
        asm volatile("vmul.xyz vf1, vf3, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf2, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
        if (vu_1 < 0.0001f) {
        } else {
            asm volatile("vdiv Q, vf0w, vf2x");
            asm volatile("vwaitq");
            asm volatile("vmulq.xyzw vf1, vf3, Q");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        }
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
        asm volatile("vopmula.xyz ACC, vf1, vf3");
        asm volatile("vopmsub.xyz vf3, vf3, vf1");
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
        temp_v1_3 = vu_2;
        asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf3, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        temp_f21 = vu_3;
        s32 vu_4;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
        s64 vu_5;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(vu_4));
        temp_f20 = vu_5 / temp_v1_3;
        GSmooth__FfffP3SMPPf(&D_002BC9A8, &sp80, temp_v1_3, D_FLT_002BC998, M2C_FIELD(&g_2dded0, f32 *, 4));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(GLimitAbs__Fff(sp80 - temp_f21, D_FLT_002BC9A0 * M2C_FIELD(&g_2dded0, f32 *, 4))));
        asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf3");
        asm volatile("vmaddx.xyzw vf1, vf1, vf2x");
        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
        LoadRotateMatrixRad(&sp50, g_2a2dc0, temp_f20 * M2C_FIELD(&g_2dded0, f32 *, 4));
        asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf5" : : "r"(M2C_FIELD(&g_2dded0, f32 *, 4)));
        asm volatile("lqc2 vf4, 0x70(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(sp));
        asm volatile("vmulax.xyz ACC, vf2, vf1x");
        asm volatile("vmadday.xyz ACC, vf3, vf1y");
        asm volatile("vmaddz.xyz vf1, vf4, vf1z");
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x90(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("vdiv Q, vf0w, vf5x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf3, vf1, Q");
        asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
        asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
        s32 vu_6;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_6));
        s64 vu_7;
        asm volatile("por %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(LimitVectorLength__FP6VECTORfT0(vu_6, temp_f22)));
        AddSoAcceleration(*arg0, vu_7);
    }
}
}
