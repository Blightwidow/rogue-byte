typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildFrustrum {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
void BuildFrustrum(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(arg0));
    asm volatile("qmtc2.ni %0, vf5" : : "r"(fparg0));
    asm volatile("lqc2 vf1, (%0)" : : "r"(arg0));
    asm volatile("vadda.xyzw ACC, vf0, vf1");
    asm volatile("vmaddx.xyzw vf1, vf2, vf5x");
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg0));
    asm volatile("vmul.xyz vf2, vf1, vf1");
    asm volatile("vaddw.x vf4, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf4, vf2z");
    asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, q");
    asm volatile("vdiv q, vf0w, vf2x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf2, vf1, q");
    asm volatile("qmtc2.ni %0, vf4" : : "r"(-fparg0));
    asm volatile("vopmula.xyz ACC, vf3, vf2");
    asm volatile("vopmsub.xyz vf3, vf2, vf3");
    asm volatile("sqc2 vf3, (%0)" : : "r"(arg1));
    asm volatile("qmtc2.ni %0, vf6" : : "r"(fparg1));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(arg0));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf5, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf5, vf1z");
    asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, q");
    asm volatile("sqc2 vf6, (%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf7" : : "r"(-fparg1));
    asm volatile("vdiv q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf1, vf2, q");
    asm volatile("sqc2 vf7, (%0)" : : "r"(sp));
    asm volatile("vopmula.xyz ACC, vf1, vf3");
    asm volatile("vopmsub.xyz vf1, vf3, vf1");
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(arg1));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf2, vf1, vf6x");
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(arg0));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf4, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf4, vf1z");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, q");
    asm volatile("vdiv q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf1, vf2, q");
    asm volatile("vopmula.xyz ACC, vf1, vf3");
    asm volatile("vopmsub.xyz vf1, vf3, vf1");
    asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(arg1));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf2, (%0)" : : "r"(arg0));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf2, vf1, vf7x");
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(arg0));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf4, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf4, vf1z");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, q");
    asm volatile("vdiv q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf1, vf2, q");
    asm volatile("vopmula.xyz ACC, vf3, vf1");
    asm volatile("vopmsub.xyz vf3, vf1, vf3");
    asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(arg1));
}
}
