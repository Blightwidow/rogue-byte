typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpClqEvaluate {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x38];
};                                                  /* size = 0x40 */
#define sp4 (*(f32 *)(sp + 0x04))
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK CRef_RefCoerceF32(s8 *, s32);             /* extern */
s8 *RefOpClqEvaluate(s8 *arg0, s8 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *temp_s0;
    temp_s0 = M2C_FIELD(arg2, s8 **, 4);
    CRef_RefCoerceF32(sp, (int)(arg2 + 8));
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(temp_s0, f32 *, 0) + (sp4 * (M2C_FIELD(temp_s0, f32 *, 4) + (sp4 * M2C_FIELD(temp_s0, f32 *, 8)))));
    M2C_FIELD(arg0, s32 *, 0) = 0x16;
    CRef_Destruct(sp);
    return arg0;
}
}
