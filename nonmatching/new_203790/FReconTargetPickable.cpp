typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FReconTargetPickable {};          /* size 0x0 */
s32 FReconTargetPickable(s8 *arg0) {
    s32 var_v0;
    s8 *temp_a0;
    s8 *temp_v0;
    if ((int)((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x100);
        if ((temp_v0 == NULL) || !((int)((u64) M2C_FIELD(temp_v0, u64 *, 0x28) >> 0x3C) & 1)) {
            temp_a0 = M2C_FIELD(arg0, s8 **, 0xEC);
            if ((temp_a0 == NULL) || (var_v0 = 0, (M2C_FIELD(temp_a0, s32 *, 0x54) == 1))) {
                var_v0 = 1;
            }
            return var_v0;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
}
