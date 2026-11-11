#include "types.h"

extern "C" {
struct MenuVtable;

struct Menu {
    s32 field_0x0;
    s32 field_0x4;
    char pad_0x8[4];
    struct MenuVtable *vtable;
    char pad_0x10[8];
    s32 field_0x18;
    char pad_0x1C[4];
    s32 field_0x20;
    struct Menu *field_0x24;
    s32 field_0x28;
    f32 field_0x2C;
    char pad_0x30[4];
    f32 field_0x34;
    char pad_0x38[8];
    s32 field_0x40;
    f32 field_0x44;
    char pad_0x48[4];
    s32 field_0x4C;
    struct GadgetEntry *field_0x50;
};

struct MenuVtable {
    char pad_0x0[0x58];
    s16 field_0x58;
    char pad_0x5A[2];
    void (*field_0x5C)(void *);
    char pad_0x60[0x130];
    s16 field_0x190;
    char pad_0x192[2];
    void (*field_0x194)(void *);
};

void func_001DD888(struct Menu *menu) {
    struct Menu *linked;

    if (menu->field_0x24 != 0) {
        menu->vtable->field_0x5C((char *)menu + menu->vtable->field_0x58);
        linked = menu->field_0x24;
        linked->vtable->field_0x194((char *)linked + linked->vtable->field_0x190);
    }
}

}
