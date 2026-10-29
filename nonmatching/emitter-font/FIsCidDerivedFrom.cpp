typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FIsCidDerivedFrom {};             /* size 0x0 */

extern M2C_UNK D_002BAAE8;

s32 FIsCidDerivedFrom(s32 arg0, s32 arg1) {
    s32 result;
    s8 *var_a0;

    var_a0 = (s8 *)((arg0 * 0x14) + &D_002BAAE8);
    if (var_a0 != NULL) {
loop_1:
        if (M2C_FIELD(var_a0, s32 *, 4) != arg1) {
            var_a0 = M2C_FIELD(var_a0, s8 **, 0);
            if (var_a0 == NULL) {
                /* Duplicate return node #6. Try simplifying control flow for better match */
                { result = 0; goto done; }
            }
            goto loop_1;
        }
        { result = 1; goto done; }
    }
    return 0;
done:
    return result;
}

}
