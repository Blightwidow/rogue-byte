#include "types.h"

typedef struct WARP {
    char pad0[0x40];
    s32 field_0x40;
    char pad44[0x13C - 0x44];
    s32 state;
    f32 field_0x140;
    s32 levelDesc;
    char pad148[0x150 - 0x148];
    s32 field_0x150;
    s32 field_0x154;
} WARP;

s32 IrowFromLevelDesc(s32);

void func_00228518(WARP *warp) {
    IrowFromLevelDesc(warp->levelDesc);
}
