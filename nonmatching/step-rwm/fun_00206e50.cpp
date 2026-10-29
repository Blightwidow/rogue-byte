typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void RemoveGuardIgnoredClass(s32, s32);
extern s32 D_002C3D10;

void func_00206E50(s32 arg0) {
    s32 *var_s1;
    s32 temp_a1;
    u32 var_s0;

    var_s0 = 0;
    var_s1 = &D_002C3D10;
    do {
        temp_a1 = *var_s1;
        var_s0 += 1;
        var_s1 += 4;
        RemoveGuardIgnoredClass(arg0, temp_a1);
    } while (var_s0 < 5U);
}

}
