typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023A1D0 {};                 /* size 0x0 */
extern s64 D_002C5A30;
s64 func_0023A1D0(void) {
    s32 temp_t0_2;
    s64 temp_t0;
    s64 var_t2;
    temp_t0_2 = M2C_FIELD((s8 *)0x10001000, s32 *, 0x10);
    var_t2 = D_002C5A30;
    if (temp_t0_2 & 0x800) {
        var_t2 += 1;
    }
    temp_t0 = temp_t0_2 & 3;
    (M2C_FIELD((s8 *)0x10001000, u32 *, 0) | (var_t2 << 0x10)) << (((temp_t0 == 0) ? 0 : 2) << temp_t0);
}
}
