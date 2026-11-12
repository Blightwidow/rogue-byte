typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0023D338 {};                 /* size 0x0 */
s32 func_0023D338(s8 *arg0, s32 arg2) {
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a3;
    u32 temp_v1;
    u64 var_a1;
    u64 var_a1_2;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0);
    var_a3 = 0;
    var_a1 = M2C_FIELD(arg0, u64 *, 0x10);
    if (temp_v1 < 2U) {
        var_a3 = 0x7FF;
        var_a1 |= 0x8000L << 0x24;
    } else if ((temp_v1 ^ 4) != 0) {
        if ((temp_v1 ^ 2) == 0) {
            var_a1 = 0;
        } else if (var_a1 != 0) {
            temp_v1_2 = M2C_FIELD(arg0, s32 *, 8);
            if (temp_v1_2 < -0x3FE) {
                temp_v0 = -0x3FE - temp_v1_2;
                var_a1_2 = var_a1 >> temp_v0;
                if (temp_v0 >= 0x39) {
                    var_a1_2 = 0;
                }
                goto block_17;
            }
            var_a3 = temp_v1_2 + 0x3FF;
            if (temp_v1_2 >= 0x400) {
                goto block_10;
            }
            if ((var_a1 & 0xFF) != 0x80) {
                var_a1_2 = var_a1 + 0x7F;
            } else {
                var_a1_2 = (var_a1 & 0x100) ? (var_a1 + 0x80) : var_a1;
            }
            if ((u64) (-1U >> 3) < var_a1_2) {
                var_a1_2 = var_a1_2 >> 1;
                var_a3 += 1;
            }
block_17:
            var_a1 = var_a1_2 >> 8;
        }
    } else {
block_10:
        var_a3 = 0x7FF;
        var_a1 = 0;
    }
    return (((((arg2 & (0xFFF0L << 0x30)) | (var_a1 & (-1U >> 0xC))) & ((((0x800FFFFF << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((var_a3 & 0x7FF) << 0x34)) & (-1U >> 1)) | ((s64) M2C_FIELD(arg0, s32 *, 4) << 0x3F);
}
}
