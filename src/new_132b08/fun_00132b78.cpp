#include "types.h"
extern "C" {
struct SidebagOwner {
    char pad0[4];
    s32 field_0x4;
};

s32 PsidebagNew();
s32 SidebagPtr_Assign(s32 *, s32);
s32 func_00258178(s32);

void func_00132B78(SidebagOwner *owner) {
    s32 *sidebagSlot;

    sidebagSlot = &owner->field_0x4;
    if (owner->field_0x4 == 0) {
        SidebagPtr_Assign(sidebagSlot, PsidebagNew());
        func_00258178(owner->field_0x4);
    }
}

}
