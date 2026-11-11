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

void InitXfm();
void func_001A6CA8(WARP *, s32);

void InitWarp(WARP *warp) {
    s32 flags;
    InitXfm();
    warp->field_0x150 = 0x189;
    warp->field_0x154 = -1;
    func_001A6CA8(warp, 0);
    flags = warp->field_0x40;
    if ((flags ^ 1) & 1) {
        *(s32 *)flags = (s32) (*(s32 *)flags | 2);
        return;
    }
    warp->field_0x40 = (s32) (flags | 2);
}
}
