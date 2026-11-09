#include "types.h"

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
