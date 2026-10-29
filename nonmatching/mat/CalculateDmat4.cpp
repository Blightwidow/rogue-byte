typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CalculateDmat4 {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ M2C_UNK sp40;                        /* inferred */
    /* 0x40 */ char pad40[0x80];
};                                                  /* size = 0xC0 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp20 (*(s128 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s8 *, s32, M2C_UNK *); /* extern */
void CalculateDmat4(s32 arg0, s32 arg1, s8 *arg2) {
    s8 sp[0xC0] __attribute__((aligned(16)));
    M2C_UNK sp40;
    InvertMatrix4Affine(&sp40, arg0);
    __ml__FRC7MATRIX4T0(sp, arg1, &sp40);
    M2C_FIELD(arg2, s128 *, 0) = sp0;
    M2C_FIELD(arg2, s128 *, 0x30) = sp30;
    M2C_FIELD(arg2, s128 *, 0x10) = sp10;
    M2C_FIELD(arg2, s128 *, 0x20) = sp20;
}
}
