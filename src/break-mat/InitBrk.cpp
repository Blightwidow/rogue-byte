#include "types.h"
extern "C" {
struct BrkObject {
    char pad0[0x40];
    s32 *field_0x40;
    char pad44[0x180 - 0x44];
    s32 field_0x180;
    s32 field_0x184;
    s32 field_0x188;
};

s32 InitSo();
void InitBrk(BrkObject *brk) {
    s32 *temp_a2;
    InitSo();
    temp_a2 = brk->field_0x40;
    brk->field_0x180 = 1;
    brk->field_0x184 = -0xA;
    brk->field_0x188 = 0x2000;
    if (((s32)temp_a2 ^ 1) & 1) {
        *temp_a2 = *temp_a2 | 2;
        return;
    }
    brk->field_0x40 = (s32 *)((s32)temp_a2 | 2);
}
}
