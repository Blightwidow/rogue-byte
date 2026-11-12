struct Slot { int field0; int state; int field8; int fieldC; };
extern "C" {
extern int D_002C4A88;
extern struct Slot B_0044BB80[32];
void func_002374E0(void);
int WaitSema(int);
int SignalSema(int);
struct Slot *func_002376D0(unsigned int index) {
    struct Slot *slot;
    func_002374E0();
    WaitSema(D_002C4A88);
    if (index >= 0x20) {
        SignalSema(D_002C4A88);
        return 0;
    }
    slot = &B_0044BB80[index];
    SignalSema(D_002C4A88);
    return slot;
}
}
