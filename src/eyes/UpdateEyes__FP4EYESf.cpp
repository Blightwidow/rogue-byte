typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;

extern "C" {
struct Eyes {
    char pad0[0x1C];
    s32 frameCount;
    char pad20[0x14];
    s32 slotList;
    char pad38[0x2C];
    s32 state;
    f32 blinkStart;
    f32 blinkDelay;
    f32 speed;
    f32 frame;
    f32 openFraction;
};

s32 FIsSlEmpty(s32);
void SetEyesEyess__FP4EYES5EYESS(Eyes*, s32);
void SetSaiIframe(Eyes*, s32);
extern f32 g_2dded0;
extern f32 g_2dded4;

void UpdateEyes__FP4EYESf(Eyes* eyes) {
    if (FIsSlEmpty((int)&eyes->slotList) == 0) {
        s32 frameCount = eyes->frameCount;
        if (frameCount >= 2) {
            s32 state = eyes->state;
            switch (state) {
            case 0:
                if (eyes->blinkDelay <= (g_2dded0 - eyes->blinkStart)) {
                    state = 1;
                }
                break;
            case 1: {
                f32 step = eyes->speed * g_2dded4;
                f32 advanced = eyes->frame + step;
                eyes->frame = advanced;
                if ((f32)frameCount <= advanced) {
                    f32 restored = advanced - step;
                    eyes->frame = restored;
                    state = (((s32)restored ^ (frameCount - 1)) == 0) ? 2 : 3;
                }
                break;
            }
            case 2:
                if (eyes->openFraction < 1.0f) {
                    state = 3;
                }
                break;
            case 3: {
                f32 retreated = eyes->frame - (eyes->speed * g_2dded4);
                eyes->frame = retreated;
                if (retreated <= ((f32)frameCount * eyes->openFraction)) {
                    state = 0;
                }
                break;
            }
            }
            SetEyesEyess__FP4EYES5EYESS(eyes, state);
            SetSaiIframe(eyes, (s32)eyes->frame);
        }
    }
}
}
