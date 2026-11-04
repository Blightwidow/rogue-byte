typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
struct CurveData {
    char pad0[0x20];
    f32 startValue;
    f32 endValue;
};

struct Crvl {
    char pad0[0x14];
    CurveData *curve;
};

extern "C" {
f32 GetSuck();
s32 SFromCrvlU__FP4CRVLf(Crvl *crvl, s32 length) {
    f32 blend = GetSuck();
    CurveData *curve = crvl->curve;
    return (s32) ((((1.0f - blend) * curve->startValue) + (blend * curve->endValue)) * (f32) length);
}
}
