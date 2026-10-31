typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 GModPositive__Fff(void);                         /* extern */

f32 SWrapCrv(s8 *arg0, f32 fparg0) {
    f32 temp_f13;
    f32 var_f0;

    var_f0 = fparg0;
    if ((M2C_FIELD(arg0, s32 *, 0xE4) != 0) && ((temp_f13 = M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + M2C_FIELD(arg0, s32 *, 0xF0)), f32 *, -4), !(fparg0 >= 0.0f)) || (var_f0 = fparg0, !(fparg0 <= temp_f13)))) {
        var_f0 = GModPositive__Fff();
    }
    return var_f0;
}

}
