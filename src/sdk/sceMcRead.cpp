struct McClient_450880 { int pad0[9]; int server; int pad28[7]; };
struct McReadCommand_450900 { int fd; int pad4; int pad8; int size; int pad10; int pad14; void *buffer; void *table; int pad20[4]; };
extern "C" {
int PollSema(int);
int SignalSema(int);
void func_0023B170(void *, int);
void func_00244110(void *);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern McClient_450880 B_00450880;
extern McReadCommand_450900 B_00450900;
extern char B_00450D80[];
extern int B_00451E40[];
extern int D_002C8350;
extern int D_002C8354;
int sceMcRead(int fd, void *buffer, int size) {
    if (B_00450880.server == 0) {
        return -0x64;
    }
    if (PollSema(D_002C8354) < 0) {
        return -0xC8;
    }
    B_00450900.fd = fd;
    B_00450900.buffer = buffer;
    B_00450900.size = size;
    B_00450900.table = B_00450D80;
    func_0023B170(buffer, size);
    func_0023B170(B_00450D80, 0xC0);
    if (sceSifCallRpc(&B_00450880, 5, 1, &B_00450900, 0x30, B_00451E40, 4, (void *)func_00244110, B_00450D80) != 0) {
        SignalSema(D_002C8354);
        return -0x5B;
    }
    D_002C8350 = 5;
    return 0;
}
}
