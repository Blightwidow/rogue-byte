struct PadSlot_4505D0 { char pad0[0x10]; int opened; char pad14[0x8]; };
struct PadPort_4505D0 { PadSlot_4505D0 slots[4]; };
extern PadPort_4505D0 B_004505D0[];
extern "C" {
int func_00243AC0(int port, int slot, int mode);
int scePadEnterPressMode(int port, int slot) {
    if (B_004505D0[port].slots[slot].opened == 0) return 0;
    return func_00243AC0(port, slot, 0xFFF);
}
}
