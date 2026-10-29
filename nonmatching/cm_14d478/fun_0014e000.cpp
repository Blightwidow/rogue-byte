typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_0014E000(s8 **arg0, s8 **arg1) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_v0;
    s8 *temp_a0;
    s8 *temp_a2;

    temp_a2 = *arg0;
    temp_a0 = *arg1;
    var_v0 = M2C_FIELD(temp_a0, s32 *, 0x110) - M2C_FIELD(temp_a2, s32 *, 0x110);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(temp_a0, s32 *, 0xE4) - M2C_FIELD(temp_a2, s32 *, 0xE4);
        if (var_v0 == 0) {
            temp_f1 = M2C_FIELD(temp_a2, f32 *, 0x114);
            temp_f0 = M2C_FIELD(temp_a0, f32 *, 0x114);
            var_v0 = -1;
            if (!(temp_f1 < temp_f0)) {
                if (temp_f0 < temp_f1) {
                    return 1;
                }
                return (s32) ((temp_a2 - temp_a0) * 0x38E38E39) >> 5;
            }
        }
    }
    return var_v0;
}

}
