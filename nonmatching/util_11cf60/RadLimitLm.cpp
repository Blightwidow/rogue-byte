typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */

void RadLimitLm(s8 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;

    temp_f20 = M2C_FIELD(arg0, f32 *, 4);
    temp_f21 = (temp_f20 + temp_f0) * 0.5f;
    temp_f0 = M2C_FIELD(arg0, f32 *, 0);
    RadNormalize__Ff(temp_f21 + GLimitAbs__Fff(RadNormalize__Ff(fparg0 - temp_f21), (temp_f20 - temp_f0) * 0.5f));
}

}
