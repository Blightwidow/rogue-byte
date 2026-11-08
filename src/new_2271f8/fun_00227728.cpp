// SPDX-License-Identifier: GPL-3.0-or-later

// A four-byte colour returned by value. func_002275B8 receives its result
// through a hidden pointer in $a0 (it saves $a0 as the destination and reads
// the selector from $a1), so the type is not returned in a register: a
// user-declared constructor gives it that memory return under g++ 2.95.
struct Color4 {
    unsigned char channel[4];
    Color4() {}
};

// Layout read by func_00227788 and func_00227728: a selector at 0x0, the
// colour at 0x4 (copied with lwl/lwr, byte aligned) and a word at 0x8.
struct ColorSlot {
    int kind;
    Color4 color;
    int field8;
};

extern "C" Color4 func_002275B8(int colorKind);
extern "C" void func_00227788(ColorSlot *slot);

// Retail resets the slot through func_00227788 (this still in $a0), then
// stores the selector, calls func_002275B8 with a stack temporary as the
// hidden return pointer and copies the four bytes into the slot with
// lwl/lwr + swl/swr: the struct-return assignment below in source order.
extern "C" void func_00227728(ColorSlot *slot, int kind, int colorKind) {
    func_00227788(slot);
    slot->kind = kind;
    slot->color = func_002275B8(colorKind);
}
