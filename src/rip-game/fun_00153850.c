#include "types.h"

struct SLOTHEAP;

void CreateSlotheapSwAlign(struct SLOTHEAP *, s32, s32, s32);
extern s32 B_002DD2E0;
extern s32 B_002DD2E4;
extern s32 B_002DD2E8;
extern s32 B_002DD2EC;
extern s32 B_002DD2F0;
extern s32 B_002DD2F4;
extern struct SLOTHEAP B_004520A8;
extern struct SLOTHEAP B_004520D0;
extern struct SLOTHEAP B_004520F8;
extern struct SLOTHEAP B_00452120;
extern struct SLOTHEAP B_00452148;
extern struct SLOTHEAP B_00452170;

void func_00153850(s32 fInit, s32 nEvent) {
    if ((nEvent == 0xFFFF) && (fInit != 0)) {
        if (++B_002DD2E0 == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        if (++B_002DD2E4 == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        if (++B_002DD2E8 == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        if (++B_002DD2EC == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        if (++B_002DD2F0 == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        if (++B_002DD2F4 == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
