#include "types.h"

struct AttachObject {
    char pad0[0x38];
    f32 radius;
    char pad3C[0xFC - 0x3C];
    s32 mode;
};

extern "C" {
f32 PostLoLoad();
extern f32 RO_002BE900;

void func_00183F50(AttachObject* attach) {
    PostLoLoad();
    if (attach->mode == 0) {
        attach->mode = 7;
    }
    if (attach->radius == 1e10f) {
        attach->radius = RO_002BE900;
    }
}
}
