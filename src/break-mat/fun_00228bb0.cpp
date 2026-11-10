#include "types.h"
extern "C" {
struct BrkTarget {
    char pad0[0xD4];
    f32 field_0xD4;
    f32 field_0xD8;
};

struct BrkOwner {
    char pad0[0xE8];
    BrkTarget *field_0xE8;
};

void func_001F3590();
void func_001F68A8(BrkOwner *, s32);

void func_00228BB0(BrkOwner *owner) {
    BrkTarget *target;

    func_001F3590();
    func_001F68A8(owner, 1);
    target = owner->field_0xE8;
    target->field_0xD8 = 1.0f;
    target->field_0xD4 = 1.0f;
}

}
