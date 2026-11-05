typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PoxExtractFromPoxa {};            /* size 0x0 */
s8 *PoxExtractFromPoxa(s8 *arg0, s8 *arg1, s8 *arg2) {
    s32 *var_a0;
    s32 temp_a2;
    s8 *var_v1;
    var_v1 = M2C_FIELD(arg1, s8 **, 0x64);
    temp_a2 = M2C_FIELD(arg2, s32 *, 0x60);
    if (var_v1 != NULL) {
        var_a0 = (s32 *)(var_v1 + 4);
        if (M2C_FIELD(var_v1, s32 *, 0xC) == temp_a2) {
            M2C_FIELD(arg1, s8 **, 0x64) = (s8 *) M2C_FIELD(var_v1, s8 **, 4);
        } else {
            while ((var_v1 = M2C_FIELD(var_v1, s8 **, 4)) != NULL) {
                if (M2C_FIELD(var_v1, s32 *, 0xC) == temp_a2) {
                    *var_a0 = M2C_FIELD(var_v1, s32 *, 4);
                    break;
                }
                var_a0 = (s32 *)(var_v1 + 4);
            }
        }
    }
    return var_v1;
}
}
