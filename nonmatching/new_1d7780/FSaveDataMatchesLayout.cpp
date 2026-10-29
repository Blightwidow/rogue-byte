typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FSaveDataMatchesLayout(s8 *arg0, s8 *arg1) {
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    u8 *var_a1;
    u8 temp_v0;

    var_a2 = 0;
    var_v1 = M2C_FIELD(arg0, s32 *, 0) * 0xA;
    var_a1 = M2C_FIELD(arg0, u8 **, 4);
    if (var_v1 != 0) {
        do {
            temp_v0 = *var_a1;
            var_v1 -= 1;
            var_a1 += 1;
            var_a2 += temp_v0;
        } while (var_v1 != 0);
    }
    var_a3 = 0;
    if (M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0) * 0xA) + M2C_FIELD(arg0, u8 **, 4)), u16 *, -6) == M2C_FIELD(arg1, s32 *, 0x5400)) {
        var_a3 = var_a2 == M2C_FIELD(arg1, s32 *, 0x5404);
    }
    return var_a3;
}

}
