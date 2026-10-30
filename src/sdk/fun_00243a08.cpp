struct PadSlot_4505D0 { char pad0[0x10]; int opened; char pad14[0x8]; };
struct PadPort_4505D0 { PadSlot_4505D0 slots[4]; };
extern PadPort_4505D0 B_004505D0[];
extern "C" {
char *func_00243270(int port, int slot);
int func_00243A08(int port, int slot) {
    int result;
    if (B_004505D0[port].slots[slot].opened == 0) return 0;
    unsigned char *pad = (unsigned char *)func_00243270(port, slot);
    if (pad[0x72] != 1) { result = 0; goto done; }
    if (pad[0x64] < 2) { result = 0; goto done; }
    if (pad[0x66] < 2) { result = 0; goto done; }
    { result = (int)(pad[0x79] + ((long)pad[0x7A] << 8) + ((long)pad[0x7B] << 16) + ((long)pad[0x7C] << 24)); goto done; }
done:
    return result;
}
}
