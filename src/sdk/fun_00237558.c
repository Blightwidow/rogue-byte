// SPDX-License-Identifier: GPL-3.0-or-later
struct Slot { int field0; int state; int field8; int fieldC; };
extern int D_002C4A88;
extern struct Slot B_0044BB80[32];
extern void func_002374E0(void);
extern int WaitSema(int);
extern int SignalSema(int);
struct Slot *func_00237558(void) {
    struct Slot *slot;
    func_002374E0();
    WaitSema(D_002C4A88);
    for (slot = B_0044BB80; slot < B_0044BB80 + 32; slot++) {
        if (slot->state == 0) {
            slot->state = 0x10000000;
            SignalSema(D_002C4A88);
            return slot;
        }
    }
    SignalSema(D_002C4A88);
    return 0;
}
