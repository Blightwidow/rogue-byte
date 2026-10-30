typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C41B8 {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x28];
};                                                  /* size = 0x30 */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
s32 func_001C41B8(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp0;
    s32 sp4;
    s8 *temp_a6;
    sp4 = 1;
    sp0 = 0x17;
    temp_a6 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_a6, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, s8 *), 0x1C)(arg0 + M2C_FIELD(temp_a6, s16 *, 0x18), 0xD, 0, 0, 0, sp, temp_a6);
    CRef_Destruct(sp);
    return ((0x17 ^ 0x17) == 0) ? sp4 : 1;
}
}
