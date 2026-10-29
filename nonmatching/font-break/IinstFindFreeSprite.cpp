typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_IinstFindFreeSprite {};           /* size 0x0 */

s32 IinstFindFreeSprite(s8 *arg0) {
    s16 *var_a0;
    s32 var_v1;
    u16 temp_a1;

    temp_a1 = M2C_FIELD(arg0, u16 *, 2);
    var_v1 = 0;
    if (temp_a1 != 0) {
        var_a0 = (s16 *)(M2C_FIELD(arg0, s32 *, 8) + 8);
loop_2:
        if (*var_a0 >= 0) {
            var_v1 += 1;
            var_a0 += 0x18;
            if (var_v1 >= (s32) temp_a1) {
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_2;
        }
        return var_v1;
    }
    return 0;
}

}
