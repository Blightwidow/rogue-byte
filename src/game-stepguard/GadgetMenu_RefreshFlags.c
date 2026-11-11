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

struct GadgetEntry {
    s32 field_0x0;
    char pad_0x4[0x18];
    s32 field_0x1C;
};

s32 FGadgetAcquired(s32);
s32 FGadgetOnSale(s32);

void GadgetMenu_RefreshFlags(struct Menu *menu) {
    s32 index;
    struct GadgetEntry *entry;

    index = 0;
    if (menu->field_0x4C > 0) {
        do {
            entry = &menu->field_0x50[index];
            index += 1;
            entry->field_0x1C = (entry->field_0x1C & ~2) | ((FGadgetOnSale(entry->field_0x0) & 1) * 2);
            entry->field_0x1C = (entry->field_0x1C & ~4) | ((FGadgetAcquired(entry->field_0x0) & 1) * 4);
        } while (index < menu->field_0x4C);
    }
}
