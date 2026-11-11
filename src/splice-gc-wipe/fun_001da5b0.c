#include "types.h"

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

s32 func_001DA5B0(struct Menu *menu) {
    s32 value;

    value = menu->field_0x20;
    if (value == -1) {
        value = menu->field_0x18;
    }
    return value;
}
