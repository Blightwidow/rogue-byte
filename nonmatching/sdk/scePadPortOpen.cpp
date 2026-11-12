extern "C" {
struct PadSlot { unsigned char *buffer; unsigned char *report; int field8; int fieldC; int state; int field14; int field18; };
struct PadPort { PadSlot slots[4]; };
struct PadRequest { int command; int port; int slot; int result; int buffer; int field14; };
struct PadReportBuffer { char pad0[0x58]; int field58; int field5C; int field60; char pad64[3]; char field67; char pad68[8]; char field70; char field71; char pad72[0xE]; };
int func_00236960(const char *format, ...);
void *memset(void *destination, int value, unsigned int count);
int sceSifCallRpc(void *client, int command, int mode, void *send, int sendSize, void *receive, int receiveSize, int callback, int callbackData);
extern int D_002C830C;
extern char B_00450580[];
extern PadPort B_004505D0[];
extern unsigned char B_004506C0[][4][32];
extern PadRequest B_004507C0;
int scePadPortOpen(int port, int slot, PadReportBuffer *buffer) {
    int index;
    PadReportBuffer *report;
    PadRequest *request;
    if (((unsigned int)buffer & 0x3F) != 0) {
        if (D_002C830C != 0) {
            func_00236960("libpad: buffer addr is not 64 byte align. %08x\n", buffer);
            return 0;
        }
        return 0;
    }
    if (B_004505D0[port].slots[slot].state == 1) {
        if (D_002C830C != 0) {
            func_00236960("libpad: pad port is already open [%d][%d]\n", port, slot);
            return 0;
        }
        return 0;
    }
    report = buffer;
    for (index = 1; index >= 0; index--) {
        report->field58 = 0;
        report->field70 = 5;
        report->field71 = 2;
        report->field67 = 0;
        memset(report, 0xFF, 0x20);
        report->field60 = 0;
        report++;
    }
    request = &B_004507C0;
    request->command = 1;
    request->port = port;
    request->slot = slot;
    request->buffer = (int)buffer;
    if (sceSifCallRpc(B_00450580, 1, 0, request, 0x80, request, 0x80, 0, 0) < 0) {
        return 0;
    }
    B_004505D0[port].slots[slot].state = 1;
    B_004505D0[port].slots[slot].fieldC = 0;
    B_004505D0[port].slots[slot].field8 = request->field14;
    *(int *)B_004506C0[port][slot] = 0;
    B_004505D0[port].slots[slot].buffer = (unsigned char *)buffer;
    B_004505D0[port].slots[slot].report = B_004506C0[port][slot];
    return request->result;
}
}
