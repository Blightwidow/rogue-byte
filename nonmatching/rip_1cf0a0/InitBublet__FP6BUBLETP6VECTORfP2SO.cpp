typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitBublet__FP6BUBLETP6VECTORfP2SO {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
f32 InitRip__FP3RIPP6VECTORfP2SO();
extern M2C_UNK D_002C1F40;
void InitBublet__FP6BUBLETP6VECTORfP2SO(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    InitRip__FP3RIPP6VECTORfP2SO();
    M2C_FIELD(arg0, f32 *, 0x20) = 0.33f;
    asm volatile("lqc2 vf1, (%0)" : : "r"(&D_002C1F40));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBE4CCCCD));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
    asm volatile("sqc2 vf1, 0xa0(%0)" : : "r"(arg0));
    M2C_FIELD(arg0, f32 *, 0xC4) = -8.0f;
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
}
}
