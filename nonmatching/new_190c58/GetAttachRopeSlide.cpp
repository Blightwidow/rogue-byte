typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetAttachRopeSlide {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ f32 sp30;                            /* inferred */
    /* 0x34 */ f32 sp34;                            /* inferred */
    /* 0x38 */ f32 sp38;                            /* inferred */
    /* 0x3C */ char pad3C[0x14];                    /* maybe part of sp38[6]? */
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ f32 sp54;                            /* inferred */
    /* 0x58 */ char pad58[0x98];
};                                                  /* size = 0xF0 */
M2C_UNK EvaluateCrvFromU(s32, s8 *, M2C_UNK *);   /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(f32 *, f32 *, f32, f32, f32); /* extern */
f32 SFromCrvU(s32, f32);                            /* extern */
f32 SMaxCrv(s32);                                   /* extern */
s32 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
extern f32 D_FLT_002BF668;
extern M2C_UNK g_2a2dc0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2dded0;
void GetAttachRopeSlide(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp50;
    f32 sp54;
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f0;
    s8 *temp_s0;
    temp_s0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x150);
    EvaluateCrvFromU(arg1, sp, &sp10);
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
    asm volatile("vmul.xyz vf2, vf3, vf1");
    asm volatile("vaddw.x vf4, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf4, vf2z");
    asm volatile("vmulx.xyzw vf2, vf1, vf2x");
    asm volatile("vsub.xyzw vf2, vf3, vf2");
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf4, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf4, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (vu_1 < 0.0001f) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2dd0));
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf2, Q");
    }
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x150), f32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x2A0) * M2C_FIELD(temp_s0, f32 *, 0x1C), 0)));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf2, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_f22 = vu_2;
    temp_f20 = SFromCrvU(arg1, fparg0);
    sp34 = M2C_FIELD(arg0, f32 *, 0x260);
    sp30 = M2C_FIELD(arg0, f32 *, 0x2A0);
    sp38 = D_FLT_002BF668;
    GSmooth__FfffP3SMPPf(&sp30, &sp50, temp_f20, 50.0f, M2C_FIELD(&g_2dded0, f32 *, 4));
    GSmooth__FfffP3SMPPf(&sp30, &sp54, temp_f20, SMaxCrv(arg1) - 50.0f, M2C_FIELD(&g_2dded0, f32 *, 4));
    var_f0 = sp50;
    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x240(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0)));
    asm volatile("vsub.xyzw vf1, vf1, vf2");
    asm volatile("sqc2 vf1, (%0)" : : "r"(arg2));
    if (!(temp_f22 < var_f0)) {
        var_f0 = temp_f22;
        if (sp54 < temp_f22) {
            var_f0 = sp54;
        }
    }
    asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f0));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
    asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, (%0)" : : "r"(arg3));
}
}
