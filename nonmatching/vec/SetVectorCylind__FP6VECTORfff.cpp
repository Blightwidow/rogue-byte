typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetVectorCylind__FP6VECTORfff {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x28];
};                                                  /* size = 0x40 */
M2C_UNK CalculateSinCos__FfPfT1(f32 *, f32 *);      /* extern */
s32 SetVectorCylind__FP6VECTORfff(f32 fparg1, f32 fparg2) {
    f32 sp10;
    f32 sp14;
    CalculateSinCos__FfPfT1(&sp10, &sp14);
    s64 vu_1;
    asm volatile("pextlw %0, %1, %0" : "=r"(vu_1) : "r"(sp10 * fparg1), "r"(sp14 * fparg1));
    s64 vu_2;
    asm volatile("pcpyld %0, %1, %0" : "=r"(vu_2) : "r"(fparg2), "r"(vu_1));
    s64 vu_3;
    asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(vu_2));
    return vu_3;
}
}
