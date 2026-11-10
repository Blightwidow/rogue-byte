#include "types.h"

struct TransitionTarget {
    char pad0[0x1C];
    s32 flags;
};

struct SwGlobals {
    char pad0[0x3B0C];
    s32 field_0x3B0C;
};

extern "C" {
void RequestTransition(SwGlobals *, void *, s32, s32, s32, s32);
void bevy_jobs_162e38(s32);
extern SwGlobals B_003DD490;
extern char RO_002A3928[];

void func_001B09A8(TransitionTarget *target) {
    RequestTransition(&B_003DD490, RO_002A3928, 0x189, -1, 0x80, -1);
    if (B_003DD490.field_0x3B0C != 0) {
        bevy_jobs_162e38(B_003DD490.field_0x3B0C);
    }
    if (target != 0) {
        target->flags = target->flags | 2;
    }
}

}
