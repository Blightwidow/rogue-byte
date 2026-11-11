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

struct Menu *Menu_Construct(struct Menu *);
void GadgetMenu_InitPage(struct Menu *);
extern struct MenuVtable D_002D8568;

struct Menu *GadgetMenu_Construct(struct Menu *menu) {
    Menu_Construct(menu);
    menu->vtable = &D_002D8568;
    GadgetMenu_InitPage(menu);
    return menu;
}
