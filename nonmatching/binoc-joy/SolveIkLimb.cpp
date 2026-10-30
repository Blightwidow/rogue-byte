typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef int QW __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SolveIkLimb {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ char pad70[0x20];                   /* maybe part of sp60[3]? */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0x90];                   /* maybe part of spC0[0xA]? */
    /* 0x160 */ s128 sp160;                         /* inferred */
    /* 0x170 */ char pad170[0x70];
};                                                  /* size = 0x1E0 */
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
#define sp60 (*(s128 *)(sp + 0x60))
#define sp90 (*(s128 *)(sp + 0x90))
#define spC0 (*(s128 *)(sp + 0xC0))
#define spA0 (*(s128 *)(sp + 0x0A0))
#define spB0 (*(s128 *)(sp + 0x0B0))
#define sp160 (*(s128 *)(sp + 0x160))
QW ConvertXfVec(int, int, QW);
s32 LoadRotateMatrixRad(s128 *, s128, f32);
f32 RadBetweenVectors__FP6VECTORN20(QW, QW, QW *);
f32 __as__6VECTORG9VU_VECTOR(s32, s128);
f32 acosf(f32);
extern M2C_UNK B_003DD490;
void SolveIkLimb(s32 arg0, s8 *arg1) {
    s8 sp[0x170] __attribute__((aligned(16)));
    void (*temp_a3)(s8 *, s8 *, s32, f32, f32);
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_v0_2;
    f32 var_f12;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v1;
    s8 **temp_t0;
    s8 *temp_a0;
    s8 *temp_a0_3;
    s8 *temp_s0;
    s8 *temp_s4;
    s8 *temp_v0_3;
    s8 *temp_v0_6;
    s8 *var_v1;
    temp_a0 = M2C_FIELD(arg1, s8 **, 4);
    M2C_FIELD(temp_a0, s128 *, 0) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(temp_a0, s128 *, 0x10) = (s128) M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(temp_a0, s128 *, 0x20) = (s128) M2C_FIELD(arg1, s128 *, 0x30);
    M2C_FIELD(temp_a0, s128 *, 0x30) = (s128) M2C_FIELD(arg1, s128 *, 0x40);
    temp_a0_2 = M2C_FIELD(arg1, s32 *, 0);
    temp_a1 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA0);
    asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(arg1));
    temp_a2 = temp_a0_2 + 0x40;
    temp_v0 = temp_a1 + 0x40;
    asm volatile("lqc2 vf7, 0x40(%0)" : : "r"(temp_a1));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf6, 0x30(%0)" : : "r"(temp_v0));
    asm volatile("vmulax.xyz ACC, vf7, vf3x");
    asm volatile("vmadday.xyz ACC, vf2, vf3y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf3z");
    asm volatile("vmaddw.xyz vf4, vf6, vf0w");
    asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(temp_a0_2));
    asm volatile("lqc2 vf8, 0x30(%0)" : : "r"(temp_a2));
    asm volatile("sqc2 vf4, 0x150(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0xa0(%0)" : : "r"(arg1));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_a2));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_a2));
    asm volatile("vmulax.xyz ACC, vf5, vf4x");
    asm volatile("vmadday.xyz ACC, vf2, vf4y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf4z");
    asm volatile("vmaddw.xyz vf5, vf8, vf0w");
    temp_f1 = M2C_FIELD(arg1, f32 *, 0xC0);
    asm volatile("lqc2 vf1, 0x150(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf5, vf1");
    asm volatile("sqc2 vf1, 0x160(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x160(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf1, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    temp_f2 = M2C_FIELD(arg1, f32 *, 0xC4);
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    temp_v0_2 = *(f32 *)&vu_1;
    var_f12 = (((temp_v0_2 * temp_v0_2) - (temp_f1 * temp_f1)) - (temp_f2 * temp_f2)) / (2.0f * temp_f1 * temp_f2);
    if (var_f12 < -1.0f) {
        var_f12 = -1.0f;
    } else if (var_f12 > 1.0f) {
        var_f12 = 1.0f;
    }
    temp_s4 = arg1 + 0x10;
    LoadRotateMatrixRad((s128 *)(sp), M2C_FIELD(arg1, s128 *, 0x90), acosf(var_f12) - M2C_FIELD(arg1, f32 *, 0xC8));
    asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(arg1));
    temp_v0_3 = arg1 + 0x50;
    asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
    temp_s0 = M2C_FIELD(arg1, s8 **, 8);
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf5, vf2y");
    asm volatile("vmaddz.xyz vf2, vf4, vf2z");
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_3));
    asm volatile("vmulax.xyz ACC, vf3, vf1x");
    asm volatile("vmadday.xyz ACC, vf5, vf1y");
    asm volatile("vmaddz.xyz vf1, vf4, vf1z");
    asm volatile("sqc2 vf1, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x60(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_v0_3));
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf5, vf2y");
    asm volatile("vmaddz.xyz vf3, vf4, vf2z");
    asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x80(%0)" : : "r"(sp));
    __as__6VECTORG9VU_VECTOR((int)(temp_s0 + 0x30), M2C_FIELD(arg1, s128 *, 0x80));
    M2C_FIELD(temp_s0, s128 *, 0) = sp30;
    M2C_FIELD(temp_s0, s128 *, 0x10) = sp40;
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(temp_s0, s128 *, 0x20) = sp50;
    M2C_FIELD(temp_s0, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0;
    var_v1 = M2C_FIELD(arg1, s8 **, 0xC);
    temp_v0_4 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA0);
    asm volatile("lqc2 vf5, 0xb0(%0)" : : "r"(arg1));
    if ((s32)var_v1 != temp_v0_4) {
        asm volatile("lqc2 vf4, (%0)" : : "r"(var_v1));
loop_6:
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(var_v1));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(var_v1));
        asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(var_v1));
        var_v1 = M2C_FIELD(var_v1, s8 **, 0xA0);
        asm volatile("vmulax.xyz ACC, vf4, vf5x");
        asm volatile("vmadday.xyz ACC, vf3, vf5y");
        asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
        asm volatile("vmaddw.xyz vf5, vf1, vf0w");
        if ((s32)var_v1 != temp_v0_4) {
            asm volatile("lqc2 vf4, (%0)" : : "r"(var_v1));
            goto loop_6;
        }
    }
    temp_v1 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA0);
    temp_v0_5 = temp_v1 + 0x40;
    asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(temp_v1));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(temp_v0_5));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0_5));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0_5));
    asm volatile("vmulax.xyz ACC, vf4, vf5x");
    asm volatile("vmadday.xyz ACC, vf2, vf5y");
    asm volatile("vmaddaz.xyz ACC, vf1, vf5z");
    asm volatile("vmaddw.xyz vf5, vf3, vf0w");
    asm volatile("lqc2 vf1, 0x150(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf5, vf1");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_f20 = RadBetweenVectors__FP6VECTORN20(vu_2, sp160, &sp30);
    asm volatile("qmtc2.ni %0, vf1" : : "r"(ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA0), sp30)));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf3, vf1, Q");
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
    LoadRotateMatrixRad(&sp90, vu_3, temp_f20);
    temp_t0 = M2C_FIELD(arg1, s8 ***, 0xD0);
    sp40 = sp90;
    sp50 = spA0;
    sp60 = spB0;
    if (temp_t0 != NULL) {
        temp_v0_6 = *temp_t0;
        temp_a3 = M2C_FIELD(temp_v0_6, void (**)(s8 *, s8 *, s32, f32, f32), 0x14);
        temp_a3((s8 *)temp_t0 + M2C_FIELD(temp_v0_6, s16 *, 0x10), arg1 + 0xCC, 0, *M2C_FIELD(arg1, f32 **, 0xD4), 0.0f);
    }
    asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA0), sp160)));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf4, vf2, Q");
    s32 vu_4;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_4));
    LoadRotateMatrixRad(&spC0, vu_4, M2C_FIELD(arg1, f32 *, 0xCC));
    asm volatile("lqc2 vf9, 0xc0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf6, 0xd0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf7, 0xe0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf9, vf2x");
    asm volatile("vmadday.xyz ACC, vf6, vf2y");
    asm volatile("vmaddz.xyz vf2, vf7, vf2z");
    asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf9, vf3x");
    asm volatile("vmadday.xyz ACC, vf6, vf3y");
    asm volatile("vmaddz.xyz vf3, vf7, vf3z");
    asm volatile("lqc2 vf8, 0x20(%0)" : : "r"(temp_s4));
    asm volatile("vmulax.xyz ACC, vf9, vf1x");
    asm volatile("vmadday.xyz ACC, vf6, vf1y");
    asm volatile("vmaddz.xyz vf1, vf7, vf1z");
    asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(arg1));
    asm volatile("vmulax.xyz ACC, vf2, vf8x");
    asm volatile("vmadday.xyz ACC, vf3, vf8y");
    asm volatile("vmaddz.xyz vf8, vf1, vf8z");
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_s4));
    asm volatile("vmulax.xyz ACC, vf2, vf5x");
    asm volatile("vmadday.xyz ACC, vf3, vf5y");
    asm volatile("vmaddz.xyz vf5, vf1, vf5z");
    asm volatile("sqc2 vf2, 0x120(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf2, vf4x");
    asm volatile("vmadday.xyz ACC, vf3, vf4y");
    asm volatile("vmaddz.xyz vf4, vf1, vf4z");
    asm volatile("sqc2 vf3, 0x130(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x140(%0)" : : "r"(sp));
    temp_a0_3 = M2C_FIELD(arg1, s8 **, 4);
    asm volatile("sqc2 vf4, 0xb0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf8, 0xc0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf9, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf6, 0x80(%0)" : : "r"(sp));
    asm volatile("sqc2 vf7, 0x90(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0xf0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x100(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, 0x110(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, 0x120(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, 0xa0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0x130(%0)" : : "r"(sp));
    asm volatile("sqc2 vf8, 0x140(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, (%0)" : : "r"(temp_a0_3));
    M2C_FIELD(temp_a0_3, s128 *, 0x10) = spB0;
    M2C_FIELD(temp_a0_3, s32 *, 0xC) = 0;
    M2C_FIELD(temp_a0_3, s128 *, 0x20) = spC0;
    M2C_FIELD(temp_a0_3, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_a0_3, s32 *, 0x1C) = 0;
    temp_v0_7 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_7;
    M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 *, 0xA4) = temp_v0_7;
    M2C_FIELD(M2C_FIELD(arg1, s8 **, 8), s32 *, 0xA4) = temp_v0_7;
}
}
