extern "C" {
struct PadSlot { int buffer; int pad4[3]; int opened; int pad14[2]; };
struct PadPort { PadSlot slots[4]; };
struct PadReport {
    char pad0[0x50];
    unsigned short modeTable[8];
    char pad60[4];
    unsigned char field64;
    unsigned char field65;
    char pad66[2];
    unsigned char field68;
    unsigned char field69;
    char pad6A[7];
    unsigned char field71;
    unsigned char status;
};
extern PadPort B_004505D0[];
PadReport *func_00243270(int port, int slot);
int scePadInfoMode(int port, int slot, int term, int index) {
    PadReport *report;
    if (B_004505D0[port].slots[slot].opened == 0) {
        return 0;
    }
    report = func_00243270(port, slot);
    if (report->status != 1) {
        return 0;
    }
    if (report->field71 == 2) {
        return 0;
    }
    switch (term) {
    case 1:
        if (report->field65 == 0xF3) {
            return 0;
        }
        return report->field65 >> 4;
    case 2:
        if (report->field64 == 1) {
            return 0;
        }
        return report->modeTable[report->field69];
    case 3:
        if (report->field64 == 1) {
            return 0;
        }
        return report->field69;
    case 4:
        if (report->field64 == 1) {
            return 0;
        }
        if (index == -1) {
            return report->field68;
        }
        if (index >= report->field68) {
            return 0;
        }
        return report->modeTable[index];
    }
    return 0;
}
}
