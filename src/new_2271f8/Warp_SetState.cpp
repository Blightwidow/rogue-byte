#include "types.h"

extern "C" {
struct WARP {
    char pad0[0x40];
    s32 field_0x40;
    char pad44[0x13C - 0x44];
    s32 state;
    f32 field_0x140;
    s32 levelDesc;
    char pad148[0x150 - 0x148];
    s32 field_0x150;
    s32 field_0x154;
};
struct WORLD {
    char pad0[0x3C84];
    WARP *field_0x3C84;
};

s32 SetHandsOff(WORLD *, s32);
s32 func_001A6CA8(WARP *, s32);
extern WORLD B_003DD490;
struct CLOCK {
    f32 t;
    f32 dt;
};
extern CLOCK g_2dded0;

void Warp_SetState(WARP *warp, s32 newState) {
    if (newState != warp->state) {
        if (newState == 4) {
            func_001A6CA8(warp, 1);
            SetHandsOff(&B_003DD490, 3);
            B_003DD490.field_0x3C84 = warp;
        }
        warp->state = newState;
        warp->field_0x140 = g_2dded0.t;
    }
}

}
