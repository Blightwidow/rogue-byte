typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001D3FA8 {};                 /* size 0x0 */

s8 *func_001D3FA8(s8 *arg0, s32 arg1) {
    s8 * result;
    s32 temp_v0;
    s32 var_a2;
    s8 **var_a0;
    s8 *temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x4F8);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_a0 = (s8 **)(arg0 + 0x4FC);
loop_2:
        temp_v1 = *var_a0;
        var_a2 += 1;
        if (M2C_FIELD(temp_v1, s32 *, 0x14) == arg1) {
            { result = temp_v1; goto done; }
        }
        var_a0 += 4;
        if (var_a2 >= temp_v0) {
            /* Duplicate return node #5. Try simplifying control flow for better match */
            { result = NULL; goto done; }
        }
        goto loop_2;
    }
    return NULL;
done:
    return result;
}

}
