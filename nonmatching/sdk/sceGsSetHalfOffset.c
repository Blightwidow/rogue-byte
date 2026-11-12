#include "types.h"

typedef struct GsHalfOffsetState {
    char unknown_0x0[0x20];
    s64 field20;
    char unknown_0x28[0x8];
    u64 field30;
} GsHalfOffsetState;

void sceGsSetHalfOffset(GsHalfOffsetState *state, s16 arg1, s16 arg2, s32 arg3)
{
    u64 reg;
    s32 xWord;
    s32 yWord;
    u64 xTerm;
    u64 yTerm;
    s64 offsetX;
    s64 offsetY;
    s64 scaleX;

    reg = state->field30;
    xWord = (s32)((reg >> 48) & 0x7FF);
    yWord = (s32)((reg >> 16) & 0x7FF);
    xTerm = (u64)(xWord + 1) >> 1;
    offsetX = (s64)arg2 - xTerm;
    yTerm = (u64)(yWord + 1) >> 1;
    offsetY = (s64)arg1 - yTerm;
    if (arg3 << 0x10) {
        scaleX = ((offsetX << 4) + 8) << 32;
    } else {
        scaleX = (offsetX << 4) << 32;
    }
    state->field20 = (offsetY << 4) | scaleX;
}
