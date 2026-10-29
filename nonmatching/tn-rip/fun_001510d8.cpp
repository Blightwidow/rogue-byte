typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FFloatsNear__Ffff(f32, f32, f32);           /* extern */

s32 func_001510D8(s8 *arg0) {
    f32 temp_f13;
    s32 var_v0;

    temp_f13 = M2C_FIELD(arg0, f32 *, 0x18);
    if ((temp_f13 < 0.0f) || (var_v0 = 0, (FFloatsNear__Ffff(M2C_FIELD(arg0, f32 *, 0xAC), temp_f13, 0x3C23D70A) != 0))) {
        var_v0 = 1;
    }
    return var_v0;
}

}
