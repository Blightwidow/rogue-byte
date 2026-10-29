typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ApplyXfmProxy {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0x20];
};                                                  /* size = 0x60 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp10 (*(s128 *)(sp + 0x10))
#define sp20 (*(s128 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
M2C_UNK InvalidateXfmMatWorld(s8 *, s128, s128);  /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s8 *, s32);           /* extern */
void ApplyXfmProxy(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    M2C_FIELD(arg0, s128 *, 0x60) = sp0;
    __ml__FRC7MATRIX4T0(sp, (int)(arg0 + 0x60));
    M2C_FIELD(arg0, s128 *, 0x70) = sp10;
    M2C_FIELD(arg0, s128 *, 0x80) = sp20;
    M2C_FIELD(arg0, s128 *, 0x90) = sp30;
    InvalidateXfmMatWorld(arg0, sp30, sp0);
}
}
