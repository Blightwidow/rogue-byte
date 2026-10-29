typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *func_001F2798(s8 *arg0) {
    s32 temp_v1;
    s8 *temp_v0;
    s8 *var_a0;
    s8 *var_a1;

    var_a0 = arg0;
    var_a1 = NULL;
loop_1:
    if ((var_a0 != NULL) && ((var_a1 = var_a0, temp_v0 = M2C_FIELD(var_a0, s8 **, 0xE8), (temp_v0 == NULL)) || ((temp_v1 = M2C_FIELD(temp_v0, s32 *, 0xC0), (temp_v1 == 3)) && (M2C_FIELD(temp_v0, s32 *, 0xA0) == temp_v1)))) {
        if (!(M2C_FIELD(var_a1, s64 *, 0x148) & (0x8000 << 0x13))) {
            var_a0 = M2C_FIELD(var_a1, s8 **, 0x10);
            goto loop_1;
        }
    }
    return var_a1;
}

}
