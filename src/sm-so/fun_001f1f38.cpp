// SPDX-License-Identifier: GPL-3.0-or-later
struct PartVt1F1F38 {
    char pad0[0xA8];
    short delta;
    short index;
    void (*fn)(void *, int);
};
struct Part1F1F38 {
    char pad0[0xC];
    PartVt1F1F38 *vptr;
};
struct Owner1F1F38 {
    char pad0[0x494];
    Part1F1F38 *part;
};
extern "C" void func_00205D10();
#define SETPART(p, v) ((p)->vptr->fn((char *)(p) + (p)->vptr->delta, (v)))
extern "C" void func_001F1F38(Owner1F1F38 *owner, int flag)
{
    func_00205D10();
    if (flag != 0) {
        if (owner->part != 0)
            SETPART(owner->part, 0);
    } else if (owner->part != 0) {
        SETPART(owner->part, 1);
    }
}
