#include "types.h"
struct ClipResult {
    char pad0[0x40];
    f32 low;
    f32 high;
    char pad1[0x78];
};
extern "C" {
s32 ClsgClipEdgeToCg(s32, s32, s32, s32, ClipResult *, s32);
s32 FClipEdgeToCg(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ClipResult clip __attribute__((aligned(16)));
    s32 clipped = ClsgClipEdgeToCg(arg0, arg1, arg2, 2, &clip, arg3 | 2);
    s32 result = 0;
    if (clipped == 0 || clip.low != 0.0f || clip.high != 1.0f) {
        result = 1;
    }
    return result;
}
}
