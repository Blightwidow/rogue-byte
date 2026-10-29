typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_IglyphFromFontCh {};              /* size 0x0 */
s32 IglyphFromFontCh(s8 *arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_v0;
    s32 var_a3;
    s32 var_t0;
    s32 var_v1;
    var_a3 = M2C_FIELD(arg0, s32 *, 0x20) - 1;
    var_t0 = 0;
    if (var_a3 >= 0) {
        var_v1 = var_a3;
loop_2:
        temp_a2 = var_v1 / 2;
        temp_v0 = (arg1 & 0xFF) - *(s32 *)((temp_a2 * 4) + M2C_FIELD(arg0, s32 *, 0x24));
        if (temp_v0 == 0) {
            return temp_a2 + 1;
        }
        if (temp_v0 <= 0) {
            var_a3 = temp_a2 - 1;
        } else {
            var_t0 = temp_a2 + 1;
        }
        var_v1 = var_a3 + var_t0;
        if (var_a3 < var_t0) {
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_2;
    }
    return 0;
}
}
