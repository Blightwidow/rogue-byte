typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 atan2f(f32, f32);                               /* extern */

void GetJtHangHeading__FP2JTPf(s8 *arg0, f32 *arg1) {
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_s1;
    s8 *temp_v1;
    s8 *temp_v1_2;

    temp_v1 = M2C_FIELD(temp_a1, s8 **, 0xC);
    temp_s1 = M2C_FIELD(temp_v1, s8 *(**)(s8 *, s8 *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1);
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x18C4);
    temp_a1_2 = M2C_FIELD(arg0, s8 **, 0x18C4);
    temp_v1_2 = M2C_FIELD(temp_a1_2, s8 **, 0xC);
    *arg1 = atan2f(M2C_FIELD(temp_s1, f32 *, 4), *M2C_FIELD(temp_v1_2, f32 *(**)(s8 *, s8 *), 0xFC)(temp_a1_2 + M2C_FIELD(temp_v1_2, s16 *, 0xF8), temp_a1_2));
}

}
