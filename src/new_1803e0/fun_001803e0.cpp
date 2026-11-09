// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"

struct Slot {
    char pad0[0xC];
    s32 target;
    char pad10[0x98 - 0x10];
    float one;
};

struct Holder {
    char pad0[0x1CC];
    s32 flag;
};

extern "C" {
s32 FIsBasicDerivedFrom(s32, s32);
void func_0017F1A0(Holder *, Slot *, s32);
void func_0017F5B0(Holder *, s32);
}

extern "C" void func_001803E0(Holder *holder, Slot *slots, s32 index)
{
    func_0017F1A0(holder, slots, index);
    s32 target = *(s32 *)((char *)slots + ((1 - index) << 6) + 0xC);
    if (FIsBasicDerivedFrom(target, 0x47) == 0 && holder->flag != 0) {
        goto setOne;
    }
    func_0017F5B0(holder, target);
    if (holder->flag == 0) {
        return;
    }
setOne:
    slots->one = 1.0f;
}
