typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CalculateTnCrv {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0x30];
    /* 0x70 */ M2C_UNK sp70;                        /* inferred */
    /* 0x70 */ char pad70[0x30];
    /* 0xA0 */ s128 spA0;                           /* inferred */
    /* 0xB0 */ char padB0[0x40];
};                                                  /* size = 0xF0 */
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M2C_UNK *, s128, s128);
s32 ConvertAloPos(M2C_UNK, s8 *, s128);
void GetPathPosFromS(s32, s8 *, s128 *, f32);
s32 PmatLoWorld(s8 *);
s32 SetVectorCylind__FP6VECTORfff(s32, f32, f32, M2C_UNK);
extern s128 g_2a2dc0;
void CalculateTnCrv(s8 *arg0, s128 arg1, s128 *arg2, s128 *arg3) {
    s8 sp[0x90] __attribute__((aligned(16)));
    M2C_UNK sp40;
    M2C_UNK sp70;
    s128 spA0;
    f32 temp_f12;
    s32 temp_a0;
    spA0 = arg1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x10C);
    if (temp_a0 != 0) {
        GetPathPosFromS(temp_a0, sp, arg3, M2C_FIELD(arg0, f32 *, 0x140));
        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp40, *arg3, g_2a2dc0);
        asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("lqc2 vf3, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x60(%0)" : : "r"(sp));
        goto block_4;
    }
    if (M2C_FIELD(arg0, s32 *, 0x12C) != 0) {
        temp_f12 = M2C_FIELD(arg0, f32 *, 0x160);
        asm volatile("qmtc2.ni %0, vf4" : : "r"(SetVectorCylind__FP6VECTORfff(temp_a0, M2C_FIELD(arg0, f32 *, 0x140) / temp_f12, temp_f12, 0)));
        asm volatile("lqc2 vf3, 0x150(%0)" : : "r"(arg0));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vadd.xyzw vf3, vf3, vf4");
        asm volatile("vopmula.xyz ACC, vf1, vf4");
        asm volatile("vopmsub.xyz vf1, vf4, vf1");
        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf2, vf1, vf1");
        asm volatile("vaddw.x vf5, vf0, vf0w");
        asm volatile("vadday.x ACC, vf2, vf2y");
        asm volatile("vmaddz.x vf2, vf5, vf2z");
        asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
        asm volatile("vsqrt Q, vf2x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf2, vf0, Q");
        asm volatile("vdiv Q, vf0w, vf2x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf2, vf1, Q");
        asm volatile("sqc2 vf2, (%0)" : : "r"(arg3));
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp70, vu_1, g_2a2dc0);
        asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("lqc2 vf3, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
block_4:
        asm volatile("vmul.xyzw vf7, vf2, vf1");
        asm volatile("vmaxw.xyzw vf8, vf0, vf0w");
        asm volatile("vmul.xyzw vf6, vf3, vf1");
        asm volatile("vmul.xyzw vf5, vf4, vf1");
        asm volatile("vadday.x ACC, vf7, vf7y");
        asm volatile("vmaddz.x vf1, vf8, vf7z");
        asm volatile("vaddax.y ACC, vf6, vf6x");
        asm volatile("vmaddz.y vf1, vf8, vf6z");
        asm volatile("vaddax.z ACC, vf5, vf5x");
        asm volatile("vmaddy.z vf1, vf8, vf5y");
        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, (%0)" : : "r"(arg2));
        asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
        return;
    }
    asm volatile("lqc2 vf1, (%0)" : : "r"(PmatLoWorld(arg0)));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf1, Q");
    asm volatile("sqc2 vf2, (%0)" : : "r"(arg3));
    *arg2 = ConvertAloPos(0, arg0, spA0);
}
}
