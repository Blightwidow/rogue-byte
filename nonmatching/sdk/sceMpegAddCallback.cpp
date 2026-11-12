typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceMpegAddCallback {};            /* size 0x0 */
s32 sceMpegAddCallback(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 saved_reg_gp;
    s32 *temp_v1;
    s32 temp_a1;
    s32 temp_t0;
    s32 temp_v0;
    s8 *temp_a0;
    temp_t0 = M2C_FIELD(arg0, s32 *, 0x40);
    temp_a1 = arg1 * 0xC;
    temp_v1 = (s32 *)(temp_t0 + 0xC + temp_a1);
    temp_a0 = (s8 *)(temp_t0 + temp_a1);
    temp_v0 = *temp_v1;
    *temp_v1 = arg2;
    M2C_FIELD(temp_a0, s32 *, 0x10) = arg3;
    M2C_FIELD(temp_a0, s32 *, 0x14) = (s32) saved_reg_gp;
    return temp_v0;
}
}
