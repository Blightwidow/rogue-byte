extern "C" {
struct PadSlot { int buffer; int pad4[3]; int opened; int pad14[2]; };
struct PadPort { PadSlot slots[4]; };
struct PadActuatorEntry { unsigned char values[4]; };
struct PadReport {
    char pad0[0x30];
    PadActuatorEntry actuators[13];
    unsigned char modeId;
    char pad65[0x5];
    unsigned char actuatorCount;
    char pad6B[7];
    unsigned char status;
};
extern PadPort B_004505D0[];
PadReport *func_00243270(int port, int slot);
int scePadInfoAct(int port, int slot, int actuator, int term) {
    PadReport *report;
    if (B_004505D0[port].slots[slot].opened == 0) {
        return 0;
    }
    report = func_00243270(port, slot);
    if (report->status != 1) {
        return 0;
    }
    if (report->modeId < 2) {
        return 0;
    }
    if (actuator >= report->actuatorCount) {
        return 0;
    }
    if (actuator == -1) {
        return report->actuatorCount;
    }
    switch (term) {
    case 1:
        return report->actuators[actuator].values[0];
    case 2:
        return report->actuators[actuator].values[1];
    case 3:
        return report->actuators[actuator].values[2];
    case 4:
        return report->actuators[actuator].values[3];
    }
    return 0;
}
}
