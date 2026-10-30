typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FTaskPrerequisitesDone {};        /* size 0x0 */
s32 FTaskPrerequisitesDone(s8 *arg0) {
    s32 temp_v1;
    s32 var_a3;
    s32 var_t0;
    s8 **var_a2;
    s8 *var_a1;
    var_t0 = 1;
    var_a3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x94) > 0) {
        var_a2 = M2C_FIELD(arg0, s8 ***, 0x98);
        var_a1 = *var_a2;
loop_2:
        temp_v1 = M2C_FIELD(var_a1, s32 *, 0x54);
        var_t0 = 0;
        if ((temp_v1 >= 2) || ((temp_v1 == 1) && (M2C_FIELD(var_a1, s32 *, 0x6C) != 0))) {
            var_t0 = 1;
        }
        var_a2 += 4;
        var_a3 += 1;
        if (var_t0 != 0) {
            if (var_a3 < M2C_FIELD(arg0, s32 *, 0x94)) {
                var_a1 = *var_a2;
                goto loop_2;
            }
        }
    }
    return var_t0;
}
}
