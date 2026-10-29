typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PidFindInIdTableA_1ed4e0 {};      /* size 0x0 */
extern s32 B_003DD010;
s32 *PidFindInIdTableA_1ed4e0(s32 arg0) {
    s32 *temp_v1;
    s32 var_a0;
    if (B_003DD010 == 0) {
        return NULL;
    }
    var_a0 = arg0 % 16381;
loop_3:
    temp_v1 = (s32 *)(*(s32 *)((var_a0 * 4) + B_003DD010));
    if (temp_v1 != NULL) {
        if (*temp_v1 != arg0) {
            var_a0 = (s32) (var_a0 + 1) % 16381;
            goto loop_3;
        }
    }
    return temp_v1;
}
}
