#include "types.h"

void CreateSlotheapSwAlign(s32 *, s32, s32, s32);
extern s32 B_002DD2E0;
extern s32 B_002DD2E4;
extern s32 B_002DD2E8;
extern s32 B_002DD2EC;
extern s32 B_002DD2F0;
extern s32 B_002DD2F4;
extern s32 B_004520A8;
extern s32 B_004520D0;
extern s32 B_004520F8;
extern s32 B_00452120;
extern s32 B_00452148;
extern s32 B_00452170;

void func_001CB7B0(s32 arg0, s32 arg1) {
    s32 count;

    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        count = B_002DD2E0 + 1;
        B_002DD2E0 = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        count = B_002DD2E4 + 1;
        B_002DD2E4 = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        count = B_002DD2E8 + 1;
        B_002DD2E8 = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        count = B_002DD2EC + 1;
        B_002DD2EC = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        count = B_002DD2F0 + 1;
        B_002DD2F0 = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        count = B_002DD2F4 + 1;
        B_002DD2F4 = count;
        if (count == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
