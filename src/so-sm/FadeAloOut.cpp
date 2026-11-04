typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;

extern "C" {
void SetAloAlpha(s32, f32);
void SetAloFadeRate(s32, f32);

void FadeAloOut(s32 alo, f32 duration) {
    if (duration <= 0.0f) {
        SetAloFadeRate(alo, 0.0f);
        SetAloAlpha(alo, 0.0f);
        return;
    }
    SetAloFadeRate(alo, -1.0f / duration);
}
}
