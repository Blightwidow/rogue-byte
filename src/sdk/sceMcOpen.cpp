extern "C" {
struct McClient_450880 { int pad0[9]; int server; int pad28[7]; };
struct McCommand_450930 { int port; int slot; int flags; int pad0C; int pad10; char name[0x400]; };
int PollSema(int);
int SignalSema(int);
char *func_00233638(char *, const char *, int);
void func_00243ED8(void *);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern McClient_450880 B_00450880;
extern McCommand_450930 B_00450930;
extern int B_00451E40[];
extern int D_002C8350;
extern int D_002C8354;
int sceMcOpen(int port, int slot, const char *name, int flags) {
    if (B_00450880.server == 0) {
        return -0x64;
    }
    if (PollSema(D_002C8354) < 0) {
        return -0xC8;
    }
    if (name == 0 || *name == 0) {
        SignalSema(D_002C8354);
        return -0xD2;
    }
    func_00233638(B_00450930.name, name, 0x3FF);
    B_00450930.port = port;
    B_00450930.flags = flags;
    B_00450930.slot = slot;
    B_00450930.name[0x3FF] = 0;
    if (sceSifCallRpc(&B_00450880, 2, 1, &B_00450930, 0x414, B_00451E40, 4, (void *)func_00243ED8, 0) != 0) {
        SignalSema(D_002C8354);
        return -0x5B;
    }
    D_002C8350 = 2;
    return 0;
}
}
