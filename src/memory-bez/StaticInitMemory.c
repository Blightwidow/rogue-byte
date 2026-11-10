#include "types.h"

typedef struct Slotheap Slotheap;

typedef struct StaticMemoryGlobals {
    void *field_0x0;
    s32 field_0x4;
} StaticMemoryGlobals;

void CreateSlotheapSwAlign(Slotheap *, s32, s32, s32); /* extern */
extern s32 B_002DD2E0;
extern s32 B_002DD2E4;
extern s32 B_002DD2E8;
extern s32 B_002DD2EC;
extern s32 B_002DD2F0;
extern s32 B_002DD2F4;
extern Slotheap B_004520A8;
extern Slotheap B_004520D0;
extern Slotheap B_004520F8;
extern Slotheap B_00452120;
extern Slotheap B_00452148;
extern Slotheap B_00452170;
extern char D_002CA578;
extern StaticMemoryGlobals g_2dd590;

void StaticInitMemory(s32 arg0, s32 arg1) {
    s32 count0;
    s32 count1;
    s32 count2;
    s32 count3;
    s32 count4;
    s32 count5;

    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        g_2dd590.field_0x0 = &D_002CA578;
        count0 = B_002DD2E0 + 1;
        g_2dd590.field_0x4 = -1;
        B_002DD2E0 = count0;
        if (count0 == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        count1 = B_002DD2E4 + 1;
        B_002DD2E4 = count1;
        if (count1 == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        count2 = B_002DD2E8 + 1;
        B_002DD2E8 = count2;
        if (count2 == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        count3 = B_002DD2EC + 1;
        B_002DD2EC = count3;
        if (count3 == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        count4 = B_002DD2F0 + 1;
        B_002DD2F0 = count4;
        if (count4 == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        count5 = B_002DD2F4 + 1;
        B_002DD2F4 = count5;
        if (count5 == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
