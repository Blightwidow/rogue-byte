typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
extern "C" {
f32 GModPositive__Fff(f32, f32);

f32 RadNormalize__Ff(f32 angle) {
    if ((angle < -3.1415927f) || (angle > 3.1415927f)) {
        angle = GModPositive__Fff(angle + 3.1415927f, 6.2831855f) - 3.1415927f;
    }
    return angle;
}

}
