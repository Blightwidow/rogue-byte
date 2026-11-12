typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023A228 {};                 /* size 0x0 */
extern M2C_UNK D_002C5A30;
s32 func_0023A228(void) {
    s32 temp_a1;
    s32 temp_a2;
    temp_a2 = M2C_FIELD(&D_002C5A30, s32 *, 0x14);
    if (temp_a2 == 0) {
        return 0x80008005;
    }
    temp_a1 = temp_a2 * 0x10;
    M2C_FIELD(temp_a2, s32 *, 0x28) = 0;
    M2C_FIELD(&D_002C5A30, s32 *, 0x10) = (s32) (M2C_FIELD(&D_002C5A30, s32 *, 0x10) + 1);
    M2C_FIELD(temp_a2, s32 *, 0xC) = 0;
    M2C_FIELD(&D_002C5A30, s32 *, 0x14) = (s32) M2C_FIELD(temp_a2, s32 *, 0);
    M2C_FIELD(temp_a2, s64 *, 0x18) = 0;
    M2C_FIELD(&D_002C5A30, s32 *, 0xC) = (s32) (M2C_FIELD(&D_002C5A30, s32 *, 0xC) + 1);
    M2C_FIELD(temp_a2, s32 *, 8) = (s32) (((M2C_FIELD(&D_002C5A30, s32 *, 0xC) * 2) & 0x3FE) | 1);
    temp_a1 | M2C_FIELD(temp_a2, s32 *, 8);
}
}
