typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 GrfsgsFromSgs(s32);                             /* extern */

s32 AsgsFromGrfsgs(s32 arg0, s32 *arg1) {
    s32 *var_s1;
    s32 var_s0;
    s32 var_s2;

    var_s0 = 0x2E;
    var_s1 = arg1;
    var_s2 = 0;
    do {
        if (arg0 & GrfsgsFromSgs(var_s0)) {
            *var_s1 = var_s0;
            var_s2 += 1;
            var_s1 += 1;
        }
        var_s0 -= 1;
    } while (var_s0 >= 0);
    return var_s2;
}

}
