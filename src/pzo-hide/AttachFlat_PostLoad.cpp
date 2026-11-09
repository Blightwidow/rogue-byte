#include "types.h"

struct AttachFlat {
    char pad0[0x38];
    f32 radius;
    char pad3C[0xE0 - 0x3C];
    s32 transformOverride;
};

extern "C" {
void PostLoLoad();
void SetTnTnsOverride(s32, s32);
extern f32 RO_002BE8C8;

void AttachFlat_PostLoad(AttachFlat* attach) {
    PostLoLoad();
    s32 overrideTransform = attach->transformOverride;
    if (overrideTransform != 0) {
        SetTnTnsOverride(overrideTransform, 0);
    }
    if (attach->radius == 1e10f) {
        attach->radius = RO_002BE8C8;
    }
}
}
