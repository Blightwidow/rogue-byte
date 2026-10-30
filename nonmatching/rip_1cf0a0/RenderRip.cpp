typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RenderRip {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */

s32 FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(s8 *, s128, s8 *, s128, s128, s128, s128); /* extern */
M2C_UNK RemoveRip(s8 *);                          /* extern */

void RenderRip(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 temp_a3;

    temp_a3 = M2C_FIELD(arg0, s128 *, 0x50);
    if (FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(arg0, M2C_FIELD(arg0, s128 *, 0x70), sp, temp_a3, M2C_FIELD(arg0, s128 *, 0x40), temp_a3, M2C_FIELD(arg0, s128 *, 0x60)) == 0) {
        RemoveRip(arg0);
    }
}

}
